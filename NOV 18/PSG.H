#ifndef PSG_H
#define PSG_H

#include <osbind.h>
#include "types.h"

#define CHANNEL_A 0
#define CHANNEL_B 1
#define CHANNEL_C 2

#define A_FINE 0x0
#define B_FINE 0x2
#define C_FINE 0x4

#define A_COARSE 0x1
#define B_COARSE 0x3
#define C_COARSE 0x5

#define A_VOL 0x8
#define B_VOL 0x9
#define C_VOL 0xA

#define NOISE_FREQ_REG 0x6
#define MIXER_REG 0x7

#define MIXER_NONE 0x3F         

#define TONE_A 0x3E    
#define TONE_B 0x3D    
#define TONE_C 0x3B    

void write_psg(int reg, UINT8 val);

UINT8 read_psg(int reg);

void set_tone(int channel, int tuning);


void set_volume(int channel, int vol);

void enable_channel(int channel, int tone_on, int noise_on);

void stop_sound();

#endif
