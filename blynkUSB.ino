/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest
  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.
    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app
  Blynk library is licensed under MIT license
  This example code is in public domain.
 *************************************************************
  =>
  =>          USB HOWTO: http://tiny.cc/BlynkUSB
  =>
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT DebugSerial


// You could use a spare Hardware Serial on boards that have it (like Mega)
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3); // RX, TX

#include <BlynkSimpleStream.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "gfi66qxzIs5SF5FnyRS0ajp6xKaLhD3m";
WidgetLED led1(V1); // pin virtual del led en blynk
BlynkTimer timer; // tiempo que se toma para refrescar la leida del puerto


 void blinkLedWidget() // funcion para leer el puerto por tiempo timer
{
  if (!digitalRead(3)) {
    led1.off(); // prende el led de blynk
    
  } else {
    led1.on(); // apaga el led de blynk
    
  }
}
void setup()
{
 pinMode(3,INPUT_PULLUP);// se configura el pin 3 como entrada cun pull up
  // Blynk will work through Serial
  // Do not read or write this serial manually in your sketch
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
  timer.setInterval(1000L, blinkLedWidget); // tiempo cada segundo y la funcion que llama
}

void loop()
{
  Blynk.run();
  timer.run();
}
