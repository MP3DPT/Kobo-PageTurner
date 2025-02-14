#include <BleKeyboard.h>
#include "esp_sleep.h"
#include "driver/rtc_io.h"
#include "driver/adc.h"

//Kobo Page Turner by MP3D mp3dpt@gmail.com
//if you want to buy me a coffee - paypal.me/mmpires


// Define the pins for the buttons and LED
const int buttonPin1 = D5;     // Button 1 (will send Left Arrow)
const int buttonPin2 = D4;     // Button 2 (will send Right Arrow)
const int extLedPin = D9;      // External LED pin (GPIO9)
const int LED_BRIGHTNESS = 1;  // Value between 0-255 for brightness (adjust as needed - If you want a flashlight, put the 255 :P)

// Sleep mode parameters
const unsigned long SLEEP_TIMEOUT = 300000;  // 5 minutes
unsigned long lastConnectedTime = 0;
bool wasConnected = false;

BleKeyboard bleKeyboard("Kobo Page Turner"); //BL Device name that will appear

void goToSleep() {
    Serial.println("Going to sleep...");
    analogWrite(extLedPin, 0);  // Turn off LED before sleep
    delay(100);

    esp_sleep_enable_gpio_wakeup();
    gpio_wakeup_enable((gpio_num_t)buttonPin1, GPIO_INTR_LOW_LEVEL);
    gpio_wakeup_enable((gpio_num_t)buttonPin2, GPIO_INTR_LOW_LEVEL);

    esp_deep_sleep_start();
}

void setup() {
    Serial.begin(115200);
    Serial.println("Starting Kobo Page Turner...");

    // Initialize BLE Keyboard
    bleKeyboard.begin();
    delay(2000);

    // Initialize pins
    pinMode(buttonPin1, INPUT_PULLUP);
    pinMode(buttonPin2, INPUT_PULLUP);
    pinMode(extLedPin, OUTPUT);
    analogWrite(extLedPin, LED_BRIGHTNESS);  // Set initial LED brightness

    Serial.println("Setup complete");
}

void loop() {
    if (bleKeyboard.isConnected()) {
        analogWrite(extLedPin, 0);  // LED off when connected
        lastConnectedTime = millis();
        wasConnected = true;
    } else {
        analogWrite(extLedPin, LED_BRIGHTNESS);  // Dimmed LED when disconnected
        
        if (wasConnected && (millis() - lastConnectedTime >= SLEEP_TIMEOUT)) {
            goToSleep();
        }
    }

    // Button 1 handling
    if (digitalRead(buttonPin1) == LOW) {
        Serial.println("Button 1 pressed, sending Left Arrow...");
        if (bleKeyboard.isConnected()) {
            bleKeyboard.press(KEY_LEFT_ARROW);
            delay(100);
            bleKeyboard.releaseAll();
        }
        lastConnectedTime = millis();
        delay(500);
    }

    // Button 2 handling
    if (digitalRead(buttonPin2) == LOW) {
        Serial.println("Button 2 pressed, sending Right Arrow...");
        if (bleKeyboard.isConnected()) {
            bleKeyboard.press(KEY_RIGHT_ARROW);
            delay(100);
            bleKeyboard.releaseAll();
        }
        lastConnectedTime = millis();
        delay(500);
    }

    delay(10);
}