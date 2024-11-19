/*
Author: Abiola, Patrick
*/

#include "MUSIC.H"
#include "psg.h"
#include "TYPES.H"
#include <stdio.h>


const Note game_music[MELODY_LENGTH] = {
    {F_FLAT, 4, QUARTER_NOTE},
    {REST, 4, WHOLE_NOTE * 4},
    {F_FLAT, 4, QUARTER_NOTE},
    {REST, 4, WHOLE_NOTE * 4},
    {F_FLAT, 4, QUARTER_NOTE},
    {REST, 4, WHOLE_NOTE * 4},
    {F_FLAT, 3, QUARTER_NOTE},
    {REST, 4, WHOLE_NOTE * 4},
    {D_SHARP, 4, QUARTER_NOTE},
    {REST, 4, WHOLE_NOTE * 4},
    {D_SHARP, 4, QUARTER_NOTE},
    {REST, 4, WHOLE_NOTE * 4},
    {D_SHARP, 4, QUARTER_NOTE},
    {REST, 4, WHOLE_NOTE * 4},
    {D_SHARP, 3, QUARTER_NOTE},
    {REST, 4, WHOLE_NOTE * 4},
    {C_SHARP, 4, QUARTER_NOTE},
    {REST, 4, WHOLE_NOTE * 4},
    {C_SHARP, 4, QUARTER_NOTE},
    {REST, 4, WHOLE_NOTE * 4},
    {C_SHARP, 4, QUARTER_NOTE},
    {REST, 4, WHOLE_NOTE * 4},
    {C_SHARP, 3, QUARTER_NOTE},
    {REST, 4, WHOLE_NOTE * 4},
    {A, 3, QUARTER_NOTE},
    {REST, 4, WHOLE_NOTE * 4},
    {A, 3, QUARTER_NOTE},
    {REST, 4, WHOLE_NOTE * 4},
    {G_SHARP, 3, QUARTER_NOTE},
    {REST, 4, WHOLE_NOTE * 4},
    {F_FLAT, 4, QUARTER_NOTE}
};

void delay(int duration){
    volatile int i;
    for (i = 0; i < duration; i++);
}

void start_music(MusicState *state) {
    long old_ssp = Super(0);

    set_tone(CHANNEL_A, game_music[state->current_note_index].period);  
    set_volume(CHANNEL_A, 6);  
    enable_channel(CHANNEL_A, 1, 0); 
    Super(old_ssp);
}

void update_music(MusicState *state, UINT32 time_elapsed){
    long old_ssp = Super(0);
    int time_to_next_note = game_music[state->current_note_index].duration; 

    if (time_elapsed >= time_to_next_note) {
        state->current_note_index++;

        if (state->current_note_index >= MELODY_LENGTH) {
            printf("Restart Melody.\n");
            state->current_note_index = 0;  
        }

        if (game_music[state->current_note_index].period == REST) {
            write_psg(MIXER_REG, TONE_A | NOISE_A); 
            printf("Rest for duration: %d\n", game_music[state->current_note_index].duration);
        } 
        else {
            set_tone(CHANNEL_A, game_music[state->current_note_index].period); 
            set_volume(CHANNEL_A, 8);
            enable_channel(CHANNEL_A, 1, 0);  
        }
        
        time_to_next_note = game_music[state->current_note_index].duration; 
    }
    Super(old_ssp);
}

int calculate_period(int note, int octave){
    switch(octave){
        case 1: return (note * 8);
        case 2: return (note * 4);
        case 3: return (note * 2);
        case 4: return (note);
        case 5: return (note / 2);
        case 6: return (note / 4);
        case 7: return (note / 8);
        default: return note;
    }
}