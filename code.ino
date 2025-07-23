#include <ESP8266WiFi.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define PIR_SENSOR D1
#define LDR_SENSOR D0  // Analog pin
#define MQ135_SENSOR A0  // Uses the same A0, switch with delay
#define RAIN_SENSOR A0   // Uses the same A0, switch with delay
#define DHT_PIN D2
#define RED_LED D8  // Red LED pin
#define YELLOW_LED D6  // Yellow LED pin
#define WHITE_LED D7  // White LED pin
#define DHTTYPE DHT11

DHT dht(DHT_PIN, DHTTYPE);

void setup() {
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    pinMode(PIR_SENSOR, INPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(WHITE_LED, OUTPUT);
    dht.begin();
}

void loop() {
    int pirState = digitalRead(PIR_SENSOR);
    int ldrValue = analogRead(LDR_SENSOR);  
    delay(100); // Debounce delay for LDR sensor
    int airQuality = analogRead(MQ135_SENSOR); 
    delay(100); // Switch between MQ135 and Rain sensor
    int rainValue = analogRead(RAIN_SENSOR);

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    // Check if the DHT readings are valid
    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    // Default LED states (LOW means OFF, HIGH means ON)
    int redState = LOW;
    int yellowState = LOW;
    int whiteState = LOW;

    if (pirState == HIGH) {
        // Control Red LED based on LDR (brightness adjustment)
        if (ldrValue < 500) {
            redState = HIGH; // Turn on Red LED in low light
        }
        
        // Control Yellow LED based on temperature
        if (temperature > 30) {
            yellowState = HIGH; // Turn on Yellow LED for high temperature
        }
        
        // Control White LED based on air quality
        if (airQuality > 600) { // Assuming higher value means poor air quality
            whiteState = HIGH; // Turn on White LED for poor air quality
        }
    }

    // Set LED states
    digitalWrite(RED_LED, redState);
    digitalWrite(YELLOW_LED, yellowState);
    digitalWrite(WHITE_LED, whiteState);

    // Output the sensor readings to Serial Monitor
    Serial.println("--- Sensor Readings ---");
    Serial.print("PIR Sensor: "); Serial.println(pirState);
    Serial.print("LDR Sensor: "); Serial.println(ldrValue);
    Serial.print("Air Quality (MQ-135): "); Serial.println(airQuality);
    Serial.print("Temperature (°C): "); Serial.println(temperature);
    Serial.print("Humidity (%): "); Serial.println(humidity);
    Serial.print("Rain Sensor: "); Serial.println(rainValue);
    Serial.print("Red LED: "); Serial.println(redState);
    Serial.print("Yellow LED: "); Serial.println(yellowState);
    Serial.print("White LED: "); Serial.println(whiteState);
    Serial.println("-----------------------");

    delay(1000);  // Delay between each loop iteration
}
