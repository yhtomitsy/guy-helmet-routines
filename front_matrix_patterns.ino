void smile(uint8_t color, uint8_t bq){
  for (uint8_t i = 0; i < strip2.numPixels(); i++){
    if(i == 166||i == 155||i == 141||i == 152||i == 138||i == 127||i == 113||i == 124||i == 110||i == 99||i == 1||i == 12){
      strip2.setPixelColor(i, strip2.Color(0,0,0));
    }
    else strip2.setPixelColor(i, Wheel(color,2,bq));
  }
  for (uint8_t i = 0; i < strip1.numPixels(); i++){  
    if(i == 194||i == 183||i == 169||i == 180||i == 165||i == 156||i == 143||i == 150){
      strip1.setPixelColor(i, strip1.Color(0,0,0));
    }
    else if(i > 129 && i < 136){
      strip1.setPixelColor(i, strip1.Color(0,0,0));
    }
    else strip1.setPixelColor(i, Wheel(color,1,bq));
  }
  for (uint8_t i = 0; i < strip3.numPixels(); i++){    
    strip3.setPixelColor(i, Wheel(color,3,bq));
  }
  strip3.show();
  strip1.show();
  strip2.show();
}

void frown(uint8_t color, uint8_t bq){
  for (uint8_t i = 0; i < strip3.numPixels(); i++){
    strip3.setPixelColor(i, Wheel(color,3,bq));
  }
  for (uint8_t i = 0; i < strip2.numPixels(); i++){  
    if(i == 166||i == 155||i == 141||i == 152||i == 138||i == 127||i == 113||i == 124||i == 110||i == 99){
      strip2.setPixelColor(i, strip2.Color(0,0,0));
    }
    else if(i > 3 && i < 10){
      strip2.setPixelColor(i, strip2.Color(0,0,0));
    }
    else strip2.setPixelColor(i, Wheel(color,2,bq));
  }
  for (uint8_t i = 0; i < strip1.numPixels(); i++){    
    if(i == 138||i == 127||i == 141||i == 152||i == 166||i == 155||i == 170||i == 179||i == 192||i == 185){
      strip1.setPixelColor(i, strip1.Color(0,0,0));
    }else strip1.setPixelColor(i, Wheel(color,1,bq));
  }
  strip3.show();
  strip1.show();
  strip2.show();
}

void goofyFace1(uint8_t color, uint8_t bq){
  for (uint8_t i = 0; i < strip2.numPixels(); i++){
    if(i > 134 && i < 139 || i > 126 && i < 131){
      strip2.setPixelColor(i, strip2.Color(0,0,0));
    }
    else strip2.setPixelColor(i, Wheel(color,2,bq));
  }
  for (uint8_t i = 0; i < strip1.numPixels(); i++){  
    if(i == 194||i == 183||i == 169||i == 180||i == 165||i == 156||i == 143||i == 150){
      strip1.setPixelColor(i, strip1.Color(0,0,0));
    }
    else if(i > 129 && i < 136){
      strip1.setPixelColor(i, strip1.Color(0,0,0));
    }
    else strip1.setPixelColor(i, Wheel(color,1,bq));
  }
  for (uint8_t i = 0; i < strip3.numPixels(); i++){    
    strip3.setPixelColor(i, Wheel(color,3,bq));
  }
  strip3.show();
  strip1.show();
  strip2.show();
}
void goofyFace2(uint8_t color, uint8_t bq){
  for (uint8_t i = 99; i < 166; i++){
    if(i > 140 && i < 145 || i > 112 && i < 117 || i > 148 && i < 153 || i > 120 && i < 125 || i > 163 && i < 166 || i > 107 && i < 110 || i > 155 && i < 158 || i > 99 && i < 102){
      strip2.setPixelColor(i, strip2.Color(0,0,0));
    }
  }
  strip2.setPixelColor(136, Wheel(100,2,bq));
  strip2.setPixelColor(137, Wheel(100,2,bq));
  strip2.setPixelColor(129, Wheel(100,2,bq));
  strip2.setPixelColor(128, Wheel(100,2,bq));
  strip2.show();
}

void goofyFace3(uint8_t color, uint8_t bq){
  strip2.setPixelColor(136, strip2.Color(0,0,0));
  strip2.setPixelColor(137, strip2.Color(0,0,0));
  strip2.setPixelColor(129, strip2.Color(0,0,0));
  strip2.setPixelColor(128, strip2.Color(0,0,0));
  for (uint8_t i = 0; i < 4; i++){
    if((135+i-1) > 134){
      strip2.setPixelColor(135+i-1, strip2.Color(0,0,0));
      strip2.setPixelColor(127+i-1, strip2.Color(0,0,0));
    }
    strip2.setPixelColor(135+i, Wheel(color,2,bq));
    strip2.setPixelColor(127+i, Wheel(color,2,bq));
    strip2.show();
    delay(100);
  }
  for (uint8_t i = 0; i < 4; i++){
    if((138-i+1) < 139){
      strip2.setPixelColor(138-i+1, strip2.Color(0,0,0));
      strip2.setPixelColor(130-i+1, strip2.Color(0,0,0));
    }
    strip2.setPixelColor(138-i, Wheel(color,2,bq));
    strip2.setPixelColor(130-i, Wheel(color,2,bq));
    strip2.show();
    delay(100);
  }
}

