# 2023FA-ENGR-2304-81001-GREEN-JOSHUA

# Pressure Control and Countdown Simulation

## Overview
This program is designed for an Arduino-based project and simulates a pressure control system with a visual countdown. It's part of the 2023FA-ENGR-2304-81001-GREEN-JOSHUA-P09 project.

## Features
- **Pressure Simulation**: Two potentiometers are used to set and simulate the target and current pressure levels.
- **LED Visualization**: A series of LEDs show the current pressure level, providing a visual representation of the system's status.
- **Countdown Mechanism**: Once the simulated pressure reaches the target, a countdown is initiated, displayed on an I2C LCD screen.
- **Launch Indication**: At the end of the countdown, an LED lights up to indicate the "launch" event.

## Hardware Components
- **I2C LCD (16x2)**: Displays the current pressure, target pressure, and the countdown timer.
- **Potentiometers**: Connected to `A0` and `A1`, these are used to adjust the target and current pressure levels.
- **LEDs**: Connected to digital pins `7`, `8`, `12`, and `13`, these LEDs visually represent the pressure level.
- **Launch Indicator LED**: Connected to digital pin `4`, this LED indicates the completion of the countdown.

## Functionality
- The current and target pressures are read from the potentiometers, mapped to a scale of 0-100%, and displayed on the LCD.
- LEDs corresponding to the current pressure level turn on sequentially as the pressure increases.
- When the current pressure reaches or exceeds the target pressure, a countdown from 5 seconds begins.
- After the countdown, the launch indicator LED lights up for 3 seconds to simulate a launch event.

## Usage
1. Adjust the `targetPotPin` potentiometer to set the desired target pressure.
2. Adjust the `pressurePotPin` potentiometer to simulate the change in pressure.
3. Observe the LED indicators and the LCD display for pressure and countdown information.
4. The final LED lights up to indicate the "launch" after the countdown.

## Customization
- The `countdownDuration` can be adjusted to change the length of the countdown.
- The `ledPins` array can be modified to use different pins for pressure level LEDs.
