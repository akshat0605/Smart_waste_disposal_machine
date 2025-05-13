Smart Disposal Machine
An IoT-enabled, hygienic, and efficient waste disposal solution designed to improve garbage management in high-traffic areas such as airports, railway stations, and university campuses. The Smart Disposal Machine (SDM) integrates real-time fill monitoring, expandable storage, and semi-automated bag sealing for improved operational efficiency and sanitation.




Quick Start Guide:
Power on the device using 18650 Li-Ion batteries.
Download the Blynk app and connect using the ESP32 credentials.
Monitor bin levels live on the app.
Use the expansion feature via app button when notified of near-full status.
Remove sealed bag when full and insert a new one.

Installation Instructions:
Install required libraries
Flash the code to the ESP-32 and Arduino UNO.
Connect components as per circuit diagram in docentation.
Launch the Blynk app and bind your device.

Basic Usage:
Fill Detection: 4 ultrasonic sensors detect waste level.
App Control: Blynk displays current fill level and allows remote expansion.
Bag Sealing: Semi-automated sealing via motor-driven thread wrap.
LED Indicators: Three LEDs signal waste level status locally.

Documentation:
Full project documentation, CAD models, and implementation steps can be found in the report.

Prerequisites:
Software:
Arduino IDE
Blynk App
OnShape (for CAD)
Hardware:
ESP-32
Arduino UNO
HC-SR04 Sensors (x4)
servo Motors
Nichrome Wire
L298N Motor Driver
Relay Modules
LEDs, Batteries, Acrylic Sheets

Contributing:
We welcome contributions! Please refer to the CONTRIBUTING.md for guidelines on how to get started.

License:
This project is licensed under the MIT License. See the LICENSE file for more information.

Technologies Used:
Microcontrollers: ESP-32, Arduino UNO

Sensors: 
HC-SR04 Ultrasonic Sensors

IoT:
Blynk App, WiFi

CAD Tools: 
OnShape, DWG for laser cutting

Languages: 
C++, Arduino Sketch

