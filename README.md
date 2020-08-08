<html style="text-align: justify;">
<h1>Estacion meteorológica Arduino - NodeMCU</h1>
<br>
<p>Utilizando un microcontrolador WiFi <b>NodeMCU ESP8266</b>, sensores <b>DHT22</b> y <b>BMP280</b>, registra temperatura (a través de dos sensores diferentes, para minimizar errores), presión atmosférica y humedad ambiente, y las <b>publica en twitter de manera automática</b>, a través de un servidor del servicio 'Blynk'.</p>
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
    <li>Añadir las tarjetas ESP8266 al IDE de Arduino, yendo al menu Archivo > Preferencias, y pegando el link https://arduino.esp8266.com/stable/package_esp8266com_index.json donde dice 'Gestor de URLs adicionales de tarjetas'.</li>
    <li>Tambien en el IDE de Arduino, ir al menu Herramientas > Placa > Gestor de tarjetas, buscar ESP8266, e instalar la ultima versión disponible.</li>
    <li>Descarga en tu telefono la aplicacion de Blynk. Puedes buscarla en la tienda de aplicaciones, o utilizar los links que deje en <a href="#links-útiles">Links útiles</a>.</li>
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
<p>Una vez cubiertos los Requerimientos previos, hay algunas cosas dentro del código que deberas personalizar. <br>

```cpp
char auth[] = "TU TOKEN DE BLYNK"; //Aqui, entre las comillas, deberas pegar el Auth Token que llego a tu email al crear el proyecto.
char ssid[] = "EL NOMBRE DE TU RED WIFI"; //Aqui, entre las comillas, deberas introducir el nombre de tu red WiFi.
char pass[] = "LA CONTRASEÑA DE TU RED WIFI"; //Aqui, entre las comillas, deberas introducir la contraseña de tu red WiFi.
```

</p>
</html>