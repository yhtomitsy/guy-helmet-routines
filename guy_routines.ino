#include <Adafruit_NeoPixel.h>

#define DATA_PIN1 8 // pin connected to fromt matrix
#define DATA_PIN2 6 // pin connected to front matrix
#define DATA_PIN3 3 // pin connected to front matrix
#define FANS 4 // pin connected to fans
#define EARS_BARS 7 // pin connected to ears and bars
#define latchPin 13  //Pin connected to ST_CP of 74HC595
#define clockPin  12  //Pin connected to SH_CP of 74HC595
#define dataPin  11  //Pin connected to DS of 74HC595
#define MR  10  //Pin connected to MR of 74HC595
#define DATA_SM  9 // pin connected to data pin of side matrix neopixels
#define LED_STRIP 5 // pin connected to led strip on side matrix

uint8_t currentBar = 0;
uint8_t bars[] = {16,21,26,31,36,41,46,51}; // contains address of first led in each bar

// front matrix neopixel strips
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(1, DATA_PIN1, NEO_RGB + NEO_KHZ800); // 196
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(1, DATA_PIN2, NEO_RGB + NEO_KHZ800); // 182
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(1, DATA_PIN3, NEO_RGB + NEO_KHZ800); // 182

//side matrix neopixel strip
Adafruit_NeoPixel sideMatrixStrip = Adafruit_NeoPixel(8, DATA_SM, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel earBarsStrip = Adafruit_NeoPixel(56, EARS_BARS, NEO_RGB + NEO_KHZ800);

uint32_t barColor = earBarsStrip.Color(20,20,20); //color for bars

// SIDE MATRIX PATTERN PLOTTING POINTS
// sideways and upward points
byte y[8]= {
  B00000001,
  B00000010,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B01000000,
  B10000000
};
byte x = B11111111;

// laser lights
int x1[8]= {
  B00000001,
  B00000010,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B01000000,
  B10000000
};

//laser flash
int y2[8]= {
  B00000001,
  B00000011,
  B00000101,
  B00001001,
  B00010001,
  B00100001,
  B01000001,
  B10000001
};
int x2[8]= {
  B00000001,
  B00000011,
  B00000101,
  B00001001,
  B00010001,
  B00100001,
  B01000001,
  B10000001
};

//box
int boxSides[] = {
  B00000001, //outer square
  B11111111,
  B11111111,
  B00000001,
  B00100000,
  B11111111,
  B11111111,
  B10000000,
  B00000010, // middle square
  B01111110,
  B00011110,
  B00000010,
  B00010000,
  B01111110,
  B00011110,
  B01000000,
  B00001100, // innermost square
  B00111100
};

//crisscross
int lines[] = {
  B00000001, //outer square
  B11111111,
  B11111111,
  B00000001,
  B00100000,
  B11111111,
  B11111111,
  B10000000,
  B00000010, // middle square
  B11111111,
  B00111111,
  B00000010,
  B00010000,
  B11111111,
  B00111111,
  B01000000,
  B00001100, // innermost square
  B11111111,
  B00111111,
  B00011000
};

void setup() {
  //
  // Initialize all front matrix pixels
  strip1.begin();
  strip2.begin();
  strip3.begin();
  strip1.show(); 
  strip2.show();
  strip3.show();
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(MR, OUTPUT);
  digitalWrite(MR, HIGH);
  //set side matrix led strip pin to output and set it low
  pinMode(LED_STRIP, OUTPUT);
  digitalWrite (LED_STRIP,LOW);
  //initialize side matrix neopixel strip
  sideMatrixStrip.begin();
  sideMatrixStrip.show();
  //initialize ears and bars leds
  earBarsStrip.begin();
  earBarsStrip.show();

  //set timer1 interrupt for displaying bars
  cli();//stop interrupts
  //set timer1 interrupt at 1Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 7816;// = (16*10^6) / (0.5*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS10 and CS12 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei();//allow interrupts
  
}

void loop() {
  smileFrown();
  //goofy();
  //OKcombined();
  //sideways();
  //updown();
  //box();
  //crissCross();
  //laserLights();
  //laserflash();
}

ISR(TIMER1_COMPA_vect){//timer1 interrupt 1Hz 
  barControl(bars[currentBar], barColor);
  if(currentBar == 7){
    currentBar = 0;
    if (barColor == earBarsStrip.Color(0,0,0))barColor = earBarsStrip.Color(20,20,20);
    else barColor = earBarsStrip.Color(0,0,0);
  }
  else currentBar++;
}

void goofy(){
  goofyFace1(30,12);
  delay(100);
  goofyFace2(30,12);
  delay(1000);
  goofyFace3(100,12);
  delay(2000);
  goofyFace1(30,12);
  delay(100);
  goofyFace2(30,12);
  delay(300);
  goofyFace1(30,12);
  delay(100);
  goofyFace2(30,12);
  delay(1000);
  goofyFace3(100,12);
  goofyFace3(100,12);
  delay(2000);
}

void OKcombined(){
  OK(12);
  for(uint8_t i = 0; i < 5; i++){
    colorEars(Wheel(63*i,5,12));
    crissCross();
  }
}

void smileFrown(){
  //Serial.println(currentBar);
  sideMatrixStrip.setPixelColor(6, sideMatrixStrip.Color(0,0,0));
  sideMatrixStrip.setPixelColor(7, sideMatrixStrip.Color(0,0,0));
  colorEars(earBarsStrip.Color(20,20,20));
  smile(30,12);
  for(uint8_t i = 0; i < 5; i++)sideways();
  frown(30,12);
  for(uint8_t i = 0; i < 5; i++)updown();
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos,uint8_t strip,uint8_t br) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   if(strip == 1)return strip1.Color((255 - WheelPos * 3)/br, 0, (WheelPos * 3)/br);
   else if(strip == 2)return strip2.Color((255 - WheelPos * 3)/br, 0, (WheelPos * 3)/br);
   else if(strip == 3)return strip3.Color((255 - WheelPos * 3)/br, 0, (WheelPos * 3)/br);
   else if(strip == 4)return sideMatrixStrip.Color((255 - WheelPos * 3)/br, 0, (WheelPos * 3)/br);
   else if(strip == 5)return earBarsStrip.Color((255 - WheelPos * 3)/br, 0, (WheelPos * 3)/br);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
    if(strip == 1)return strip1.Color(0, (WheelPos * 3)/br, (255 - WheelPos * 3)/br);
    else if(strip == 2)return strip2.Color(0, (WheelPos * 3)/br, (255 - WheelPos * 3)/br);
    else if(strip == 3)return strip3.Color(0, (WheelPos * 3)/br, (255 - WheelPos * 3)/br);
    else if(strip == 4)return sideMatrixStrip.Color(0, (WheelPos * 3)/br, (255 - WheelPos * 3)/br);
    else if(strip == 5)return earBarsStrip.Color(0, (WheelPos * 3)/br, (255 - WheelPos * 3)/br);
  } else {
   WheelPos -= 170;
   if(strip == 1)return strip1.Color((WheelPos * 3)/br, (255 - WheelPos * 3)/br, 0);
   else if(strip == 2)return strip2.Color((WheelPos * 3)/br, (255 - WheelPos * 3)/br, 0);
   else if(strip == 3)return strip3.Color((WheelPos * 3)/br, (255 - WheelPos * 3)/br, 0);
   else if(strip == 4)return sideMatrixStrip.Color((WheelPos * 3)/br, (255 - WheelPos * 3)/br, 0);
   else if(strip == 5)return earBarsStrip.Color((WheelPos * 3)/br, (255 - WheelPos * 3)/br, 0);
  }
}

