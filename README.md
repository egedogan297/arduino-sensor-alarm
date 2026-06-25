# Arduino Sensor Alarm System

## What is this?

This project is a proximity alarm system that uses an ultrasonic sensor to measure distance and warns the user through LEDs and a buzzer — just like a parking sensor on a car.

As an object gets closer to the sensor, the system escalates its warning:
- Far away → green LEDs, no sound
- Getting closer → yellow LEDs, buzzer starts
- Too close → red LEDs, buzzer gets louder

The buzzer frequency also increases with danger level, giving both visual and audio feedback at the same time.

## Why I built this

This is my first embedded systems project. I built it to learn how sensors, digital outputs, and control logic work together on real hardware — not just in simulation. The goal was to understand how a simple rule-based system can respond to the physical world in real time.

## Hardware

- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- 2x Red LED
- 2x Yellow LED
- 2x Green LED
- 1x Buzzer
- 6x 220Ω Resistor
- Breadboard + Jumper Wires

## Pin Configuration

- HC-SR04 Trig → Pin 10
- HC-SR04 Echo → Pin 11
- Red LED 1 (top) → Pin 2
- Red LED 2 (bottom) → Pin 3
- Yellow LED 1 (top) → Pin 4
- Yellow LED 2 (bottom) → Pin 5
- Green LED 1 (top) → Pin 6
- Green LED 2 (bottom) → Pin 7
- Buzzer → Pin 8

## How It Works

The system has 6 distance zones. As the object gets closer, more LEDs activate and the buzzer frequency increases.

- Above 60 cm — single green LED, no sound
- 50 – 60 cm — both green LEDs on, no sound
- 40 – 50 cm — single yellow LED, no sound
- 30 – 40 cm — both yellow LEDs on, buzzer at 1000 Hz
- 15 – 30 cm — single red LED, buzzer at 2000 Hz
- Below 15 cm — both red LEDs on, buzzer at 3000 Hz

## Photos

### Circuit Setup
[Circuit](images/circuit.jpeg)

### Distance Zones in Action
[Green - Safe](images/green.jpeg)
[Yellow - Caution](images/yellow.jpeg)
[Red - Danger](images/red.jpeg)
[Double Red - Critical](images/double%20red.jpeg)

## What I learned

- How HC-SR04 ultrasonic sensor works (trigger pulse, echo measurement)
- Converting pulse duration to distance using the speed of sound
- Controlling multiple digital outputs simultaneously
- Building a rule-based control system on embedded hardware

## Author

Ege Doğan — Electrical & Electronics Engineering Student
Istanbul Ticaret University

- Date: June 2026
- Status: Completed


