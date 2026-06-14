https://github.com/user-attachments/assets/8b346910-3b76-405f-8918-e63fa6f2abb9

**Smart Environmental Monitor**

Objective:
To design and simulate a real-time embedded system capable of reading, processing, and displaying ambient environmental data using an ESP32 microcontroller.

Hardware & Components:
Microcontroller: ESP32 Development Board
Sensor: DHT22 (or DHT11) Temperature and Humidity Sensor
Display: 16x2 Character LCD with an I2C Backpack

Software & Libraries:
Language: C++ (Arduino Framework)
Simulation Environment: Wokwi IoT Simulator
Dependencies: Adafruit DHT Sensor Library, LiquidCrystal I2C

System Architecture & Functionality:
Data Acquisition: The ESP32 is programmed to query the DHT22 sensor every 2 seconds via a single digital data line (GPIO 13), ensuring stable timing for the sensor's protocol.
Processing & Error Handling: The microcontroller extracts the raw humidity percentage and Celsius temperature values. The execution loop includes integrated error handling (isnan checks) to immediately flag physical wire disconnections or protocol mismatches.
Data Output: Processed telemetry is transmitted simultaneously to two interfaces: it streams to a Serial Monitor for backend debugging and is formatted and pushed via the I2C protocol (SDA/SCL pins) to a local LCD screen for real-time user visualization.

[Smart Environmental Monitor Project.zip](https://github.com/user-attachments/files/28927402/Smart.Environmental.Monitor.Project.zip)
