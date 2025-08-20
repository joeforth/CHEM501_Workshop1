#include "Arduino_BHY2Host.h"

// Define sensor names - doesn't have to be "temperature"
Sensor temperature(SENSOR_ID_TEMP);

// Tell the Arduino what numbers are going exist
float temperatureValue = 0;

void setup(){
  // Start reading a serial port, turn on the sensors
  Serial.begin(115200);
  BHY2Host.begin();
  temperature.begin();
}

void loop(){
  // Update sensor values and store the temperature value
  BHY2Host.update();
  temperatureValue = temperature.value();

  // Write the temperature value to the computer
  Serial.println(temperatureValue);
}
