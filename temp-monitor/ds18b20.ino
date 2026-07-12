#include <WiFi.h>
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// -------- OLED --------
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// -------- DS18B20 --------
#define ONE_WIRE_BUS 4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// -------- WiFi --------
const char* ssid = "Your Wifi id";
const char* password = "Your Wifi password";

WiFiServer server(80);

float temperature = 0;

void setup() {

  Serial.begin(115200);
  delay(1000);

  Serial.println("Starting...");

  // DS18B20
  sensors.begin();

  // OLED
  Wire.begin(22, 21);      // SDA, SCL

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED allocation failed");
    while (1);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);

  display.setCursor(0,0);
  display.println("Connecting WiFi...");
  display.display();

  // WiFi
  WiFi.begin(ssid, password);

  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {

  // Read temperature
  sensors.requestTemperatures();
  temperature = sensors.getTempCByIndex(0);

  // OLED Display
  display.clearDisplay();

  display.setCursor(0,0);
  display.setTextSize(1);
  display.println("ESP32 Temp Monitor");

  display.println();

  display.print("Temp: ");
  display.print(temperature);
  display.println(" C");

  display.println();

  display.print("IP:");
  display.println(WiFi.localIP());

  display.display();

  // Web Server
  WiFiClient client = server.available();

  if (client) {

    while (client.connected()) {

      if (client.available()) {

        client.readStringUntil('\r');
        client.flush();

        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println();

        client.println("<!DOCTYPE html>");
        client.println("<html>");
        client.println("<head>");
        client.println("<meta http-equiv='refresh' content='2'>");
        client.println("<title>ESP32 Temperature</title>");
        client.println("</head>");

        client.println("<body style='font-family:Arial;text-align:center;'>");

        client.println("<h1>ESP32 Temperature Monitor</h1>");

        client.print("<h2>");
        client.print(temperature);
        client.println(" &deg;C</h2>");

        client.println("<p>Auto Refresh Every 2 Seconds</p>");

        client.println("</body>");
        client.println("</html>");

        break;
      }
    }

    client.stop();
  }

  delay(1000);
}
