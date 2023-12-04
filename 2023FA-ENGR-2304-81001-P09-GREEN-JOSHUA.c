//modification
#include <Wire.h>

#include <LiquidCrystal_I2C.h>

// 2023FA-ENGR-2304-81001-GREEN-JOSHUA-P09
// Set the LCD I2C address to 0x20 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x20, 16, 2);

// Define the pins for the potentiometers and LED
const int pressurePotPin = A0;
const int targetPotPin = A1;
const int ledPins[] = {7, 8, 12, 13}; // LED pins for showing pressure levels
const int finalLEDPin = 4; // Pin for the final LED to indicate "launch"

int targetPressure = 0; // Target pressure value
int countdownDuration = 5; // Countdown duration in seconds
bool countdownMode = false; // Flag to indicate if countdown is active

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing LCD...");

  lcd.init(); // Initialize the LCD
  lcd.backlight();
  Serial.println("LCD Initialized.");

  // Initialize all LED pins as outputs
  for (int pin : ledPins) {
    pinMode(pin, OUTPUT);
  }
  pinMode(finalLEDPin, OUTPUT);
}

void loop() {
  // Read and map the pressure value from the potentiometer
  int pressure = analogRead(pressurePotPin);
  pressure = map(pressure, 0, 1023, 0, 100);

  // Read and map the target pressure value from the potentiometer
  targetPressure = analogRead(targetPotPin);
  targetPressure = map(targetPressure, 0, 1023, 0, 100);

  // Display the current and target pressures on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pressure: ");
  lcd.print(pressure);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Target: ");
  lcd.print(targetPressure);
  lcd.print("%");

  // Update the LED indicators for the current pressure
  updatePressureLEDs(pressure);

  // Check if target pressure has been reached and start the countdown
  if (pressure >= targetPressure && !countdownMode) {
    countdownMode = true;
    initiateCountdown();
  }

  delay(100); // Short delay to prevent bouncing
}

void updatePressureLEDs(int pressure) {
  // Determine how many LEDs should be on based on the pressure value
  int ledsOn = map(pressure, 0, 100, 0, 5); // Map pressure to 0-4 for LEDs

  // Turn on LEDs up to the number specified by ledsOn
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], (i < ledsOn) ? HIGH : LOW);
  }
}

void initiateCountdown() {
  // Countdown from the set duration to 0
  for (int i = countdownDuration; i >= 0; i--) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Countdown: ");
    lcd.print(i);
    lcd.print("s");
    delay(1000); // Wait for a second between countdown steps
  }

  // Indicate "launch" by turning on the final LED
  digitalWrite(finalLEDPin, HIGH);
  delay(3000); // Keep the "launch" LED on for 3 seconds
  digitalWrite(finalLEDPin, LOW); // Turn off the "launch" LED

  // Reset the countdown mode
  countdownMode = false;
}
