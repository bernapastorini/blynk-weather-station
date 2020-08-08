<html style="text-align: justify;">
<h1>Estacion meteorológica Arduino - NodeMCU</h1>
<br>
<p>Registra temperatura (a través de dos sensores diferentes, para minimizar errores), presión atmosférica y humedad ambiente, y las <b>publica en twitter de manera automática</b>, a través de un servidor del servicio 'Blynk'.</p>
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
            <li>Descargar la ultima version, descomprimir, y copiar el contenido de la carpeta 'libraries' dentro de la carpeta del mismo nombre, de Arduino (Generalmente ubicada en 'C:\Archivos de Programa\Arduino').</li>
        </ul>
    </li>
    <li>
        <b>DHT22 by Adafruit: </b> Instalable desde el gestor de librerías del IDE de Arduino. <br>
    </li>
    <li>
        <b>BMP280 by Adafruit: </b> Instalable desde el gestor de librerías del IDE de Arduino.<br>
    </li>
    <li>
        <b>Time by Michael Margolis: </b> Incluida en la librería de Blynk. <br>
    </li>
</ul>

<h2>Requerimientos previos</h2> <br>
<ol>
    <li>Instalar las librerias mencionadas en el item <a href="#librerías-utilizadas">Librerías utilizadas</a>.</li>
    <li>Añadir las tarjetas ESP8266 al IDE de Arduino, yendo al menu Archivo > Preferencias, y pegando el link https://arduino.esp8266.com/stable/package_esp8266com_index.json donde dice 'Gestor de URLs adicionales de tarjetas'.</li>
    <li>Tambien en el IDE de Arduino, ir al menu Herramientas > Placa > Gestor de tarjetas, buscar ESP8266, e instalar la ultima versión disponible.</li>
</ol>
</html>