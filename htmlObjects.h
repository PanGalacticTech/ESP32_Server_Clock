/* Place to Store HTML objects that can be called from a function




*/

#include <WiFi.h>


// Print the text box for a number input
void numberInputBox(WiFiClient client, String boxLabel, String boxName, String currentValue ) {

  client.println(boxLabel + ": <span id=\"" + boxName + "\"></span> </br>");
  client.println("<div class= \"centerBox\">");
  client.println("<div class= \"flexBox\">");   // centered box
  client.println("<form action='/' class=\"inputForm\" method=get >"); //uses IP/port of web page
  client.println("<input type=\"number\" name=\"" + boxName + "\" min =\"0\" max =\"99\" value= " + currentValue + "  style=\"width: 3em\"><br>");

  client.println("</br> <input type=\"submit\" value=\"Apply\">");
  client.println("</form> </div> </br>");
  //client.println("</div>");

}






void genericButton(WiFiClient client, String titleText, String buttonONText,  String currentState, String returnString) {

  client.println("<p>" + titleText + currentState + "</p>");

  if (currentState == "on") {
    //    client.println("<p><a href=\"/" + returnString + "/off\"><button class=\"button button2\"></button></a></p>");
  } else {
    client.println("<p><a href=\"/" + returnString + "/on\"><button class=\"button\">" + buttonONText + "</button></a></p>");
  }
}


void toggleButton(WiFiClient client, String titleText, String buttonONtext, String buttonOFFtext, String currentState, String returnString) {

  client.println("<p>" + titleText + currentState + "</p>");

  if (currentState == "on") {
    client.println("<p><a href=\"/" + returnString + "/off\"><button class=\"button button2\">" + buttonOFFtext + "</button></a></p>");
  } else {
    client.println("<p><a href=\"/" + returnString + "/on\"><button class=\"button\">" + buttonONtext + "</button></a></p>");
  }
}




String countDown_Time = "00:01:32";

void javaScript_timeHead(WiFiClient client) {

  // This Code goes in Head //
  client.println("<script>");
  client.println("function startTime() {");
  client.println("var today = new Date();");
  client.println("var h = today.getHours();");
  client.println("  var m = today.getMinutes();");
  client.println("  var s = today.getSeconds();");
  client.println("  m = checkTime(m);");
  client.println("  s = checkTime(s);");
  client.println("  document.getElementById('webTime').innerHTML =");
  client.println(" h + "":"" + m + \":\" + s;");
  client.println("  var t = setTimeout(startTime, 500);");
  client.println("}");
  client.println("function checkTime(i) {");
  client.println("  if (i < 10) {i = \"0\" + i};  // add zero in front of numbers < 10");
  client.println("  return i;");
  client.println("}");
  client.println("</script>");
  // </head>
}


void javascript_timeBody(WiFiClient client) {
  // Code for body //
  client.println("<body onload=\"startTime()\">");

  client.println("<div id=\"webTime\"></div>");



}





void pageContent(WiFiClient client) {    // Displays All the Content Displayed to Client


  numberInputBox(client, "Hours", "hours", H);

  numberInputBox(client, "Minutes", "mins", M);

  numberInputBox(client, "Seconds", "secs", S);

  //  genericButton(client, "Start Countdown | Current State = ", "Start", countdownRun, "start_countdown");

  //  genericButton(client, "Pause Countdown | Current State = ", "Pause", countdownPause, "pause_countdown");
  // javascript_timeBody(client); Does not work

  toggleButton(client, "Toggle Countdown | Current State = ", "Start", "Pause", toggleCountdown, "toggle_countdown");



}






void httpResponse(WiFiClient client) {
}





void htmlPageHeading(WiFiClient client) {
  // Display the HTML web page
  client.println("<!DOCTYPE html><html>");
  client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
  client.println("<link rel=\"icon\" href=\"data:,\">");

  //javaScript_timeHead(client);  << does not seem to work

  // Head closed by CSS Method
}





