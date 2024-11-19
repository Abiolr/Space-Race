/**
 * MUSIC_TEST.C file
 * A test driver for the music system implementation.
 *
 * Purpose: This program tests the functionality of the music system by initializing 
 * the music state, starting and updating the music, and stopping it after a specified duration.
 * The test uses a timer to calculate elapsed time and updates the music state accordingly.
 *
 * Authors: - Abiola Raji Patrick Dang
 * 
 * Date: Nov 18, 2024
 */

#include "MUSIC.H"
#include "TYPES.H"
#include <stdio.h>

/**
 * Main program for testing the music system.
 * 
 * Initializes the music state, starts music playback, updates it over a 
 * defined duration, and stops playback. The test uses a loop to track elapsed 
 * time and updates the music accordingly.
 *
 * TO DO: Did not finish the sound, got part of the sound to start playing, 
 * having trouble getting rests and different octaves to work for each note.
 * 
 * 
 * @return 0 on successful completion.
 */
int main()
{
    UINT32 timeThen, timeNow, timeElapsed;
    int i;
    MusicState music_state;

    music_state.current_note_index = 0;

    printf("Starting music test driver...\n");

    stop_sound();  
    printf("Sound Muted.\n");

    start_music(&music_state);
    printf("Music started.\n");

    timeThen = get_time2();

    for (i = 0; i < TEST_DURATION; i++){
        timeNow = get_time2(); // Get the current time

        timeElapsed = timeThen - timeNow; // Calculate elapsed time
        delay(10000); // Introduce a delay for timing simulation

        if (timeElapsed > 0) {
            update_music(&music_state, timeElapsed);
            timeThen = timeNow; // Update reference time
        }  
    }

    printf("Melody done.\n");
    stop_sound();
    printf("Music stopped.\n");

    printf("Music test driver completed.\n");
    return 0;
}

/**
 * Reads the current system time from a specific memory location.
 * 
 * @return Current system time in ticks.
 */
UINT32 get_time2(){
    long *timer = (long *)0x462;
    long old_spp = Super(0);
    UINT32 timeNow = *timer;
    Super(old_spp);
    return timeNow;
}
