# Embedded-Systems-FInal-Project---Pomodoro-Timer
Creating a functional Pomodoro timer in Arduino using a 4-Digit 7 Segment LED Display and 4x4 Keypad and Arduino DUE Microcontroller.

[![ Pomoduino - Physical Pomodoro Timer](https://fayazrafin.notion.site/image/https%3A%2F%2Fprod-files-secure.s3.us-west-2.amazonaws.com%2F970a1427-7d44-47a1-b007-1b20fc6f7b9b%2F7fae9491-a45b-4888-8224-68a6189c2205%2FAD_4nXfJFvjK6QsOGXJ1_kkpJQ8U2qNWXdPhRYA293hYuVvE9oTwIgyu4AVQ0mah5bWCA5A2bYo6cWGMxe_60TZ6B8GUCYcPoIYNGeG68uMEIo_2fwyiVdzg8BZR.jpg?table=block&id=ca240d1d-bb49-4e99-aed4-0d86d61f5ae6&spaceId=970a1427-7d44-47a1-b007-1b20fc6f7b9b&width=2000&userId=&cache=v2)


This project is a customizable Pomodoro Timer built for embedded systems, allowing users to input study and break times, view the countdown on a seven-segment display, and control the timer with a keypad. It includes pause and reset functionalities and is developed using C for embedded systems.

## Features

- **Customizable Time Intervals**: Set desired study and break times via a keypad.
- **Seven-Segment Display**: Displays countdown time in minutes and seconds.
- **Pause and Reset Functions**: Pause to temporarily halt the timer or reset to start over manually.
- **Intuitive Interface**: Easy to use and set up on compatible hardware.

## Requirements

- **Hardware**:
  - Microcontroller (e.g., an Arduino or similar development board)
  - 4x4 Matrix Keypad
  - Seven-segment display
  - Optional: Buzzer for audible alert at the end of each interval

- **Software**:
  - C Compiler (such as GCC)
  - Arduino IDE or equivalent for microcontroller programming
  
## Setup and Wiring

1. **Connect the Seven-Segment Display** to the appropriate GPIO pins on your microcontroller.
2. **Connect the Keypad** to designated input pins, ensuring proper mapping to match the code's setup.
3. **Optional**: Connect a buzzer to an output pin for interval alerts.
4. Ensure all connections are secure and correct, as per the specific microcontroller's pinout.

## Installation and Compilation

1. **Clone the repository**:

   ```bash
   git clone https://github.com/fayaz-rafin/Embedded-Systems-FInal-Project---Pomodoro-Timer.git
   cd Embedded-Systems-FInal-Project---Pomodoro-Timer
   
2. Open the project in your preferred IDE (e.g., Arduino IDE, PlatformIO, etc.)
3. Verify and compile the code to check for errors or necessary adjustments based on your specific hardware.
4. Upload the code to your microcontroller.

## Usage

- Set Time: Use the keypad to input desired study and break intervals.
- Start Timer: Begin the Pomodoro session by pressing the designated start button.
- Pause/Resume: Press the pause button to halt the countdown; press again to resume.
- Reset: Press the reset button to stop the session and clear the timer.

## Demo

For a demonstration, refer to the videos or images in the repository.

## Troubleshooting

- Display Issues: Ensure the seven-segment display wiring is correct and matches the code.
- Keypad Malfunction: Confirm the keypad matrix connections are secure and mapped correctly.
- Buzzer: Check the buzzer’s wiring and the microcontroller pin’s output settings if no sound is heard at the end of intervals.


