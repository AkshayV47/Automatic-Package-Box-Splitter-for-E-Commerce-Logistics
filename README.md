# IoT-based automatic package sorting system using ESP8266 and RFID to prevent courier mismatches in e-commerce logistics.

📦 Automatic Package Box Splitter for E-Commerce Logistics
📌 Project Overview

The Automatic Package Box Splitter is an IoT-based smart logistics system designed to prevent courier mis-matching in e-commerce deliveries. The system automatically identifies each package using RFID technology and mechanically routes it to the correct courier section using a servo-controlled splitting mechanism.

This solution reduces human error in sorting centers and ensures that packages are sent to the correct customers without delivery mismatches.

🎯 Key Features

📡 Package identification using RFID Reader & RFID Tags

🤖 Automatic package routing using Servo Motor

🌐 WiFi-enabled controller using ESP8266

🔁 Real-time decision making for courier separation

⚡ Stable operation with dedicated Power Supply

🚚 Minimizes wrong courier dispatches

⏱️ Faster and error-free sorting process

🛠️ Components Used

ESP8266 (NodeMCU)

RFID Reader

RFID Tags

Servo Motor

Power Supply Module

Mechanical Package Splitter

Jumper Wires & Resistors

⚙️ Working Principle

Each package is attached with a unique RFID tag.

The RFID reader scans the tag when the package enters the system.

The ESP8266 verifies the tag ID with predefined courier routing logic.

Based on the destination or courier code:

The servo motor rotates to the required angle

The package is guided to the correct courier channel

This process repeats automatically for each package, ensuring zero mismatches.

🔁 System Flow
Package → RFID Reader → ESP8266 → Courier Decision
                                   ↓
                              Servo Motor
                                   ↓
                         Correct Courier Path

🌍 Applications

E-commerce sorting hubs

Courier distribution centers

Automated warehouses

Smart logistics systems

Industrial parcel handling

🚀 Advantages

Eliminates human sorting errors

Improves delivery accuracy

Low-cost automation solution

Scalable for large logistics centers

Faster package dispatch

📌 Future Enhancements

Database / Cloud integration

Real-time tracking dashboard

Conveyor belt automation

Barcode + RFID hybrid system

AI-based routing optimization

📂 Repository Contents

ESP8266 firmware code

Circuit diagram

RFID tag mapping logic

Mechanical design reference

Project documentation
