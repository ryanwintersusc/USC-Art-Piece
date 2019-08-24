/*  OctoWS2811 BasicTest.ino - Basic RGB LED Test
    http://www.pjrc.com/teensy/td_libs_OctoWS2811.html
    Copyright (c) 2013 Paul Stoffregen, PJRC.COM, LLC

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.

  Required Connections
  --------------------
    pin 2:  LED Strip #1    OctoWS2811 drives 8 LED Strips.
    pin 14: LED strip #2    All 8 are the same length.
    pin 7:  LED strip #3
    pin 8:  LED strip #4    A 100 ohm resistor should used
    pin 6:  LED strip #5    between each Teensy pin and the
    pin 20: LED strip #6    wire to the LED strip, to minimize
    pin 21: LED strip #7    high frequency ringining & noise.
    pin 5:  LED strip #8
    pin 15 & 16 - Connect together, but do not use
    pin 4 - Do not use
    pin 3 - Do not use as PWM.  Normal use is ok.

  This test is useful for checking if your LED strips work, and which
  color config (WS2811_RGB, WS2811_GRB, etc) they require.
*/

#include <OctoWS2811.h>

const int ledsPerStrip = 600;

DMAMEM int displayMemory[ledsPerStrip * 6];
int drawingMemory[ledsPerStrip * 6];

const int config = WS2811_GRB | WS2811_800kHz;

OctoWS2811 leds(ledsPerStrip, displayMemory, drawingMemory, config);

void setup() {
  leds.begin();
  leds.show();
}
/*
  #define RED    0xFF0000
  #define GREEN  0x00FF00
  #define BLUE   0x0000FF
  #define YELLOW 0xFFFF00
  #define PINK   0xFF1088
  #define ORANGE 0xE05800
  #define WHITE  0xFFFFFF
*/
// Less intense...

#define RED    0x160000
#define GREEN  0x001600
#define BLUE   0x000016
#define YELLOW 0x101400
#define PINK   0x120009
#define ORANGE 0x100400
#define WHITE  0x101010

////////////////GLOBAL VARIABLE for current color for ballOn and tubeOn
uint32_t globalColor;//LOW BRIGHTNESS!! Lets not kill the power supply
int totalNum 434;

int Blen 20;

int B1start 0;
int B2start 41;
int B3start 82;
int B4start 123;
int B5start 227;
int B6start 268;
int B7start 175;
int B8start 341;
int B9start 382;

int Hlen 21;
int Dlen 32;

int H1start 20;
int H2start 61;
int H3start 102;
int H4start 247;
int H5start 288;
int H6start 361;

int D1start 195;
int D2start 143;
int D3start 309;
int D4start 402;


void loop() {

  allOff();
  //set all leds blue
  globalColor = BLUE;
  allOn();
  //path will light up in red
  globalColor = RED;

  //Sequence 1
  ballOn(B1start); //B1
  tubeOn(H1start, Hlen); //T12
  ballOn(B2start); //B2
  tubeOn(H2start, Hlen); //T23
  ballOn(B3start); //B3
  tubeOn(H3start, Hlen); //T34
  ballOn(B4start); //B4
  delay(1500);
  globalColor = BLUE;
  allOn();
  globalColor = RED;


  //Sequence 2
  ballOn(B1start); //B1
  tubeOn(H1start, Hlen); //T12
  ballOn(B2start); //B2
  tubeOn(H2start, Hlen); //T23
  ballOn(B3start); //B3
  tubeOn(D2start, Dlen); //T34
  ballOn(B7start); //B4
  delay(1500);
  globalColor = BLUE;
  allOn();
  globalColor = RED;


  //Sequence 3
  ballOn(B1start); //B1
  tubeOn(D1start, Dlen); //T12
  ballOn(B5start); //B2
  tubeOn(H4start, Hlen); //T23
  ballOn(B6start); //B3
  tubeOn(H5start, Hlen); //T34
  ballOn(B7start); //B4
  delay(1500);

  globalColor = BLUE;
  allOn();
  globalColor = RED;
 
  //Sequence 4
  ballOn(B1start); //B1
  tubeOn(D1start, Dlen); //T12
  ballOn(B5start); //B2
  tubeOn(H4start, Hlen); //T23
  ballOn(B6start); //B3
  tubeOn(D4start, Dlen); //T34
  ballOn(B9start); //B4
  delay(1500);
  
  globalColor = BLUE;
  allOn();
  globalColor = RED;


  //Sequence 5
  ballOn(B1start); //B1
  tubeOn(D1start, Dlen); //T12
  ballOn(B5start); //B2
  tubeOn(D3start, Dlen); //T23
  ballOn(B8start); //B3
  tubeOn(H6start, Hlen); //T34
  ballOn(B9start); //B4
  delay(1500);




}

//Turns on all of the LEDs in the ball at once then delays for 500ms
void ballOn(int startNum) {

  for (int i = startNum; i < startNum + Blen; i++) {
    leds.setPixel(i, globalColor);
  }
  leds.show();
  delay(500);

}

//Turns on each LED with a delay in between
void tubeOn(int startNum, int len) {
  for (int i = startNum; i < startNum + len; i++) {
    leds.setPixel(i, globalColor);
    leds.show();
    delay(50);
  }
}

void allOff() {
  for (int i = 0; i < totalNum; i++) {
    leds.setPixel(i, 0);
  }
  leds.show();
}

void allOn() {
  for (int i = 0; i < totalNum; i++) {
    leds.setPixel(i, globalColor);
  }
  leds.show();

}
