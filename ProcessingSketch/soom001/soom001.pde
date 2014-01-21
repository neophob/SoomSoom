
//define the size of your matrix here, see info tab of pixelcontroller to get
//the "Internal Buffersize"
int PIXELS_X = 80;
int PIXELS_Y = 40;

//define the physical pixel resolution
int PIXELCOUNT_HORIZ = 10;
int PIXELCOUNT_VERT = 5;

int DATA_SIZE = PIXELS_X * PIXELS_Y;
int[] pixelBuffer = new int[PIXELCOUNT_VERT*PIXELCOUNT_HORIZ];
//the maximal UDP packet size
int MAXIMAL_UDP_PACKET_SIZE = 65507;
float i;
 
void setup() {
  size(PIXELS_X, PIXELS_Y);
  frameRate(20);
  println("\nOSC Packet size: "+DATA_SIZE*BPP);
  if (DATA_SIZE*BPP > MAXIMAL_UDP_PACKET_SIZE) {
    println("ERROR, you use OSC to send that much data (UDP Packet size limit is 64k). Lower your resolution.");
    System.exit(1);
  }
  noSmooth();
  noStroke();
}
 
void draw() {
  //fill pixelbuffer (8bpp)
  for (int i=0; i<pixelBuffer.length; i++) {
    pixelBuffer[i] = (i*64+(i+frameCount<<2))%255;
  }
  
  //draw pixels
  drawPixelData();
  
  //send osc
  sendOsc();
}
 
void drawPixelData() {
  int xofs = PIXELS_X / PIXELCOUNT_HORIZ;
  int yofs = PIXELS_Y / PIXELCOUNT_VERT;
  int ofs = 0;
  for (int y=0; y<PIXELCOUNT_VERT; y++) {
    for (int x=0; x<PIXELCOUNT_HORIZ; x++) {      
      fill(pixelBuffer[ofs++]);
      rect(x*xofs,y*yofs,xofs,yofs);
    }
  }  
}
