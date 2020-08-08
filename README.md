<h1>Estacion meteorológica Arduino - NodeMCU</h1>
<br>
<h2>Tweetea automaticamente</h2>
<br>
<p>Registra temperatura (de dos sensores diferentes, para minimizar errores), presión atomsférica y humedad ambiente, y las publica en twitter de manera automática.</p>
<br>
<h3>Links útiles</h3>
<br>
<b>Descarga App Blynk Android: </b> https://play.google.com/store/apps/details?id=cc.blynk&hl=es_AR <br>
<b>Descarga App Blynk iOS: </b> https://apps.apple.com/ar/app/blynk-iot-for-arduino-esp32/id808760481 <br>
<b>Documentación de Blynk: </b> http://docs.blynk.cc/ <br>
<b>Añadir tarjeta NodeMCU al IDE de Arduino: </b> https://arduino.esp8266.com/stable/package_esp8266com_index.json <br>


<h2>Librerías utilizadas</h2> <br>
<ul>
    <li>
        <b>Blynk: </b> https://github.com/blynkkk/blynk-library/releases <b>Descargar la ultima version, descomprimir, y copiar el contenido de la carpeta 'libraries', dentro de la carpeta del mismo nombre, de Arduino (Generalmente ubicada en 'C:\Archivos de Programa\Arduino').</b><br>
    </li>
    <li>
        <b>DHT22: </b> Instalable desde el gestor de librerías del IDE de Arduino. <br>
    </li>
    <li>
        <b>Adafruit BMP280: </b> Instalable desde el gestor de librerías del IDE de Arduino. <br>
    </li>
    <li>
        <b>Time by Michael Margolis: </b> Incluida en la librería de Blynk. <br>
    </li>
</ul>

<h2>Requerimientos previos</h2> <br>
<ol>
    <li>Instalar las librerias mencionadas en el item <a href="#librerías-utilizadas">Librerías utilizadas</a>.</li>
    <li>Añadir las tarjetas ESP8266 al IDE de Arduino, yendo al menu Archivo > Preferencias, y pegando el link https://arduino.esp8266.com/stable/package_esp8266com_index.json donde dice 'Gestor de URLs adicionales de tarjetas' </li>
    <li>Tambien en el IDE de Arduino, ir al menu Herramientas > Placa > Gestor de tarjetas, buscar ESP8266, e instalar la ultima version disponible.</li>
</ol>