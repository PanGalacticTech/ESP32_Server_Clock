/*********
  ESP32 Web Server Clock Controller

  Use a web server
  accessed over
  local network to
  control a clock


  Declan Heard
  06/11/2020
*********/

// Load Wi-Fi library
#include <WiFi.h>



// Load other Librarys
//#include <buttonObject.h>

#include <timeObject.h>

timeObject simpleClock;

#define INITAL_HOURS 1
#define INITAL_MINS 5
#define INITAL_SECS 32

#define FORCE_PRINT_CLOCK false


#include <autoDelay.h>
#include "globals.h"

// Outputs

#include "wifi_Utilities.h"
#include "dataParsing.h"
#include "CSS.h"
#include "htmlObjects.h"
#include "html_webpage.h"





autoDelay timePrintDelay;

autoDelay testPrintDelay;












//--------------------------------------------Setup---------------------------------------
void setup() {

  Serial.begin(115200);
  delay(100);

 // setup_accessPoint();   //only set up to default IP at the moment 192.168.4.1
   connectWifi_staticIP();

  delay(500);
  simpleClock.countdownSetup(INITAL_HOURS, INITAL_MINS, INITAL_SECS);

  // simpleClock.countdownStart();   // for testing, else we want countdown paused untill triggered


}




//--------------------------------------------Main Loop---------------------------------------

void loop() {

  serverLoop();

  // Call in every loop
  simpleClock.countdownLoop();


  

  // Prints the clock every time seconds change.
  //Can be forced to print by passing true as an argument
  simpleClock.countdownPrint(FORCE_PRINT_CLOCK);

}




// countdown clock master variables:

//simpleClock.countdown_master;
//simpleClock.countdown_master.h;
//simpleClock.countdown_master.m;
///simpleClock.countdown_master.s;
