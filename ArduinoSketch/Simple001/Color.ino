// --------------------------------------------
// create a 15bit color
// --------------------------------------------
unsigned int Color(byte r, byte g, byte b) {
  //Take the lowest 5 bits of each value and append them end to end
  return( (((unsigned int)g & 0x1F )<<10) | (((unsigned int)b & 0x1F)<<5) | ((unsigned int)r & 0x1F));
}

//convert from 24bpp -> 15bpp
unsigned int Color24bpp(byte r, byte g, byte b) {
  return Color(r>>3, g>>3, b>>3);
}

