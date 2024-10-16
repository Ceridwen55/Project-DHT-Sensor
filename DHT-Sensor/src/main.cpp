#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define Type DHT11

int sensePin = 2;
DHT HT(sensePin,Type);
float humidity;
float tempC;
float tempF;
float tempK;

void setup()
{
  Serial.begin(9600);
  HT.begin();
}

void loop() 
{
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = (tempC * 9.0/5.0) + 32.0;
  tempK = tempC + 273.0;

  Serial.print("Humidity : ");
  Serial.println(humidity);
  delay(1000);

  Serial.print("Temperature Celcius : ");
  Serial.println(tempC);
  delay(1000);
  
  Serial.print("Temperature Fahrenheit : ");
  Serial.println(tempF);
  delay(1000);

  Serial.print("Temperature Kelvin : ");
  Serial.println(tempK);
  delay(1000);

}