void clearMatrix(){
  for(uint8_t i = 0; i < strip1.numPixels(); i++){
    strip1.setPixelColor(i, strip1.Color(0,0,0));
    if(i < 182){
      strip2.setPixelColor(i, strip2.Color(0,0,0));
      strip3.setPixelColor(i, strip3.Color(0,0,0));
    }
  }
}

void shiftOut(int myDataPin, int myClockPin, byte myDataOut) {
  // This shifts 8 bits out MSB first, 
  //on the rising edge of the clock,
  //clock idles low

  //internal function setup
  int i=0;
  int pinState;
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  //clear everything out just in case to
  //prepare shift register for bit shifting
  digitalWrite(clockPin, 0);
  digitalWrite(dataPin, 0);

  //for each bit in the byte myDataOut�
  //NOTICE THAT WE ARE COUNTING DOWN in our for loop
  //This means that %00000001 or "1" will go through such
  //that it will be pin Q0 that lights. 
  for (i=7; i>=0; i--)  {
    digitalWrite(clockPin, 0);

    //if the value passed to myDataOut and a bitmask result 
    // true then... so if we are at i=6 and our value is
    // %11010100 it would the code compares it to %01000000 
    // and proceeds to set pinState to 1.
    if ( myDataOut & (1<<i) ) {
      pinState= 1;
    }
    else {  
      pinState= 0;
    }

    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(dataPin, pinState);
    //register shifts bits on upstroke of clock pin  
    digitalWrite(clockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(dataPin, 0);
  }

  //stop shifting
  digitalWrite(clockPin, 0);
}

