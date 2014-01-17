//source http://www.openprocessing.org/sketch/7475

float i;

//define the size of your matrix here. the maximal size is 16x16!
int PIXELS_X = 80;
int PIXELS_Y = 40;
int DATA_SIZE = PIXELS_X * PIXELS_Y;

//the maximal UDP packet size
int MAXIMAL_UDP_PACKET_SIZE = 65507;
 
void setup() {
  size(PIXELS_X, PIXELS_Y);
  frameRate(10);
  println("\nOSC Packet size: "+DATA_SIZE*BPP);
  if (DATA_SIZE*BPP > MAXIMAL_UDP_PACKET_SIZE) {
    println("ERROR, you use OSC to send that much data (UDP Packet size limit is 64k). Lower your resolution.");
    System.exit(1);
  }
  noSmooth();
  noStroke();
}
 
void draw() {
  int xofs = PIXELS_X / 10;
  int yofs = PIXELS_Y / 5;
  for (int y=0; y<5; y++) {
    for (int x=0; x<10; x++) {
      int c = x*xofs + y*yofs+frameCount<<2;
      fill(c % 255);
      rect(x*xofs,y*yofs,xofs,yofs);
    }
  }
  sendOsc();
}
 

