# MQ135-Gas-Monitoring-System-using-Arduino
Air Quality Monitoring System using MQ135 Gas Sensor and Arduino UNO to measure CO2, NH3, and Alcohol concentrations in PPM. Real-time values are displayed on a 16x2 LCD and Serial Monitor using calibrated Rs/R0 gas curve equations.
# 🌫️ MQ135 Gas Monitoring System (Arduino)

##  Overview
This project measures air quality using the MQ135 gas sensor and displays gas concentration in PPM on a 16x2 LCD and Serial Monitor.

Detected gases:
- CO2
- NH3
- Alcohol Vapors

---

## 🖼️Project Image

![Project Image](add-![WhatsApp Image 2026-02-20 at 5 04 42 PM](https://github.com/user-attachments/assets/eedcc827-f649-440d-9b8a-fc6c90feb517)
your-image-here.jpg)


##  Components Used
- Arduino UNO
- MQ135 Gas Sensor Module
- 16x2 LCD Display
- Breadboard & Jumper Wires

---

## ⚙️ Working Principle
- Reads analog value from MQ135
- Calculates Rs and Rs/R0 ratio
- Uses datasheet equation to estimate PPM
- Displays float values on LCD using `dtostrf()`

---

## 🧮Gas Formula Used

```
Rs = ((5 - Vout) / Vout) × RL
Ratio = Rs / R0

CO2 = 116.602 × pow(ratio, -2.769)
NH3 = 102.2 × pow(ratio, -2.473)
Alcohol = 77.255 × pow(ratio, -2.391)
```

---

## ⚠️Note
- R0 must be calibrated in clean air.
- Values are approximate.

---

##  Author
Alka Bhutta  
Embedded Systems Learner 🚀
