
#ifndef Tunes_H
#define Tunes_H

#include <math.h>

//Run Fixed Data Tables instead of microphone
static bool  testMode = false;

//Output Debug Messages
const bool   debugMode = false;
const int    debugLevel = 0;

const bool   debugNanInf = false;
const bool   debugPlotMic = false;
const bool   debugPlotFFT = false;
const bool   debugFPS = false;
const bool   debugRequired = (debugMode || debugNanInf || debugPlotMic || debugPlotFFT || debugFPS);

// LED SETUP
const unsigned int NUMLEDS = 60;
const unsigned int NUMSTRIPS = 4;
const unsigned int DATA_PIN_STRIP1 = 4;  //STRIP1 PIN ASSIGNMENT
const unsigned int DATA_PIN_STRIP2 = 5;  //STRIP2 PIN ASSIGNMENT
const unsigned int DATA_PIN_STRIP3 = 6;  //STRIP3 PIN ASSIGNMENT
const unsigned int DATA_PIN_STRIP4 = 7;  //STRIP4 PIN ASSIGNMENT

// VISUALIZATION TUNES
const float MAX_DISPLAYED_FREQ = 10000.0;
const unsigned int NUMBER_OF_TICK_TIMERS = 10;
const unsigned int NUMBER_OF_LAYERS = 10;

//FFT Tunes
const int FFT_MAX = 128;
const unsigned int SAMPLE_RATE = 26000;
const int SAMPLE_TIME_US = 1000000.0/SAMPLE_RATE;
const unsigned int BIN_SAVE_LENGTH = 60;

//Trigger Level
const float SILENCE_THRESHOLD = 0.05;
const float triggerLevelGain = 1.1;

// Sampler Tunes
/* ch7:A0 ch6:A1 ch5:A2 ch4:A3 ch3:A4 ch2:A5 ch1:A6 ch0:A7 */
#define ADC_CHANNELS ADC_CHER_CH7 | ADC_CHER_CH5 | ADC_CHER_CH4  //Fixed Gain Mic
//#define ADC_CHANNELS ADC_CHER_CH6 | ADC_CHER_CH5 | ADC_CHER_CH4  //Auto Gain Mic
#define ADC_RESOLUTION 12
const unsigned int NUM_CHANNELS = 3;
const unsigned int CHANNEL_SIZE = FFT_MAX;
const unsigned int BUFFER_SIZE = CHANNEL_SIZE*NUM_CHANNELS;
const unsigned int NUMBER_OF_BUFFERS = 20;  /// Size of circular buffer for holding microphone sample sets
const unsigned int MAX_BUFFERS_TO_PROCESS = 20;  /// Max number of mic sample sets to process.  This prevents a runnaway from occuring if the CPU cannot keep up

//Sound Detection
const float   SOUND_DETECT_THRESHOLD = 0.05;
const int     silenceIntegratorMax = 50000;
const int     silenceDetectedThreshold = 0.1*silenceIntegratorMax;
const int     soundDetectedThreshold = 0.9*silenceIntegratorMax;
const int     soundAdder = 1000;
const int     silenceSubtractor = -10;

//CALCULATED TUNES
const int FFT_M = (int)log2(FFT_MAX);
const int BINS = FFT_MAX / 2;
const float BINS_DOUBLE = FFT_MAX / 2.0;
const int ADDBITS = pow(2,ADC_RESOLUTION);
const int FFT_GAIN = 1000;
const int POWER_GAIN = 20;
const int MAX_POWER = ADDBITS * POWER_GAIN;
const float MAX_DB = 20*log10(ADDBITS);

#endif
