/*
 * COMP 2659 Music File
 * 
 * Purpose: To manage background music playback in the game using the PSG sound system.
 *          Handles music initialization, note sequencing, timing, and melody looping.
 *          Includes a predefined melody array with note frequencies, durations, and rest periods.
 * 
 * Authors: Patrick Dang, Abiola Raji
 * Date: November 18, 2024
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

/*
 * Function: delay
 * Purpose: Creates a time delay by running an empty loop for a specified duration.
 * Parameters:
 *      duration - The number of iterations for the delay loop.
 * Returns:
 *      None.
 */
void delay(int duration){
    volatile int i;
    for (i = 0; i < duration; i++);
}

/*
 * Function: start_music
 * Purpose: Initializes and starts playing music on Channel A of the PSG.
 * Parameters:
 *      state - Pointer to the MusicState structure containing the current playback state.
 * Returns:
 *      None.
 */
void start_music(MusicState *state) {
    long old_ssp = Super(0);

    set_tone(CHANNEL_A, game_music[state->current_note_index].period);  
    set_volume(CHANNEL_A, 6);  
    enable_channel(CHANNEL_A, 1, 0); 
    Super(old_ssp);
}

/*
 * Function: update_music
 * Purpose: Updates the music playback based on elapsed time, handling note transitions
 *          and melody repetition.
 * Parameters:
 *      state - Pointer to the MusicState structure containing the current playback state.
 *      time_elapsed - The amount of time that has passed since the last update.
 * Returns:
 *      None.
 */
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

/*
 * Function: calculate_period
 * Purpose: Calculates the period value for a given musical note and octave.
 * Parameters:
 *      note - The base frequency value of the note.
 *      octave - The octave multiplier (1-7).
 * Returns:
 *      The calculated period value for the note in the specified octave.
 */
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