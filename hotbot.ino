#include <Arduino.h>
#include <DHT22.h>

#define DHT22_PIN 13

DHT22 myDHT22(DHT22_PIN);

void setup(void)
{
  Serial.begin(9600);
}

void loop(void)
{ 
  DHT22_ERROR_t errorCode;
  
  delay(2000);
  
  errorCode = myDHT22.readData();
  switch(errorCode)
  {
    case DHT_ERROR_NONE:
      int temperature;
      int humidity;
      temperature = myDHT22.getTemperatureC();
      humidity = myDHT22.getHumidity();

      char buf[128];
      sprintf(buf, '{"temperature": %i, "humidity": %i}', temperature, humidity);
      Serial.println(buf);
      break;
    case DHT_ERROR_CHECKSUM:
      Serial.println("{error: 'check sum error'}");
      break;
    case DHT_BUS_HUNG:
      Serial.println("{error: 'BUS hung'}");
      break;
    case DHT_ERROR_NOT_PRESENT:
      Serial.println("{error: 'not present'}");
      break;
    case DHT_ERROR_ACK_TOO_LONG:
      Serial.println("{error: 'ACK timeout'}");
      break;
    case DHT_ERROR_SYNC_TIMEOUT:
      Serial.println("{error: 'sync timeount'}");
      break;
    case DHT_ERROR_DATA_TIMEOUT:
      Serial.println("{error: 'data timeount'}");
      break;
    case DHT_ERROR_TOOQUICK:
      Serial.println("{error: 'polled too quick'}");
      break;
  }
}
