/* Javascript functions go here
 * 
 * 
 * 
 * 
 */



// New Idea



void javascriptVariables(WiFiClient client){



   client.println(" <p>Live Clock: <span id='live_clock'></span></p>");

  
}






// This updater requires data to be saved in an XML document called "liveClock" with the data laid out like

// {"live_clock": T- 00:20:10}

// This may be possible with tinyxm12.h library
/*
void javascriptXMLUpdater(){

<script>
    requestData(); // get intial data straight away 
  
    // request data updates every 5000 milliseconds
    setInterval(requestData, 1000);

    function requestData() {

      var xhr = new XMLHttpRequest();
      xhr.open('GET', 'liveClock');

      xhr.onload = function() {
        if (xhr.status === 200) {

          if (xhr.responseText) { // if the returned data is not null, update the values

            var data = JSON.parse(xhr.responseText);

            document.getElementById("live_clock").innerText = data.live_clock;
         

          } else { // a problem occurred

            document.getElementById("live_clock").innerText = "?";
           
          }
        } else {
          console.log('Request failed.  Returned status of ' + xhr.status);

          document.getElementById("live_clock").innerText = "00:00:00";
     

        }
      };
      
      xhr.send();
    }

</script>
  
}
*/


















 // Old didnt work stuff
// Live Clock - Broken atm

/*
void javaScript_timeHead(WiFiClient client) {

  // This Code goes in Head //
  client.println("<script>");
  client.println("function startTime() {");

  client.println("var time = simpleClock.countdown_clock_string");

  client.println("  document.getElementById('webTime').innerHTML =");
  client.println(" time;");
  client.println("  var t = setTimeout(startTime, 500);");
  client.println("}");


  client.println("</script>");
  // </head>
}


void javascript_timeBody(WiFiClient client) {
  // Code for body //
  client.println("<body onload=\"startTime()\">");

  client.println("<div id=\"webTime\"></div>");



}

*/
