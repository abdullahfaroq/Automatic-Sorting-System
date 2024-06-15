# Automatic-Sorting-System
Automatic Sorting System: Repository for an Embedded Systems project featuring password-protected stepper motor activation via keypad, and object sorting using servo motors and IR sensors based on height. Includes code and documentation for Tiva microcontrollers.
Expected Outcome:
Develop a conveyor belt system that can sort objects based on their height.

Program Logic:
The project is divided into two main parts, each handled by separate Tiva microcontrollers:

Stepper Motor Activation (via Keypad-protected Password):

The conveyor belt is activated through a password-protected keypad.
Upon correct password entry, the stepper motors will start, moving the conveyor belt.
Object Sorting (using Servo Motors and IR Sensors):

Objects are sorted based on their height using servo motors and IR sensors.
Three categories are maintained to count the sorted objects.
Program Flow:
Part 1: Stepper Motor Activation

Include Libraries: Import built-in libraries for LCD and Keypad.
Setup Pins: Configure the pins for the Stepper motor, keypad, and LCD.
Password Check Loop:
Continuously check if the correct password is entered.
If correct, turn an indicator LED ON and activate the stepper motors to rotate the conveyor belt.
Monitor keypad input to potentially interrupt and stop the stepper motors.
Part 2: Object Sorting

Include Libraries: Import necessary libraries for hardware control.
Setup Pins and Counters: Initialize pins for hardware components and set up three counters for different object categories.
Servo and Sensor Integration:
Integrate two servo motors with two initial IR sensors to sort objects.
Utilize a third IR sensor to handle discarded objects.
Counter Reset Mechanism:
Monitor the state of a push button to reset the counters when needed.
Hardware Connections:
Follow the detailed hardware connections as indicated in the project report.
Reference Links for Code:
LCD Interfacing with Tiva Launchpad
Password-protected Stepper Motor
Servo Motor Interfacing with Tiva Launchpad
This brief provides a structured outline of the project's objectives, program logic, and the implementation steps required to achieve the desired outcomes. The reference links will guide you through specific code implementations for different parts of the project.
