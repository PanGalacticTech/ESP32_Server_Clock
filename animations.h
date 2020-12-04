

// Animations
void animateSpace(uint32_t animationDelay = 300 ) {

  for (int j = 6; j > 0 ; j--) {


    countdownClock.setDigit(countdownClock.S, 6 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
    countdownClock.setDigit(countdownClock.p, 5 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
    countdownClock.setDigit(countdownClock.A, 4 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
    countdownClock.setDigit(countdownClock.C, 3 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
    countdownClock.setDigit(countdownClock.E, 2 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
    countdownClock.setDigit(countdownClock.blank, 1 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)

    Serial.printf("Set Digit %i 8" , j);
    Serial.println("");
    FastLED.show();
    delay(animationDelay);
  }
}



void flashSpace(uint32_t animationDelay = 100, uint32_t holdText = 500) {
  countdownClock.setDigit(countdownClock.S, 5, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
  FastLED.show();
  delay(animationDelay);
  countdownClock.setDigit(countdownClock.p, 4, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
  FastLED.show();
  delay(animationDelay);
  countdownClock.setDigit(countdownClock.A, 3, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
  FastLED.show();
  delay(animationDelay);
  countdownClock.setDigit(countdownClock.C, 2, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
  FastLED.show();
  delay(animationDelay);
  countdownClock.setDigit(countdownClock.E, 1, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
  FastLED.show();
  delay(animationDelay);
  delay(holdText);
}


void flashFrom(uint32_t animationDelay = 100, uint32_t holdText = 500) {

  countdownClock.setDigit(countdownClock.F, 4, 255, 255, 255);
  FastLED.show();
  delay(animationDelay);
  countdownClock.setDigit(countdownClock.r, 3, 255, 255, 255);
  FastLED.show();
  delay(animationDelay);
  countdownClock.setDigit(countdownClock.o, 2, 255, 255, 255);
  FastLED.show();
  delay(animationDelay);
  countdownClock.setDigit(countdownClock.n, 1, 255, 255, 255);
  countdownClock.setDigit(countdownClock.n, 0, 255, 255, 255);
  FastLED.show();
  delay(animationDelay);
  delay(holdText);
}



void flashTo(uint32_t holdText = 500) {
  countdownClock.setDigit(countdownClock.t, 5, 255, 255, 255);
  countdownClock.setDigit(countdownClock.o, 4, 255, 255, 255);
  FastLED.show();
  delay(holdText);
}




void animateScotland(uint32_t animationDelay = 500, uint32_t holdText = 500) {

  for (int j = 9; j > 0 ; j--) {

    if (j > 3) {
      countdownClock.setDigit(countdownClock.S, 9 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
      countdownClock.setDigit(countdownClock.c, 8 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
      countdownClock.setDigit(countdownClock.o, 7 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
      countdownClock.setDigit(countdownClock.t, 6 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
      countdownClock.setDigit(countdownClock.L, 5 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
      countdownClock.setDigit(countdownClock.A, 4 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
    } else {
      countdownClock.setDigit(countdownClock.t, 6 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
      countdownClock.setDigit(countdownClock.L, 5 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
      countdownClock.setDigit(countdownClock.A, 4 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
      countdownClock.setDigit(countdownClock.n, 3 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
      countdownClock.setDigit(countdownClock.d, 2 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
      countdownClock.setDigit(countdownClock.blank, 1 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
    }

    Serial.printf("Set Digit %i 8" , j);
    Serial.println("");
    FastLED.show();
    delay(animationDelay);
  }
  delay(holdText);
}
