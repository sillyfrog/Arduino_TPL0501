#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "TPL0501.h"
TPL0501 *tpl = new TPL0501(1, 2, 3); // SCLK is pin 1, DIN is pin 2, CS is pin 3

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET 18
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
  // Initialize Serial Monitor
  Serial.begin(115200);

  // Initialize the I2C bus with custom SDA and SCL pins
  Wire.begin(8, 9); // SDA is pin 8, SCL is pin 9

  // Initialize the display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }

  display.clearDisplay();

  // Set text size and color
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Set cursor position for IP address
  display.setCursor(0, 0);
  display.print("Setting output to");

  display.display(); // Update the display with the text
}

int value = 0;
void loop()
{
  // Set the resistor
  tpl->setResistor(value);

  // Clear the previous counter text area
  display.fillRect(0, 10, SCREEN_WIDTH, 16, SSD1306_BLACK);
  // Set cursor position for counter
  display.setCursor(0, 10);
  // Display the counter
  int resistance = (100000 / 256) * value;
  String text = "Value: " + String(value);
  display.println(text);
  if (resistance < 1000)
    text = "Resistance: " + String(resistance) + " ohm";
  else
    text = "Resistance: " + String(resistance / 1000) + " K ohm";
  display.println(text);
  display.display(); // Update the display with the counter

  delay(200);

  value++; // Increment the counter
  if (value > 255)
  {
    value = 0;
  }
}