void OK(uint8_t bq){
  clearMatrix();
  strip1.show();
  strip2.show();
  strip3.show();
  for(uint8_t i = 0; i < 10; i++){
     strip2.setPixelColor(100+i, Wheel(0,2,bq));
     Osides(i,44,2,Wheel(0,2,bq),0);
  }
  strip2.show();
  delay(100);
  for(uint8_t i = 0; i < 10; i++){
     strip2.setPixelColor(114+i, Wheel(16,2,bq));
     Osides(i,30,2,Wheel(16,2,bq),0);
  }
  strip2.show();
  delay(100);
  for(uint8_t i = 0; i < 10; i++){
     Osides(i,128,2,Wheel(32,2,bq),0);
     if(i < 9)Osides(i,17,2,Wheel(32,2,bq),1);
  }
  strip2.show();
  delay(100);

  for(uint8_t i = 0; i < 10; i++){
     Osides(i,142,2,Wheel(48,2,bq),0);
     if(i < 9)Osides(i,3,2,Wheel(48,2,bq),1);
  }
  strip2.show();
  delay(100);

  for(uint8_t i = 0; i < 10; i++){
     Osides(i,156,2,Wheel(64,2,bq),0);
     if(i < 8)Osides(i,186,1,Wheel(64,1,bq),2);
  }
  strip2.show();
  strip1.show();
  delay(100);

  for(uint8_t i = 0; i < 10; i++){
     Osides(i,170,2,Wheel(80,2,bq),0);
     if(i < 8)Osides(i,172,1,Wheel(80,1,bq),2);
  }
  strip2.show();
  strip1.show();
  delay(100);
  
  for(uint8_t i = 0; i < 10; i++){
     Osides(i,2,3,Wheel(96,3,bq),0);
     if(i < 7)strip1.setPixelColor(159+i, Wheel(96,1,bq));
  }
  strip1.show();
  strip3.show();
  delay(100);

  for(uint8_t i = 0; i < 10; i++){
     Osides(i,16,3,Wheel(112,3,bq),0);
     if(i < 7)strip1.setPixelColor(145+i, Wheel(112,1,bq));
  }
  strip1.show();
  strip3.show();
  delay(100);

  for(uint8_t i = 0; i < 10; i++){
     Osides(i,30,3,Wheel(128,3,bq),0);
     if(i < 8)strip1.setPixelColor(130+i, Wheel(128,1,bq));
  }
  strip1.show();
  strip3.show();
  delay(100);

  for(uint8_t i = 0; i < 10; i++){
     Osides(i,44,3,Wheel(144,3,bq),0);
     if(i < 8)strip1.setPixelColor(116+i, Wheel(144,1,bq));
  }
  strip1.show();
  strip3.show();
  delay(100);

  for(uint8_t i = 0; i < 10; i++){
     Osides(i,58,3,Wheel(160,3,bq),0);
     if(i < 8)Osides(i,102,1,Wheel(160,1,bq),2);
     strip1.setPixelColor(101, Wheel(160,1,bq));
  }
  strip1.show();
  strip3.show();
  delay(100);

  for(uint8_t i = 0; i < 10; i++){
     Osides(i,72,3,Wheel(176,3,bq),0);
     if(i < 9)Osides(i,87,1,Wheel(176,1,bq),1);
  }
  strip1.show();
  strip3.show();
  delay(100);

  for(uint8_t i = 0; i < 10; i++){
     Osides(i,86,3,Wheel(192,3,bq),0);
     if(i < 9)Osides(i,73,1,Wheel(192,1,bq),1);
  }
  
  strip1.show();
  strip3.show();
  delay(100);


  for(uint8_t i = 0; i < 10; i++){
     Osides(i,100,3,Wheel(208,3,bq),0);
     Osides(i,58,1,Wheel(208,1,bq),0);
  }
  strip1.show();
  strip3.show();
  delay(100);

  for(uint8_t i = 0; i < 10; i++){
     strip3.setPixelColor(114+i, Wheel(224,3,bq));
     Osides(i,44,1,Wheel(224,1,bq),0);
  }
  strip1.show();
  strip3.show();
  delay(100);

  for(uint8_t i = 0; i < 10; i++){
     strip3.setPixelColor(128+i, Wheel(240,3,bq));
     Osides(i,30,1,Wheel(240,1,bq),0);
  }
  strip1.show();
  strip3.show();
  delay(100);
}

void Osides(uint8_t i, int x, uint8_t strip,uint32_t color, uint8_t n){
  if(x+i > x+1 && x+i < x+8-n){
  }
  else{ 
    if(strip == 1)strip1.setPixelColor(x+i, color);
    if(strip == 2)strip2.setPixelColor(x+i, color);
    if(strip == 3)strip3.setPixelColor(x+i, color);
  }
}
