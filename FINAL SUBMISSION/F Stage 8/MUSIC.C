/*
* COMP 2659 Music File
* 
* Purpose: To manage the background music for the game, including starting the music
*          and updating it based on elapsed time.
* Authors: Patrick Dang, Abiola Raji
* Date: December 9, 2024
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

/*
 * Function: start_music
 * ----------------------
 * Initializes the music playback by setting up the PSG sound chip.
 * Starts playing the first note in the melody.
 */
void start_music(){
    long old_ssp = Super(0);

    current_note_index = 0;

    set_tone(CHANNEL_A, game_music[current_note_index].tuning);
    set_envelope(9, 3000);

    enable_channel(CHANNEL_A, 1, 0); 
 
    set_volume(CHANNEL_A, 15); 
   
    Super(old_ssp);
}


/*
 * Function: update_music
 * -----------------------
 * Updates the currently playing note based on the elapsed time.
 * Advances to the next note in the melody when the duration of the current note is completed.
 *
 * Parameters:
 *   time_elapsed: The amount of time that has passed since the last update.
 */
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
        set_envelope(9, 3000);
        enable_channel(CHANNEL_A, 1, 0);
        set_volume(CHANNEL_A, 15);
    }
    
    Super(old_ssp);
    
}
