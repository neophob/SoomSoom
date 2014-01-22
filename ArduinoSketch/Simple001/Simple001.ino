// SPI Pins for Arduino UNO/2009: 11 (MOSI), 13 (SCK)
// SPI Pins for Teensy 2.0 1/B1 (SCK), 2/B2 (MOSI)
// SPI Pins for Teensy++ 2.0 21/B1 (SCK), 22/B2 (MOSI)
#include <SPI.h>
#include <TimerOne.h>
#include <Neophob_LPD6803.h>

#define NR_OF_PIXELS 20

//Teensy 2.0 has the LED on pin 11.
//Teensy++ 2.0 has the LED on pin 6
//Teensy 3.0 has the LED on pin 13
//Arduino UNO pin 13
#define LED_PIN 13

#define BAUD_RATE 115200

// rainbow animation stuff
int j=0,k=0;

//initialize pixels
Neophob_LPD6803 strip = Neophob_LPD6803(NR_OF_PIXELS);

// --------------------------------------------
//      setup
// --------------------------------------------
void setup() {
  Serial.begin(BAUD_RATE); //Setup high speed Serial
  Serial.flush();

  //first blink: init
  digitalWrite(LED_PIN, HIGH);
  delay(250);
  digitalWrite(LED_PIN, LOW);  
  
  //SETUP SPI SPEED AND ISR ROUTINE
  //-------------------------------
  //The SPI setup is quite important to set up correctly

  //SPI SPEED REFERENCE  
  //strip.begin(SPI_CLOCK_DIV128);        // Start up the LED counterm 0.125MHz - 8uS
  //strip.begin(SPI_CLOCK_DIV64);        // Start up the LED counterm 0.25MHz - 4uS
  //strip.begin(SPI_CLOCK_DIV32);        // Start up the LED counterm 0.5MHz - 2uS
  //strip.begin(SPI_CLOCK_DIV16);        // Start up the LED counterm 1.0MHz - 1uS
  //strip.begin(SPI_CLOCK_DIV8);        // Start up the LED counterm 2.0MHz - 0.5uS
  //strip.begin(SPI_CLOCK_DIV4);        // Start up the LED counterm 4.0MHz - 0.25uS
  //strip.begin(SPI_CLOCK_DIV2);        // Start up the LED counterm 8.0MHz - 0.125uS

  strip.setCPU(36);                    // call the isr routine each 36us to drive the pwm
  strip.begin(SPI_CLOCK_DIV8);        // Start up the LED counterm 0.5MHz - 2uS

  rainbow();      // display some colors
  
  //second blink: init done
  delay(250);  
  digitalWrite(LED_PIN, HIGH);
  delay(250);
  digitalWrite(LED_PIN, LOW);    
}


// --------------------------------------------
//      main loop
// --------------------------------------------
void loop() {
  //rainbow();
  solid();
}




