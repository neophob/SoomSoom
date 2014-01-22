void solid() {
  delay(200);
  k++;
  int r = random(strip.numPixels()-2);
  for (unsigned int i=0; i < r; i++) {
    strip.setPixelColor(i, Color24bpp(0,255,0));
  }
  for (unsigned int i=r; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, Color24bpp(255,0,0));
  }
  strip.show();      
}


void rainbow() {
  delay(1);

  k++;
  if (k>50) {
    k=0;
    j++;
    if (j>96*3) {  // 3 cycles of all 96 colors in the wheel
      j=0; 
    }

    for (unsigned int i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i + j) % 96));
    }
    strip.show();    
  }
}
 
 
// --------------------------------------------
//     Input a value 0 to 127 to get a color value.
//     The colours are a transition r - g -b - back to r
// --------------------------------------------
unsigned int Wheel(byte WheelPos) {
  byte r,g,b;
  switch(WheelPos >> 5) {
  case 0:
    r=31- WheelPos % 32;   //Red down
    g=WheelPos % 32;      // Green up
    b=0;                  //blue off
    break; 
  case 1:
    g=31- WheelPos % 32;  //green down
    b=WheelPos % 32;      //blue up
    r=0;                  //red off
    break;   
  case 2:
  default:
    b=31- WheelPos % 32;  //blue down 
    r=WheelPos % 32;      //red up
    g=0;                  //green off
    break; 
  }
  return(Color(r,g,b));
}

