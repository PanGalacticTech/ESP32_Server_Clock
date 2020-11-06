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




//------------------------------------------------String Parsing Numerical updates----------------------------


//---------------------  Numerical Data Extraction ----

int32_t numericalDataParse(String headerText, int32_t origionalValue) {


  if (header.indexOf("GET /?" + headerText + "=") >= 0) {                  // If the header contains the passed header text






    int stringLength =  header.length() + 1;                      // work out the length of char array needed to hold the String
    // object header.

    char copy[stringLength];                                    /// this is long....like 535 characters long wtf man.
    // it works but damn there has to be a better way
    header.toCharArray(copy, stringLength);                     // copy the String - header. to char copy
    // This data is now indexed and can be sorted.

    /*
        int j = 0;                                               // another variable to be used along with i to control indexes
        char u[4];                                              // char array to hold our new numerical value

        for (int i = 13; i < 16; i++) {                       // Example of copy[] = GET /?redPWM=100 max is 16, start of int is 13
          u[j] = copy[i];
          j++;                                                  // increment j along with for loop
        }
    */
    /*
        char u[4];
        int pointer;

        for (int i = 0; i < 20; i++) {               // find the location of the equals sign
          if (&copy[i] == "=") {
            pointer = i + 1;                           // save the location of the first integer value
            Serial.print("Pointer: ");
            Serial.println(pointer);
          }
        }

        int y;
        for (int i = pointer; i < (pointer + 3); i++) {      // copy the string from the pointer to pointer+3
          u[y] = copy[i];
          Serial.println(u[y]);
          y++;
        }

      //   Serial.println(u);
    */

    char *pch;

    pch = strchr(copy, '=');
    // while (pch != NULL) {
      Serial.printf("%d\n", pch - copy + 1);
    //  pch = strchr(pch + 1, '=');
    // }

int pointer = atoi(pch);

Serial.println(pointer);
    

    char u[4];
    int y = 0;
    for (int i = &pch; i < (&pch + 3); i++) {      // copy the string from the pointer to pointer+3
     u[y] = copy[i];
      Serial.println(u[y]);
     y++;
    }




    // int32_t extractedData = atoi( u );                                 // put char array into extracted data value as int.





    Serial.print("Extracted Numerical Value: ");
    //  Serial.println(extractedData);



    for (int i = 0; i < sizeof(copy); i++) {               // Resets copy buffer maybe unneeded

      copy[i] = (char)0;
    }

    // return extractedData;
    return 0;
  } else {
    return origionalValue;
  }

}


// Uses Numerical data parse to update the master clock

void updateClock() {


  simpleClock.countdown_master.h = numericalDataParse("hours", simpleClock.countdown_master.h);

  simpleClock.countdown_master.m = numericalDataParse("mins", simpleClock.countdown_master.m);

  simpleClock.countdown_master.s = numericalDataParse("secs", simpleClock.countdown_master.s);


}
