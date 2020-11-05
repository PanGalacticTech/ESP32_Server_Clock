/*********
  ESP32 SAD Lamp Controller

  Use a web server
  accessed over
  local network to
  control a relay.


  Declan Heard
  31/08/2020
*********/

// Load Wi-Fi library
#include <WiFi.h>




// Include Time Libary
#include "time.h"

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 0;
const int   daylightOffset_sec = 3600;


// Load other Librarys
//#include <buttonObject.h>
#include <autoDelay.h>
#include "globals.h"

// Outputs

#include "wifi_Utilities.h"
#include "dataParsing.h"
#include "CSS.h"
#include "htmlObjects.h"





autoDelay timePrintDelay;

autoDelay testPrintDelay;












//--------------------------------------------Setup---------------------------------------
void setup() {

  Serial.begin(115200);



  delay(100);

  setup_accessPoint();   //only set up to default IP at the moment 192.168.4.1

//  connectWifi_staticIP();

  delay(500);

  /*
    // Init and get the time
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    delay(100);
    printLocalTime();

  */



}
//------------------------------------^^^^--------Setup---------------------------------------



//--------------------------------------------Main Loop---------------------------------------

void loop() {

  serverLoop();



  if (timePrintDelay.millisDelay(1000)) {
   // testTime();
  }
}
//----------------------------------------^^^----Main Loop-------------------------------------



//
//--
