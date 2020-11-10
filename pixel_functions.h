


void light_dots(bool turn_On){

  
}


void light_t(bool turn_On){

  
}



void light_plusminus(bool light_plus){   // Could be pass bool as argument to light the + sign, or just use global variables

if (countdownClock.tminus){
// Light up Just the - Symbol  
} else {
  // Light up the Plus & the Minus symbol
}
  
}




// function to take a number and return the most significant figure

int32_t return_most_sf(int32_t input){
  if (input < 10){
    return 0;
  } else {
    input = input / 10;
    return input;
  }
}



// function to take a number and return the least significant figure


int32_t return_least_sf(int32_t input){

char calc[3];
 if (input < 10){
  return input;
 } else {
 return (input % 10);
 }  
}


// Animations
void printArora(uint32_t animationDelay = 500 ) {


  for (int j = 6; j > 0 ; j--) {


    countdownClock.setDigit(countdownClock.A, 6 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
    countdownClock.setDigit(countdownClock.r, 5 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
    countdownClock.setDigit(countdownClock.o, 4 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
    countdownClock.setDigit(countdownClock.r, 3 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
    countdownClock.setDigit(countdownClock.A, 2 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
    countdownClock.setDigit(countdownClock.blank, 1 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)

    Serial.printf("Set Digit %i 8" , j);
    Serial.println("");
    FastLED.show();
    delay(animationDelay);
  }


}


void displaySetup(int8_t setupBrightness){
 Serial.println("Clock Initializing...");

  countdownClock.sevenSegSetup(setupBrightness);

  Serial.println("Seven Seg Setup");
  

  CURRENT_COLOUR = countdownClock.pureWhite;

  
  // Preset the starting LED colour, can be changed later in program
  delay(100);
  countdownClock.setDigitsBlank();   // Set all digits to blank
  delay (200);
  FastLED.show();
  Serial.println("||    ~~Set Digits Blank~~    ||");


  delay(500);

  for (int j = 0; j < 6 ; j++) {
    countdownClock.setDigit(countdownClock.alldigits[8], j, CURRENT_COLOUR.r, CURRENT_COLOUR.g, CURRENT_COLOUR.b);  // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
    Serial.printf("Set Digit %i 8" , j);
    Serial.println("");
    FastLED.show();
    delay(100);
  }



  delay(1000);
  countdownClock.setDigitsBlank();   // Set all digits to blank
  delay(100);
  FastLED.show();
  Serial.println("Setting Digits Blank");
  delay(500);

  //countdownClock.setAllDigitsX(countdownClock.H, 255, 255, 255);

  printArora();
  delay(100);
  FastLED.show();
  Serial.println("Setup Complete, Clock Starting:");

  delay(2000);
  countdownClock.setDigitsBlank();   // Set all digits to blank
  delay(100);
  FastLED.show();

}
