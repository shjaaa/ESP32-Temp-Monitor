# ESP32 IoT Temperature Monitoring System

## 📌 Overview

This project is an IoT-based temperature monitoring system built using the ESP32 and DS18B20 digital temperature sensor. The ESP32 reads the temperature, displays it on an SSD1306 OLED display, and hosts a web server to monitor the temperature from any device connected to the same Wi-Fi network.

## 🚀 Features

* Real-time temperature monitoring using DS18B20
* OLED display for live temperature updates
* Built-in ESP32 web server
* Wi-Fi connectivity
* Auto-refreshing web page
* Serial Monitor output for debugging

## 🛠️ Hardware Used

* ESP32 Development Board
* DS18B20 Temperature Sensor
* SSD1306 OLED Display (I²C)
* 10 kΩ Pull-up Resistor
* Breadboard and Jumper Wires

## 📚 Software Used

* Arduino IDE
* OneWire Library
* DallasTemperature Library
* Adafruit GFX Library
* Adafruit SSD1306 Library

## 🔌 Circuit Connections

### DS18B20

* VCC → 3.3V
* GND → GND
* DATA → GPIO 25
* 10 kΩ resistor between DATA and 3.3V

### OLED Display

* VCC → 3.3V
* GND → GND
* SDA → GPIO 33
* SCL → GPIO 32

## ▶️ How to Run

1. Install the required libraries.
2. Update the Wi-Fi SSID and password in the code.
3. Upload the sketch to the ESP32.
4. Open the Serial Monitor (115200 baud).
5. Note the IP address assigned to the ESP32.
6. Open the IP address in a web browser connected to the same Wi-Fi network.

## 📷 Output

* OLED displays the live temperature.
* Browser displays the current temperature through the ESP32 web server.
* Serial Monitor shows the temperature readings and Wi-Fi status.

## 📖 Concepts Learned

* ESP32 programming
* OneWire communication
* I²C communication
* Wi-Fi networking
* Embedded systems
* IoT web server development

## 🔮 Future Improvements

* Upload temperature data to ThingSpeak.
* Add Blynk integration for remote monitoring.
* Include temperature graphs and data logging.
* Add email or mobile alerts for high temperatures.

## 👨‍💻 Author

**Shobhit Singh**
