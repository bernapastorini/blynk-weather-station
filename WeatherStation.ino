#define BMP280_I2C_ADDRESS  0x76
#define DHTTYPE DHT22
#define BLYNK_PRINT Serial

#include <Adafruit_BMP280.h>
#include "DHT.h"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <TimeLib.h>
#include <WidgetRTC.h>

BlynkTimer timer;
WidgetRTC rtc;

char auth[] = "_-_4ZkrWQ5XBgH0PO5K_Eb6h4HiU9Ojd";

char ssid[] = "Bernardo";
char pass[] = "2227430674";

bool tweeted = false;
bool firstRun = true;

float pressure;
float tempBMP;
float tempDHT;
float humidity;

float averageTemp;

int DHTPin = 14;

DHT dht(DHTPin, DHTTYPE);
Adafruit_BMP280 bmp280;

BLYNK_CONNECTED() {
  // Synchronize time on connection
  rtc.begin();
}

void setup() 
{
  Wire.begin(4, 0);
  Serial.begin(9600);
  Serial.println("Comunicacion serial iniciada.");

  //Blynk.begin(auth, ssid, pass);
  Blynk.config(auth);
  Blynk.connect();
  Serial.println("Conexion a internet establecida.");

  bmp280.begin(BMP280_I2C_ADDRESS);
  Serial.println("Sensor BMP280 conectado.");

  pinMode(DHTPin, INPUT);
  dht.begin();
  Serial.println("Sensor DHT22 conectado.");

  setSyncInterval(600); //10 minutos
  timer.setInterval(30000, reconnectBlynk);
  Serial.println("Iniciando...");
}

void loop() 
{
  timer.run();
  if(firstRun)
  {
    delay(5000);
    Serial.println("Tiempo sincronizado.");
    firstRun = false;
  }

  if(Blynk.connected() == true)
  {
    Blynk.run();
  }

  if(!tweeted)
  {
    if(minute() == 0 || minute() == 30)
    {
      pressure = bmp280.readPressure() / 100;
      tempBMP = bmp280.readTemperature();
      tempDHT = dht.readTemperature(false);
      humidity = dht.readHumidity();

      Serial.println("");
      Serial.println(String("Temperatura DHT: ") + tempDHT);
      Serial.println(String("Temperatura BMP: ") + tempBMP);

      averageTemp = (tempBMP + tempDHT) / 2;
      int minutes = minute();

      Blynk.tweet(String(hour()) + ":" + minute() + "hs. La temperatura es de " + averageTemp + "ºC, la presión " + pressure + " hPa, y la humedad " + humidity + "%.");
      Blynk.notify("Tweeteado.");
      Serial.println(".");
      Serial.println("Tweeteado.");
      tweeted = true;
      Serial.println(tweeted);

      Serial.println(String(hour()) + ":" + minute() + " La temperatura es de " + averageTemp + "ºC, la presion " + pressure + " hPa, y la humedad " + humidity + "%.");
    }
  }

  if(tweeted)
  {
    if(minute() != 0 && minute() != 30)
    { 
      tweeted = false;
      Serial.println(tweeted);
    }
  }
  Serial.print(".");
  delay(10000);
}

void reconnectBlynk() {
  if (!Blynk.connected()) {
    Serial.println(".");
    Serial.println("Conexión perdida");
    if(Blynk.connect()) {
      Serial.println(".");
      Serial.println("Reconectado");
    }
    else {
      Serial.println(".");
      Serial.println("Sin conexión");
    }
  }
}