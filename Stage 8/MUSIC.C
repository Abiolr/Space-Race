/*
Author: Abiola, Patrick
*/
#include <stdio.h>
#include "psg.h"
#include "MUSIC.h"
#include "TYPES.H"

static int current_note_index = 0;
static int note_elapsed_time = 0;

const Note game_music[MELODY_LENGTH] = {
    {E_FLAT, QUARTER_NOTE},
    {REST, QUARTER_NOTE},
    {E_FLAT, QUARTER_NOTE},
    {REST, QUARTER_NOTE},
    {E_FLAT, QUARTER_NOTE},
    {REST, QUARTER_NOTE},
    {E_FLAT / 2, QUARTER_NOTE},
    {REST, QUARTER_NOTE},
    {D_SHARP, QUARTER_NOTE},
    {REST, QUARTER_NOTE},
    {D_SHARP, QUARTER_NOTE},
    {REST, QUARTER_NOTE},
    {D_SHARP, QUARTER_NOTE},
    {REST, QUARTER_NOTE},
    {D_SHARP / 2, QUARTER_NOTE},
    {REST, QUARTER_NOTE},
    {C_SHARP, QUARTER_NOTE},
    {REST, QUARTER_NOTE},
    {C_SHARP, QUARTER_NOTE},
    {REST, QUARTER_NOTE},
    {C_SHARP, QUARTER_NOTE},
    {REST, QUARTER_NOTE},
    {C_SHARP / 2, QUARTER_NOTE},
    {REST, QUARTER_NOTE},    
    {A, HALF_NOTE},
    {REST, QUARTER_NOTE}, 
    {G_SHARP, QUARTER_NOTE},
    {REST, QUARTER_NOTE}, 
    {E_FLAT, WHOLE_NOTE},
    {REST, QUARTER_NOTE},
    {REST, QUARTER_NOTE}
};

void start_music(){
    
    long old_ssp = Super(0);
    stop_sound();

    current_note_index = 0;

    set_tone(CHANNEL_A, game_music[current_note_index].tuning);

    set_envelope(0x9, 3000);

    enable_channel(CHANNEL_A, 1, 0); 

    set_volume(CHANNEL_A, 15); 
   
    Super(old_ssp);
}

void update_music(UINT32 time_elapsed) {
    long old_ssp = Super(0);
    
    note_elapsed_time += time_elapsed;

    if (note_elapsed_time >= game_music[current_note_index].duration) {
     
        current_note_index++;
        note_elapsed_time = 0;

  
        if (current_note_index >= MELODY_LENGTH) {
            current_note_index = 0;
        }

        set_tone(CHANNEL_A, game_music[current_note_index].tuning);
        set_envelope(0x9, 3000);
        enable_channel(CHANNEL_A, 1, 0);
        set_volume(CHANNEL_A, 15);
    }
    
    Super(old_ssp);
    
}
