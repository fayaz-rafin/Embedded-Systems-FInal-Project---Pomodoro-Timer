// EECS2032Z Final Project
// Name: Abror Fayaz Imam Rafin
// Student No: 218042598

#include <SevSeg.h>
#include <Keypad.h>

#define ROWS 4
#define COLS 4

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; // Connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
SevSeg sevseg; // Instantiate a seven segment controller object

bool timerRunning = false;
unsigned long startTime = 0;
unsigned long currentTime = 0;
unsigned long duration = 0; // duration in seconds
bool settingCustomTime = false; // To check if we're setting a custom time
int customTime = 0; // To store the custom time value during setup

int redLedPin = 11; // Red LED connected to pin 10
int greenLedPin = 13; // Green LED connected to pin 11

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {38, 36, 34, 32}; // Digits: 1,2,3,4
  byte segmentPins[] = {40, 44, 28, 24, 22, 42, 30, 26}; // Segments: A,B,C,D,E,F,G,Period

  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(100); // Max is 100

  pinMode(redLedPin, OUTPUT); // Set the red LED pin as an output
  pinMode(greenLedPin, OUTPUT); // Set the green LED pin as an output
  digitalWrite(redLedPin, LOW); // Ensure the red LED is off
  digitalWrite(greenLedPin, LOW); // Ensure the green LED is off
}

void loop() {
  char key = keypad.getKey();

  if (settingCustomTime) {
    handleCustomTimeInput(key);
  } else {
    switch (key) {
      case 'A': // Start Pomodoro (25 minutes)
        startTimer(25 * 60);
        digitalWrite(redLedPin, HIGH); // Turn on red LED
        digitalWrite(greenLedPin, LOW); // Ensure green LED is off
        break;
      case 'B': // Start break (5 minutes)
        startTimer(5 * 60);
        digitalWrite(redLedPin, LOW); // Ensure red LED is off
        digitalWrite(greenLedPin, HIGH); // Turn on green LED
        break;
      case 'C': // Enter custom time mode
        settingCustomTime = true;
        customTime = 0; // Reset custom time at the start
        break;
      case '*': // Stop timer
        stopTimer();
        break;
    }
  }

  manageTimer();
  sevseg.refreshDisplay(); // Must run repeatedly
}

void startTimer(unsigned long secs) {
  duration = secs;
  startTime = millis();
  timerRunning = true;
}

void stopTimer() {
  timerRunning = false;
  digitalWrite(redLedPin, LOW); // Ensure red LED is off
  digitalWrite(greenLedPin, LOW); // Ensure green LED is off
}

void manageTimer() {
  if (timerRunning) {
    currentTime = millis();
    long remainingTime = duration - (currentTime - startTime) / 1000;
    if (remainingTime <= 0) {
      remainingTime = 0;
      stopTimer();
    }
    displayTime(remainingTime);
  } else {
    displayTime(duration);
  }
}

void handleCustomTimeInput(char key) {
  if (key >= '0' && key <= '9') { // Number key pressed
    customTime = customTime * 10 + (key - '0'); // Accumulate the input minutes
    displayTime(customTime * 60); // Display the input as seconds for consistency
  } else if (key == '#') { // Confirm custom time
    startTimer(customTime * 60); // Start the timer with custom duration
    settingCustomTime = false; // Exit custom time setting mode
    customTime = 0; // Reset custom time
  } else if (key == '*') { // Cancel or reset input
    customTime = 0;
    displayTime(customTime);
  }
}

void displayTime(long seconds) {
  int minutes = seconds / 60;
  int secs = seconds % 60;

  char buf[5];
  sprintf(buf, "%02d%02d", minutes, secs);
  sevseg.setChars(buf);
}
