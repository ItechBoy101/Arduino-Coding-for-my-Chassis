# Mechanical Design Fundamental Studio 1
# Arduino-Coding
# Arduino Mega 2560 as our MicroController

1. Chassis used L298N driver motors, 4 DC motors and Omni Wheels.
2. Collection System uses 2xDRV8825 with expansion boards, 2 NEMA (17 or 23) Stepper Motors(each motor needs a 1.6A as minimum current to be used)
2.1. Stepper motor driver needs two power sources (1x5V supply & minimum of 12V for the motor)
3. Lifitng Ramp System uses 2xServo Motors that produces high torque(metal gears servo motors)
3.1. High Torque Servos
✅ Standard Operating Voltage
4.8V – 6.0V
This is the classic range for the majority of hobby-grade high-torque servos.
✅ High-Voltage (HV) Servo Rating
Some newer high-torque servos are “HV servos,” which are designed to run at:
6.0V – 7.4V (2S LiPo)
Many HV servos are safe up to 8.4V (fully charged 2S LiPo).

⚠ Important Power Notes
Servos need high current
High-torque metal-gear servos can draw:

0.5A to 1A under normal load

2A – 3A peak each under stall load

So you must:
Use a separate BEC or servo power supply
NEVER power servos directly from the Arduino 5V pin
