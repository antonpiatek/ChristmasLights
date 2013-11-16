/* This header defines all user configurable stuff.
Of course you're free to change anything outside
this file too... :-) */

/* Remember to set your MCU in the Makefile */

/* Number of LEDs in the string, up to 255 */
#define NUM_LEDS	50

//Patterns to include
#include "static.h"	//removing static breaks cycle mode logic
#include "fade.h"
#include "run.h"
#include "chameleon.h"
#include "wave.h"
#include "twinkle.h"

#define NUM_PATTERNS 5			//not including static
unsigned char current_pattern = 1;	//default pattern, 0 is static
#define CYCLE_TIME 300/0.04		//frames to display a pattern for in cycle mode, must be integer, for convinience say "seconds/0.04".
bool cycle = 1;			//0 means default to not cycling, 1 means default to cycling from the default pattern


//add the patterns you desire and have #included to these three switches
void init(void) {
  switch (current_pattern) {
    case 0:
      static_init();
      break;
    case 1:
      fade_init();
      break;
    case 2:
      run_init();
      break;
    case 3:
      chameleon_init();
      break;
    case 4:
      wave_init();
      break;
    case 5:
      twinkle_init();
      break;
  }
/* Timer calibration, if the patterns are too fast, make
this larger. Not all MSP430s were created equal and few
come with larger than a 1MHz calibration. 
The Cycle time defined by CYCLE_TIME is a good thing to
check. */
#define DCO_CAL_DIV	16  return;
}

void frame(void) {
  switch (current_pattern) {
    case 0:
      static_frame();
      break;
    case 1:
      fade_frame();
      break;
    case 2:
      run_frame();
      break;
    case 3:
      chameleon_frame();
      break;
    case 4:
      wave_frame();
      break;
    case 5:
      twinkle_frame();
      break;
  }
  return;
}

unsigned long getled(unsigned char index) {
  switch (current_pattern) {
    case 0:
      return static_getled(index);
    case 1:
      return fade_getled(index);
    case 2:
      return run_getled(index);
    case 3:
      return chameleon_getled(index);
    case 4:
      return wave_getled(index);
    case 5:
      return twinkle_getled(index);
  }
  return(0);
}
