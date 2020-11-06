/*
   Routeins for data parsing and switch cases


*/

#include <WiFi.h>

//------------------------------------------------GPIO Control and string parsing----------------------------
// turns the GPIOs on and off:

void GPIOcontrol() {

  if (header.indexOf("GET /25/off") >= 0) {
    Serial.println("GPIO 25 off");
    // sadLampState = "off";

    modeChange = true;
  } else if (header.indexOf("GET /25/on") >= 0) {
    Serial.println("GPIO 25 on");
    //  sadLampState= "on";

    //   modeChange = true;
  }
}
//------------------------------------------^^^-----GPIO Control-------------------------

bool genericBoolcontrol(String headerValue) {

  if (header.indexOf("GET /" + headerValue + "/off") >= 0) {
    Serial.print(headerValue);
    Serial.println(": Bool False");
    return false;
    // sadLampState = "off";

    // modeChange = true;
  } else if (header.indexOf("GET /" + headerValue + "/on") >= 0) {
    Serial.print(headerValue);
    Serial.println(": Bool True");
    return true;
    //  sadLampState= "on";

    //   modeChange = true;
  } else {
    return false;   // Not ideal if used as a toggle but should work for our purposes now
  }
}

bool toggleBoolcontrol(String headerValue) {

  if (header.indexOf("GET /" + headerValue + "/off") >= 0) {
    Serial.print(headerValue);
    Serial.println(": Bool False");

    toggleCountdown = "off";
    simpleClock.countdownStop();
    modeChange = true;
    return false;
  } else if (header.indexOf("GET /" + headerValue + "/on") >= 0) {
    Serial.print(headerValue);
    Serial.println(": Bool True");

    toggleCountdown = "on";
    simpleClock.countdownStart();
    modeChange = true;
    return true;
  } else {
    return false;   // Not ideal if used as a toggle but should work for our purposes now
  }
}





// Uses values returned from genericBOOL header to control the state of the clock
void startPausecountdown() {
  if (!simpleClock.runCountdown) {      // countdown state is off
    countdownRun = "off";                      // These variables control the style applied to buttons
    countdownPause = "on";
    if (triggerCountdown) {                 // if trigger flag has been set
      simpleClock.countdownStart();           // start the countdown
    }
  } else {                                    // If countdown is running
    countdownRun = "on";
    countdownPause = "off";
    if (triggerCountdownPause) {                 // if trigger pause flag has been set
      simpleClock.countdownStop();           // pause the countdown
    }
  }
}


//------------------------------------------------String Parsing pwm updates----------------------------


//--------------------- RED LEVEL SORTING--------------------
void pwmDataParse() {                      ////int channelPWM, String     // channelPWM = pass redPWM/greenPWM or bluePWM

  if (header.indexOf("GET /?lampPWM=") >= 0) {                      // If the header contains the command for the red channel

    int stringLength =  header.length() + 1;                      // work out the length of char array needed to hold the String
    // object header.

    char copy[stringLength];                                    /// this is long....like 535 characters long wtf man.
    // it works but damn there has to be a better way
    header.toCharArray(copy, stringLength);                     // copy the String - header. to char copy
    // This data is now indexed and can be sorted.


    int j = 0;                                               // another variable to be used along with i to control indexes
    char u[4];                                              // char array to hold our new brightness value - later use R variable?

    for (int i = 13; i < 16; i++) {                       // Example of copy[] = GET /?redPWM=100 max is 16, start of int is 13
      u[j] = copy[i];
      j++;                                                  // increment j along with for loop
    }


    lampBrightness = atoi( u );                                 // put char array into redPWM value as int.

    Serial.println( lampBrightness);

    BRIGHT  = lampBrightness;                                          // save redPWM value into string object R

    for (int i = 0; i < sizeof(copy); i++) {               // Resets copy buffer maybe unneeded

      copy[i] = (char)0;
    }

    //  if (sadLampState == "on") {                           // set the new LED brightness if the LED is already on

    // TURN LAMP ON HARDER, maybe

    // writePWM(lampBrightness);

    //   } else {

    //  writePWM(lampBrightness);
  }
} //--------------------- RED LEVEL SORTING--------------------
