<img src="https://r2cdn.perplexity.ai/pplx-full-logo-primary-dark%402x.png" class="logo" width="120"/>

# 🚮 Smart Disposal Machine (SDM)

**An IoT-enabled, hygienic, and efficient waste disposal solution for smarter garbage management in high-traffic areas.**

## ✨ Overview

The **Smart Disposal Machine (SDM)** is designed to revolutionize waste management in places like airports, railway stations, and university campuses. With real-time fill monitoring, expandable storage, and semi-automated bag sealing, SDM ensures both operational efficiency and superior sanitation.

## ⚡ Quick Start Guide

1. **Power Up:**
Insert 18650 Li-Ion batteries and power on the device.
2. **Connect via Blynk:**
    - Download the Blynk app.
    - Connect using the ESP32 credentials provided.
3. **Live Monitoring:**
    - Track bin fill levels in real time on the app.
4. **Expand Storage:**
    - Use the expansion feature in the app when notified of a near-full status.
5. **Bag Replacement:**
    - Remove the sealed bag when full.
    - Insert a new bag to continue operation.

## 🛠️ Installation Instructions

- **Install Required Libraries:**
Ensure all necessary libraries are added to your development environment.
- **Flash Firmware:**
Upload the code to both the ESP-32 and Arduino UNO.
- **Hardware Setup:**
Connect all components as per the circuit diagram in the documentation.
- **App Binding:**
Launch the Blynk app and bind your device for live control and monitoring.


## 🚀 Basic Usage

- **Fill Detection:**
Four ultrasonic sensors continuously monitor waste levels.
- **Remote App Control:**
The Blynk app displays current fill status and enables remote expansion.
- **Bag Sealing:**
Semi-automated sealing via a motor-driven thread wrap ensures hygiene.
- **LED Indicators:**
Three LEDs provide a local, visual signal of waste levels.


## 🔧 Prerequisites

### Software

- Arduino IDE
- Blynk App
- OnShape (for CAD modeling)


### Hardware

- ESP-32
- Arduino UNO
- HC-SR04 Ultrasonic Sensors (x4)
- Servo Motors
- Nichrome Wire
- L298N Motor Driver
- Relay Modules
- LEDs, Batteries, Acrylic Sheets


## 🤝 Contributing

We welcome contributions!
Please see the [CONTRIBUTING.md](https://github.com/akshat0605/Smart_waste_disposal_machine/blob/main/CONTRIBUTING.md) for guidelines on how to get started.

## 📄 License

This project is licensed under the MIT License.
See the [LICENSE](https://github.com/akshat0605/Smart_waste_disposal_machine/blob/main/LICENSE.md) file for more information.

## 🧰 Technologies Used

| Category | Details |
| :-- | :-- |
| Microcontrollers | ESP-32, Arduino UNO |
| Sensors | HC-SR04 Ultrasonic Sensors |
| IoT | Blynk App, WiFi |
| CAD Tools | OnShape, DWG for laser cutting |
| Programming | C++, Arduino Sketch |

> **Empowering smart, sustainable, and sanitary waste management for the spaces that need it most!**
