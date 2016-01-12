void barControl(uint8_t bar, uint32_t c){
  for(uint8_t i = bar; i < bar+5; i++)earBarsStrip.setPixelColor(i, c); // set bars to white
  earBarsStrip.show();
}

void colorEars(uint32_t c){
  for(uint8_t i = 0; i < 16; i++)earBarsStrip.setPixelColor(i, c); // set ears to whatever color you like
  earBarsStrip.show();
}

