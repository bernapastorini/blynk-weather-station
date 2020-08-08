#define BLYNK_PRINT Serial
#define BMP280_I2C_ADDRESS 0x76 //Si no funciona, intenta con 0x77
#define DHTTYPE DHT22

#include <Adafruit_BMP280.h>
#include "DHT.h"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <TimeLib.h>
#include <WidgetRTC.h>

BlynkTimer timer;
WidgetRTC rtc;

char auth[] = "TU TOKEN DE BLYNK";
char ssid[] = "EL NOMBRE DE TU RED WIFI";
char pass[] = "LA CONTRASEÑA DE TU RED WIFI";

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
  rtc.begin(); //Sincroniza el reloj al conectarse
}

void setup() 
{
  Wire.begin(4, 0);
  Serial.begin(9600);
  Serial.println("Comunicacion serial iniciada.");

  Blynk.begin(auth, ssid, pass);
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
      Serial.println(String("Presión: " ) + pressure);

      averageTemp = (tempBMP + tempDHT) / 2;
      int minutes = minute();

      Blynk.tweet(String(hour()) + ":" + minute() + "hs. La temperatura es de " + averageTemp + "ºC, la presión " + pressure + " hPa, y la humedad " + humidity + "%.");
      Blynk.notify("Tweeteado.");
      Serial.println(".");
      Serial.println("Tweeteado.");
      tweeted = true;

      Serial.println(String(hour()) + ":" + minute() + "hs. La temperatura es de " + averageTemp + "ºC, la presión " + pressure + " hPa, y la humedad " + humidity + "%.");
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