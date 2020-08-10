<html style="text-align: justify;">
<h1>Estación meteorológica Arduino - NodeMCU</h1>
<br>
<p>Utilizando un microcontrolador WiFi <b>NodeMCU ESP8266</b>, sensores <b>DHT22</b> y <b>BMP280</b>, registra la temperatura, presión atmosférica y humedad ambiente, y las <b>publica en twitter de manera automática</b>, a través de un servidor del servicio '<b>Blynk</b>'.</p>
<br>
Mira el <a href="#resultado">resultado</a> al final de esta página.
<h2>Links útiles</h2><br>
<ul>
<li><b>Descarga App Blynk Android: </b> https://play.google.com/store/apps/details?id=cc.blynk&hl=es_AR <br></li>
<li><b>Descarga App Blynk iOS: </b> https://apps.apple.com/ar/app/blynk-iot-for-arduino-esp32/id808760481 <br></li>
<li><b>Documentación oficial de Blynk: </b> http://docs.blynk.cc/ <br></li>
</ul>
<h2>Materiales necesarios</h2>
<ul>
    <li><b>1</b> NodeMCU ESP8266 (yo utilizo la versión 2, pero puedes utilizar la que tengas).</li>
    <li><b>1</b> Sensor DHT22, que mide temperatura y humedad ambiente.</li>
    <li><b>1</b> Sensor BMP280, que mide temperatura y presión atmosférica.
        <ul>
            <li>El objetivo de utilizar dos sensores diferentes que midan temperatura, es minimizar los errores y las diferencias.</li>
        </ul>
    </li>
    <li><b>1</b> resistencia de 10k ohms. Si no sabes diferenciarlas, cada resistencia trae un código de colores diferente, puedes buscar en Google.</li>
    <li><b>9</b> cables de tipo jumper macho a macho.</li>
    <li><b>1</b> protoboard plástico de tamaño medio (400 puntos aprox), como mínimo. Yo uso uno grande, de 830 puntos.</li>
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
    <li>Instala las librerias mencionadas en el apartado <a href="#librerías-utilizadas">Librerías utilizadas</a>.</li>
    <li>Abre el archivo <b>WeatherStation.ino</b> con el IDE de Arduino, descargable desde su <a href="https://www.arduino.cc/en/Main/Software">web oficial</a>.</li>
    <li>Añade las tarjetas ESP8266 al IDE de Arduino, yendo al menú <b>Archivo > Preferencias</b>, y pegando el link https://arduino.esp8266.com/stable/package_esp8266com_index.json donde dice 'Gestor de URLs adicionales de tarjetas'.</li>
    <li>También en el IDE de Arduino, en el menú <b>Herramientas > Placa > Gestor de tarjetas</b>, busca ESP8266, e instala la última versión disponible.
        <ul>
            <li>Ahora en el menú <b>Herramientas > Placa > ESP8266 Boards</b>, deberás elegir la <b>NodeMCU 1.0</b>.</li>
        </ul>
    </li>
    <li>En el menú <b>Herramientas > Puerto</b>, deberás seleccionar el puerto al cual está conectado el NodeMCU. No te preocupes, si no eliges la correcta, te darás cuenta al intentar subir el codigo, y solo tienes que cambiar la selección de este item.</li>
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

<br> Deberás realizar las conexiones de la siguiente manera: 
<br><b>(Abrir imagen para ver correctamente los textos de los pines)</b>
<img src="https://i.imgur.com/Npy24Iv.png" alt="WeatherStation en Fritzing">
<ul>
<h4>Notas</h4>
<li>Como se ve en la imagen, deberás conectar una <b>resistencia de 10k</b> en el sensor DHT22, entre los pines de 3.3v y el que va al pin D5 del NodeMCU.</li>
<li>El sensor BMP280 en realidad tiene 2 pines mas (CSB y SDD), pero no los utilizamos para este proyecto.</li>
<li>Con la conexion USB del NodeMCU deberia ser suficiente para alimentar tu proyecto. Si por alguna razon no alcanza, siempre puedes enviarle electricidad desde otro dispositivo (Como un Arduino UNO), a traves del pin de 5V de Arduino, al pin 'VIN' del NodeMCU y conectando también 'GND' de ambos controladores.</li>
</ul>
<br>
Deberia verse mas o menos, como el mio (puedes utilizar cables mas cortos, te va a quedar mejor presentado):
<br>
<img src="https://i.imgur.com/a8pYsyD.jpg" alt="WeatherStation - Finalizado">
</p>
<h2>Resultado</h2>
<p>
Una vez hechos los cambios en el codigo y conectados todos los cables a los sensores, solo queda subir el codigo al NodeMCU, desde el IDE de Arduino (<b>Control + U</b>), entrar a la app Blynk y darle Play ► al proyecto.
<br>
<br>
El resultado será, cada media hora, un tweet como este:
<br>
<br>
<img src="https://i.imgur.com/qTv1D7n.png" alt="Weather Station - Tweet">
<br>
<br>
Si lo tienes conectado a la PC por USB irá además dando información sobre su funcionamiento a traves del Monitor Serie del IDE de Arduino (<b>Control + Mayus + M</b>).
<br>
<br>
Si lo vas a dejar al aire libre, desconectado de una PC, te recomiendo comentar la primer linea de código, y todas las que comiencen con <b>Serial.</b> anteponiendoles dos barras <b>//</b>:

```cpp
#define BLYNK_PRINT Serial      <- Esta es una linea sin comentar.
//#define BLYNK_PRINT Serial    <-Esta es una linea comentada.
Serial.begin(9600);             <- Esta es una linea sin comentar.
//Serial.begin(9600);           <-Esta es una linea comentada.
```

<b>¿Para qué comentar esto?</b> Para que el controlador NodeMCU no esté intentando enviar información a través del puerto USB, ya que no está conectado a ninguna PC y puede provocar errores en su funcionamiento.
</p>

Si lograste hacerlo, <b>¡FELICITACIONES!</b> Y si tenes algún tipo de problema, consulta o duda, puedes escribirme por Twitter (<b><a href="http://twitter.com/bernapastorini">@bernapastorini</a></b>), con gusto te voy a dar una mano.
</html>