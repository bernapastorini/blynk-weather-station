<html style="text-align: justify;">
<h1>Estación meteorológica Arduino - NodeMCU</h1>
<br>
<p>Utilizando un microcontrolador WiFi <b>NodeMCU ESP8266</b>, sensores <b>DHT22</b> y <b>BMP280</b>, registra la temperatura, presión atmosférica y humedad ambiente, y las <b>publica en twitter de manera automática</b>, a través de un servidor del servicio 'Blynk'.</p>
<h2>Links útiles</h2><br>
<ul>
<li><b>Descarga App Blynk Android: </b> https://play.google.com/store/apps/details?id=cc.blynk&hl=es_AR <br></li>
<li><b>Descarga App Blynk iOS: </b> https://apps.apple.com/ar/app/blynk-iot-for-arduino-esp32/id808760481 <br></li>
<li><b>Documentación oficial de Blynk: </b> http://docs.blynk.cc/ <br></li>
</ul>

<h2>Librerías utilizadas</h2> <br>
<ul>
    <li>
        <b>Blynk: </b> https://github.com/blynkkk/blynk-library/releases 
        <ul>
            <li>Descargar la última version, descomprimir, y copiar el contenido de la carpeta 'libraries' dentro de la carpeta del mismo nombre, de Arduino (Generalmente ubicada en 'C:\Archivos de Programa\Arduino').</li>
        </ul>
    </li>
    <li>
        <b>DHT22 by Adafruit: </b> Instalable desde el gestor de librerías del IDE de Arduino.
        <ul>
            <li>En el IDE de Arduino, ir a Herramientas > 'Administrar bibliotecas...', buscar 'DHT22', verificar que sea la distribuida por Adafruit, y darle al boton 'Instalar'.</li>
        </ul>
    </li>
    <li>
        <b>BMP280 by Adafruit: </b> Instalable desde el gestor de librerías del IDE de Arduino.
        <ul>
            <li>En el IDE de Arduino, ir a Herramientas > 'Administrar bibliotecas...', buscar 'BMP280', verificar que sea la distribuida por Adafruit, y darle al boton 'Instalar'.</li>
        </ul>
    </li>
    <li>
        <b>Time by Michael Margolis: </b> Está incluida en la librería de Blynk instalada anteriormente.
    </li>
</ul>

<h2>Requerimientos previos</h2> <br>
<ol>
    <li>Instalar las librerias mencionadas en el apartado <a href="#librerías-utilizadas">Librerías utilizadas</a>.</li>
    <li>Añadir las tarjetas ESP8266 al IDE de Arduino, yendo al menú <b>Archivo > Preferencias</b>, y pegando el link https://arduino.esp8266.com/stable/package_esp8266com_index.json donde dice 'Gestor de URLs adicionales de tarjetas'.</li>
    <li>Tambien en el IDE de Arduino, ir al menú <b>Herramientas > Placa > Gestor de tarjetas</b>, buscar ESP8266, e instalar la última versión disponible.
        <ul>
            <li>Ahora en el menú <b>Herramientas > Placa > ESP8266 Boards</b>, deberás elegir la <b>NodeMCU 1.0</b>.</li>
        </ul>
    </li>
    <li>Descarga en tu telefono la aplicación de Blynk. Puedes buscarla en la tienda de aplicaciones, o utilizar los links que dejé en <a href="#links-útiles">Links útiles</a>.</li>
    <li>Crea un proyecto en Blynk.
        <ul>
            <li>Abre la app de Blynk, y registrate.</li>
            <li>Selecciona 'New Project', dale un nombre a tu proyecto, y en 'Choose Device', selecciona 'NodeMCU'.</li>
            <li>A tu cuenta de correo electronico te habra llegado un codigo ('Auth Token'), lo vas a necesitar pronto, asi que no borres ese correo.</li>
            <li>Presiona el boton <b>+</b>, y añade los elementos 'Twitter', 'Notification', y 'Real-time clock'. Para el primero, te pedira los datos de la cuenta de Twitter desde la que quieras publicar.</li>
        </ul>
    </li>
</ol>

<h2>Configurando el código</h2>
<p>Una vez cubiertos los Requerimientos previos, hay algunas cosas dentro del código de <a href="https://github.com/bernapastorini/blynk-weather-station/blob/master/WeatherStation.ino">WeatherStation.ino</a> que deberas personalizar. <br>

```cpp
char auth[] = "TU TOKEN DE BLYNK"; //Aqui, entre las comillas, deberás pegar el Auth Token que llegó a tu email al crear el proyecto.
char ssid[] = "EL NOMBRE DE TU RED WIFI"; //Aqui, entre las comillas, deberás introducir el nombre de tu red WiFi.
char pass[] = "LA CONTRASEÑA DE TU RED WIFI"; //Aqui, entre las comillas, deberás introducir la contraseña de tu red WiFi.
```
</p>

<h2>Conectando los sensores</h2>
<p>Comencemos viendo los pines que tiene la placa NodeMCU (Yo utilizo la v2, pero también sirven las demás versiones):
<img src="https://www.luisllamas.es/wp-content/uploads/2018/06/esp8266-nodemcu-pinout.png" alt="NodeMCU v2 Pinout">

Para este proyecto estoy utilizando un <a href="https://www.google.com/search?q=protoboard&oq=protoboard" target="_blank">protoboard</a> plástico de 830 puntos, que me facilita mucho el proceso de prototipado. Te recomiendo que tengas uno de tamaño medio (400 puntos) como mínimo.
<br> Deberás realizar las conexiones de la siguiente manera:
<img src="https://raw.githubusercontent.com/bernapastorini/blynk-weather-station/master/WeatherStation-Fritzing_bb.png?token=ANQTRJXIJL4AD64E6YJMUNC7GB2BY" alt="WeatherStation en Fritzing">
<ul>
<b>Notas</b> 
<li>El sensor BMP280 en realidad tiene 2 pines mas (CSB y SDD), pero no los utilizamos para este proyecto.</li>
<li>Con la conexion USB del NodeMCU deberia ser suficiente para alimentar tu proyecto. Si por alguna razon no alcanza, siempre puedes enviarle electricidad desde otro dispositivo (Como un Arduino UNO), a traves del pin de 5V de Arduino, al pin 'VIN' del NodeMCU y conectando también 'GND' de ambos controladores.</li>
</ul>
</p>
</html>