void serverLoop() {
  //------------------------ Client HTTP Requests-----------------------------

  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      //   Serial.println("While client.connected");
      if (client.available()) {             // if there's bytes to read from the client,
        //   Serial.println("if client.available");
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;                        // add that character to the header String
        //  Serial.print(c); //see what was captured   // ADDED LINE << Lets see wtf goes on here.

        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.

          // that's the end of the client HTTP request, so send a response:



          //--------------------------------------------AP--HTTP Response--------------------
          //--------------------------------------------AP--HTTP Response--------------------
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            //--------------------------------^^^^---- HTTP Requests/Response------------------------------------
            // This function returns a HTTP respone to the client
            //--------------------------------^^^^---- HTTP Requests/Response------------------------------------




            //------------------------------------------------GPIO Control and string parsing----------------------------
            // turns the GPIOs on and off:

            //  GPIOcontrol();       // Switch case for HTTP requests containing GPIO on/off commands

            //  triggerCountdown = genericBoolcontrol("start_countdown");   //Bool header for start countdown header
            //  Serial.print("Trigger Countdown:");
            //  Serial.println(triggerCountdown);
            //  triggerCountdownPause = genericBoolcontrol("pause_countdown");
            // Serial.print("Trigger Pause:");
            // Serial.println(triggerCountdownPause);

            //  startPausecountdown(); // Controls the state of the clock based on bools returned above

            toggleBoolcontrol("toggle_countdown");

            //------------------------------------------------String Parsing pwm updates----------------------------

            pwmDataParse();          // Sorts incoming HTTP requests containing PWM updates





            //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~# HTTP WEB PAGE GOES HERE #~~~~~~~~~~~~~~~~~~


            //----------------------------------------------------HTML Header---------------------------------------------------------------
            htmlPageHeading(client);
            //---------------------------------------------------------CSS--------------------------------------------------------------
            // CSS to style the on/off buttons
            callCSS(client);  //  function calls CSS sheet    // Must be passed wifi client.


            //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~## Web Page CONTENT ##~~~~~~~~~~~~~~~~~~~

            //-------- Web Page Heading-----------------------------------------------------------------------
            client.println("<body><h1>Skyrora Countdown Clock</h1>");



            //-------------------------------------------------------------Display Buttons-------------------------

            pageContent(client);

            //   displayDayTimes(client);     // New Funtion added to display each weekday and the time the clock is set to.


            // end the HTML body
            client.println("</body></html>");

            // The HTTP response ends with another blank line
            client.println();
            //added line below to force close:
            //  client.stop();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }

    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");


  }

}


void sliderInputForm(WiFiClient client) {

  /*
              client.println("<p>Red - GPIO 25 - State " + R + "</p>");        //output25State replaced by red PWM might not work coz its an int not a char
              // If the output25State is off, it displays the ON button
              if (output25State == "off") {
                client.println("<p><a href=\"/25/on\"><button class=\"button button2\">OFF</button></a></p>");
              } else {
                client.println("<p><a href=\"/25/off\"><button class=\"button\">ON</button></a></p>");
              }


              // Print the text box for PWM value;   // HIGHLY EXPEREMENTAL
              client.println("Red Level: <span id=\"red\"></span> </br>");

              client.println(" <div class= \"centerBox\">");

              client.println("<form action='/' class=\"inputForm\" method=get >"); //uses IP/port of web page

              client.println(" <div class= \"flexBox\">");   // centered box

              client.println(" <div class= \"marginBox\"> </div>");  //

              client.println(" <div class= \"leftBox\">");   // div box for input slider/form

              //this line for text box input
              // client.println("<input type=\"number\" name=\"redPWM\" min =\"0\" max =\"255\" value= " + R + "  style=\"width: 3em\"><br>");

              //these lines for slider input;
              client.println("<div class=\"slidecontainer\">");
              client.println("<input type=\"range\" name=\"redPWM\" min =\"0\" max =\"255\" value= " + R + " class=\"slider\"");
              client.println("id=\"redRange\"><br>");   // id= "myRange used for javascript (style=\"width: 3em\") remioved
              client.println("</div>");    // close slider box
              client.println("</div>");   // close left box

              client.println(" <div class= \"rightBox\">");   // div box for apply button

              client.println("<input type=\"submit\" value=\"Apply\">");   ///</br>  removed from start of box
              client.println("</div>");   // close right box
                client.println("</div>");   // close flex box

              client.println("</form>");   // close the form
              client.println("</div>");     // close the center box


              // print javascript object;
              client.println("<script> var slider = document.getElementById(\"redRange\");");
              client.println("var output = document.getElementById(\"red\");");
              client.println("output.innerHTML = slider.value;");

              client.println("slider.oninput = function() {output.innerHTML = this.value;}");
              client.println("</script>");
  */
}























//char dayNames[][10] = {"Monday", "Tuseday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

/*
  void displayDayTimes(WiFiClient client) {

  client.println(" <div class= \"centerBox\">");
  client.println(" <div class= \"flexBox\">");   // centered box

  client.println(" <div class= \"leftBox\">");   // div box for input slider/form

  for (int i = 0; i < 7; i++) {

    //   String D = dayNames[i];
    //  String T =  turnOnTimes[i];
    T.remove(0 , 1);   // Remove the 2 characters at the start that are just used to hold the number of the weekday.

    // Put display here with each weekday name and the time the switch is timed on at
    client.println("<p>"  + D +  " Wakeup Time: " + T + "</p>");
  }
  client.println("</div>");    // close Left box
  client.println("</div>");   // close Flex box
  client.println("</div>");     // close the center box
  }
*/
