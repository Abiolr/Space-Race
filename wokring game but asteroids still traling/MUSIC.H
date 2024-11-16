#ifndef MUSIC_H
#define MUSIC_H

#include "psg.h"

#define WHOLE_NOTE 128     
#define HALF_NOTE 64        
#define QUARTER_NOTE 32     

/*no sound*/
#define REST 0

#define C_FLAT 478
#define C_SHARP 451
#define D_FLAT 426
#define D_SHARP 402
#define E_FLAT 379
#define F_FLAT 358
#define F_SHARP 338
#define G_FLAT 319
#define G_SHARP 301
#define A_FLAT 284
#define A 276
#define A_SHARP 268
#define B_FLAT 253
#define CHANNEL_A 0


typedef struct
{
    int period;  // The period value for this note, based on the octave and note
    int octave;  // Represent octave (middle = 4, higher or lower octaves are adjusted accordingly)
    int duration; // Duration of the note in ms or a chosen time unit
} Note;

void start_music();
void update_music();
void stop_music();
int calculate_period(int note, int octave);

#endif

