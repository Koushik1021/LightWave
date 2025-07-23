# 🌟 LightWave

**LightWave** is a smart lighting and environmental monitoring system designed to optimize energy usage and comfort. It automatically adjusts light intensity based on human presence and temperature, detects rain, and monitors air quality to enhance safety and sustainability.

---

## 🚀 Features

* 💡 **Smart Lighting Control** – Adjusts light intensity based on human presence using a PIR sensor and ambient light using LDR.
* 🌡️ **Temperature-Based Lighting** – Modulates light output depending on temperature levels.
* 🌧️ **Rain Detection** – Alerts or responds to rainfall using a rain sensor.
* 🌬️ **Air Quality Monitoring** – Monitors air quality with an MQ-135 sensor.
* 📶 **IoT Integration** – Real-time monitoring and data processing using microcontrollers.

---

## 🛠️ Technologies Used

* **Microcontroller:** ESP32 / Arduino
* **Sensors:**

  * PIR Sensor (for motion detection)
  * LDR (for ambient light detection)
  * DHT11 (for temperature and humidity)
  * MQ-135 (for air quality)
  * Rain Sensor
* **Programming Language:** C/C++ (Arduino IDE)
* **Communication:** Serial / Wi-Fi (if applicable)
* **Power Supply:** 5V regulated source or battery

---

## 📸 System Architecture

```
          +--------------+      
          |   PIR Sensor |----+
          +--------------+    |
                              |
          +--------------+    |        +---------------+
          |    LDR       |----+------->|   Microcontroller (ESP32) |
          +--------------+             +---------------+
                              |        |               |
          +--------------+    |        |               |
          |   DHT11      |----+        |               |
          +--------------+             |               |
                                       v               v
                              +--------------+   +------------+
                              |   Rain Sensor|   | MQ-135     |
                              +--------------+   +------------+
                                       |
                                       v
                               +----------------+
                               |    LED Lights   |
                               +----------------+

```

---

## 📦 How to Use

1. **Connect all sensors** to the microcontroller as per circuit design.
2. **Upload the code** from the `/src` folder using the Arduino IDE.
3. **Power the device** and observe automatic adjustments in lighting and sensor outputs.

---

## 📈 Future Enhancements

* Integration with **cloud dashboards** for real-time monitoring
* **Mobile app interface** for manual control and visualization
* **Energy analytics** and usage reports

---

## 🧑‍💻 Author

**Koushik1021** – [GitHub Profile](https://github.com/Koushik1021)
