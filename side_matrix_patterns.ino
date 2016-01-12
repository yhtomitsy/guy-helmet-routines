void crissCross(){
  digitalWrite (LED_STRIP,HIGH); // turn on side matrix led strip
  // turn first two side matrix neopixels on
  neolight(0,sideMatrixStrip.Color(20,0,0));
  
  int j = 0;
  while (j < 50){
    for (int i = 0; i < 8; i+=2) {
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, lines[i]);
      shiftOut(dataPin, clockPin, lines[i+1]);
      digitalWrite(latchPin, 1);
      delay(1);
    }
    j++;
  }
  delay(1);
  // turn next two side matrix neopixels on
  neolight(2,sideMatrixStrip.Color(20,20,0));
  j = 0;
  while (j < 50){
    for (int i = 8; i < 16; i+=2) {
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, lines[i]);
      shiftOut(dataPin, clockPin, lines[i+1]);
      digitalWrite(latchPin, 1);
      delay(1);
    }
    j++;
  }
  delay(1);
  // turn next two side matrix neopixels on
  neolight(4,sideMatrixStrip.Color(0,20,0));
  j = 0;
  while (j < 100){
    for (int i = 16; i < 20; i+=2) {
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, lines[i]);
      shiftOut(dataPin, clockPin, lines[i+1]);
      digitalWrite(latchPin, 1);
      delay(1);
    }
    j++;
  }
  // turn next two side matrix neopixels on
  neolight(6,sideMatrixStrip.Color(0,20,20));
  j = 0;
  while (j < 50){
    for (int i = 8; i < 16; i+=2) {
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, lines[i]);
      shiftOut(dataPin, clockPin, lines[i+1]);
      digitalWrite(latchPin, 1);
      delay(1);
    }
    j++;
  }
  delay(1);
  digitalWrite (LED_STRIP,LOW); // turn on side matrix led strip
  // turn last two side matrix neopixels on
  neolight(8,sideMatrixStrip.Color(0,0,20));
}

void box(){
  colorWipe(sideMatrixStrip.Color(20,0,0));
  digitalWrite (LED_STRIP,HIGH); // turn on side matrix led strip
  int j = 0;
  while (j < 20){
    for (int i = 0; i < 8; i+=2) {
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, boxSides[i]);
      shiftOut(dataPin, clockPin, boxSides[i+1]);
      digitalWrite(latchPin, 1);
      delay(1);
    }
    j++;
  }
  delay(1);
  colorWipe(sideMatrixStrip.Color(0,20,0));
  digitalWrite (LED_STRIP,LOW); // turn on side matrix led strip
  j = 0;
  while (j < 20){
    for (int i = 8; i < 16; i+=2) {
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, boxSides[i]);
      shiftOut(dataPin, clockPin, boxSides[i+1]);
      digitalWrite(latchPin, 1);
      delay(1);
    }
    j++;
  }
  delay(1);
  colorWipe(sideMatrixStrip.Color(0,0,20));
  digitalWrite (LED_STRIP,HIGH); // turn on side matrix led strip
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, boxSides[16]);
  shiftOut(dataPin, clockPin, boxSides[17]);
  digitalWrite(latchPin, 1);
  delay(100);
}

void laserflash(){
  digitalWrite (LED_STRIP,HIGH); // turn on side matrix led strip
  digitalWrite(MR, HIGH);
  uint8_t j = 0;
  while(j < 20){
    for (int i = 0; i < 8; i++) {
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, y2[i]);
      shiftOut(dataPin, clockPin, x2[i]);
      digitalWrite(latchPin, 1);
      delay(1);
    }
  j++;
    colorWipe(Wheel(j*12,4,12));
  }
  digitalWrite(MR, LOW);
  delay(100);
}

