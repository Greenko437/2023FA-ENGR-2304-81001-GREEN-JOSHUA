// 2023-ENGR-2304-81001-GREEN-JOSHUA-P05

#include <LiquidCrystal.h>

// Connect the LCD pins to Arduino as follows:
// RS -> Pin 12, E -> Pin 11, D4 -> Pin 5, D5 -> Pin 4, D6 -> Pin 3, D7 -> Pin 2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD:
  lcd.print("Hello World!");
}

void loop() {
  // Nothing here as we only want to print the message once
}