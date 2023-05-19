# StopWatch-Using-PIC

# Stopwatch Project

This repository contains the source code and documentation for a Stopwatch project implemented using a PIC18F452 Microcontroller and a seven-segment display. The project utilizes hardware interrupts and interrupt service routines (ISRs) to enable pause, start, and reset functionality.

## Features
- Start the stopwatch by pressing a button
- Pause the stopwatch by pressing another button
- Reset the stopwatch to zero by pressing a different button
- Display the time on a seven-segment display

- Hardware interrupts: The project leverages hardware interrupts (INT0, INT1, INT2) to trigger specific actions for pause, start, and reset operations, ensuring accurate timekeeping and user control.

- Interrupt Service Routines (ISRs): Each interrupt is associated with a dedicated ISR, which handles the corresponding button press and executes the required functionality seamlessly.

-Hardware timers: The stopwatch utilizes the hardware timer feature of the PIC18F452 microcontroller to achieve accurate timekeeping. Timer0 is specifically used for providing precise delays in the order of seconds. By configuring the timer and its associated prescaler, the project achieves accurate timing intervals for the stopwatch functionality.

- Seven-segment display: A seven-segment display is integrated to visually represent time from 0 to 9 seconds. The display logic is interrupt-driven, ensuring proper cycling and repetition of time representation.


By default INT0 is high priority hardware interrupt for PIC18F452 and all other hardware interrupts (INT1 and INT2) are low priority on default.
here INT0 is used for RESET button and INT1 and INT2 are used for PAUSE and RESUME respectively. Hence in case of three interrupts occurring simultaneously the PIC will always reset the stopwatch.

##TODO
--Planning to use and LCD display instead of Seven Segment display.



Note:- The circuit diagram given here doesn't contain the ground for PIC,In actual design ground the VSS and give necessary power.