void laserLights(){
  digitalWrite (LED_STRIP,HIGH); // turn on side matrix led strip
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, B00000001);
  shiftOut(dataPin, clockPin, x);
  digitalWrite(latchPin, 1);
  neoLaser(0, sideMatrixStrip.Color(0,0,20));
  delay(100);
  neoLaser(3, sideMatrixStrip.Color(0,0,20));
  uint8_t j = 0;
  while(j < 20){
    for (int i = 0; i < 6; i++) {
      digitalWrite(latchPin, 0);
      shiftOut(dataPin, clockPin, y[i]);
      shiftOut(dataPin, clockPin, x1[i]);
      digitalWrite(latchPin, 1);
      delay(1);
    }
    j++;
  }
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, B00111111);
  shiftOut(dataPin, clockPin, B00000001);
  digitalWrite(latchPin, 1);
  neoLaser(5, sideMatrixStrip.Color(0,0,20));
  delay(100);
}

void sideways(){
  for (int i = 0; i < 6; i++) {
    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, y[i]);
    shiftOut(dataPin, clockPin, x);
    digitalWrite(latchPin, 1);
    sideMatrixStrip.setPixelColor(i, sideMatrixStrip.Color(20,20,0));
    sideMatrixStrip.show();
    digitalWrite (LED_STRIP,HIGH); // turn on side matrix led strip
    delay(50);
    digitalWrite (LED_STRIP,LOW); // turn off side matrix led strip
  }
  for (int i = 5; i >= 0; i--) {
    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, y[i]);
    shiftOut(dataPin, clockPin, x);
    digitalWrite(latchPin, 1);
    sideMatrixStrip.setPixelColor(i, sideMatrixStrip.Color(0,0,0));
    sideMatrixStrip.show();
    digitalWrite (LED_STRIP,HIGH); // turn on side matrix led strip
    delay(50);
    digitalWrite (LED_STRIP,LOW); // turn off side matrix led strip
  }
}
void updown(){
  digitalWrite (LED_STRIP,HIGH); // turn on side matrix led strip
  for (int i = 0; i < 8; i++) {
    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, x);
    shiftOut(dataPin, clockPin, y[i]);
    digitalWrite(latchPin, 1);
    colorWipe(Wheel(i*32,4,12)); // set neopixel strip color
    delay(50);
  }
  digitalWrite (LED_STRIP,LOW); // turn on side matrix led strip
  for (int i = 7; i >= 0; i--) {
    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, x);
    shiftOut(dataPin, clockPin, y[i]);
    digitalWrite(latchPin, 1);
    colorWipe(Wheel(256 - i*32,4,12)); // set neopixel strip color
    delay(50);
  }
}

void neolight(uint8_t x, uint32_t color){
  for(uint8_t i = x; i < 2+x; i++){
    sideMatrixStrip.setPixelColor(i, color);
    if(i > 1)sideMatrixStrip.setPixelColor(i-2, sideMatrixStrip.Color(0,0,0));
    else{
      sideMatrixStrip.setPixelColor(7, sideMatrixStrip.Color(0,0,0));
      sideMatrixStrip.setPixelColor(6, sideMatrixStrip.Color(0,0,0));
    }
  }
  sideMatrixStrip.show();
}

// Fill the neopixel strip with the same color at once
void colorWipe(uint32_t color) {
  for(uint16_t i=0; i<sideMatrixStrip.numPixels(); i++) {
      sideMatrixStrip.setPixelColor(i, color);
  }
  sideMatrixStrip.show();
}

//laser neopixel
void neoLaser(uint8_t x, uint32_t color){
  for(uint16_t i=0; i<sideMatrixStrip.numPixels(); i++) {
      sideMatrixStrip.setPixelColor(i, sideMatrixStrip.Color(0,0,0));
  }
  for(uint8_t i = x; i < 2+x; i++){
    sideMatrixStrip.setPixelColor(i, color);
    if(i == 1 || i == 6)sideMatrixStrip.setPixelColor(i+1, color);
  }
  sideMatrixStrip.show();
}

