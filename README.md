# Smart Grid Fault Detection with IoT Sensors

**IoT-based Smart Grid Fault Detection system with real-time monitoring and alerting.**  

This project demonstrates how embedded IoT sensors can be used to monitor a power distribution line, detect faults (overcurrent, short circuit, or line interruptions), and send data to a dashboard for real-time visualization.

---

## Features
- Voltage & current sensing using IoT-enabled modules  
- Fault detection algorithm (overcurrent, undervoltage, disconnection)  
- Wireless data transmission (ESP32/Arduino + WiFi/Serial)  
- Real-time dashboard for monitoring (Python/ThingSpeak/Blynk)  
- Modular design with separate hardware, firmware, and visualization  

---

## Hardware Used
- ESP32 (can use Arduino UNO too) 
- Current Sensor (ACS712)  
- Voltage Divider Circuit (for line voltage monitoring)  
- Relay Module (for isolation/testing)  
- Breadboard, jumper wires, power supply  

---

## Software / Tools
- Arduino IDE (C/C++ for firmware)  
- Python (Matplotlib, PySerial, Pandas)  
- ThingSpeak / Blynk (optional dashboard hosting)  
- GitHub for version control  

---

## How It Works
1. Sensors measure **voltage/current** and send data to the microcontroller.  
2. Fault detection algorithm identifies abnormal conditions.  
3. Fault event triggers alert + logs data.  
4. Dashboard visualizes readings in **real-time**.  

---

## How to Run
### Firmware
1. Open `firmware/fault_detection.ino` in Arduino IDE.  
2. Select your board (ESP32/Arduino UNO).  
3. Upload the sketch.  

### Dashboard
1. Install dependencies:  
   ```bash
   pip install pyserial matplotlib pandas
   ```  
2. Run the script:  
   ```bash
   python dashboard/realtime_plot.py
   ```  
3. View real-time plots of current & voltage data.  

---

## Sample Output
- **Terminal log**: shows sensor readings + fault alerts  
- **Python plot**: real-time voltage/current chart  
- **Dashboard**: remote monitoring option  

---

## Example terminal log

Voltage: 230.5 V | Current: 5.2 A  
✓ System Normal  

Voltage: 270.1 V | Current: 18.7 A  
⚠ Overvoltage + Overcurrent Fault Detected!

---
