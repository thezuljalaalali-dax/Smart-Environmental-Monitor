#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// --- Wokwi Guaranteed Setup ---
#define DHTPIN 13      // Moved to a 100% safe pin (D4)
#define DHTTYPE DHT22 // MUST be DHT22 for Wokwi's default sensor

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  Serial.begin(115200);
  Serial.println("Initializing Wokwi Environment...");

  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("System Ready...");
  delay(1000);
  lcd.clear();
}

void loop() {
  delay(2000);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Error: Wires mismatched or wrong sensor type!");
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error   ");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  |  Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1); 
  lcd.print((char)223);      
  lcd.print("C   ");         

  lcd.setCursor(0, 1);
  lcd.print("Hum:  ");
  lcd.print(humidity, 1);
  lcd.print("%   ");
}