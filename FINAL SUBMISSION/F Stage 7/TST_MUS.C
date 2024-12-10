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
#include "EFFECTS.H"
#include <stdio.h>

UINT32 get_time();

/**
 * Main program for testing the music system.
 * 
 * Initializes the music state, starts music playback, updates it over a 
 * defined duration, and stops playback. The test uses a loop to track elapsed 
 * time and updates the music accordingly.
 * 
 */
int main()
{
    UINT32 timeThen, timeNow, timeElapsed;
    char input = NO_INPUT;

    printf("Playing music... Hit s to play sound effect. \n");
    printf("Hit ESC to move on.");
    fflush(stdout);

    start_music();

    timeThen = get_time();

    while (input != ESC){
        timeNow = get_time();
        timeElapsed = timeNow - timeThen;

        if (Cconis()) {
            input = Cnecin();
        }

        if (input == 's') {
            play_crash();
        }

        if (timeElapsed > 0) {
            
            while (get_time() == timeNow);
            update_music(timeElapsed);
            timeThen = timeNow;
        }
    }





    return 0;
}

/**
 * Reads the current system time from a specific memory location.
 * 
 * @return Current system time in ticks.
 */
UINT32 get_time(){
    long *timer = (long *)0x462;
    long old_spp = Super(0);
    UINT32 timeNow = *timer;
    Super(old_spp);
    return timeNow;
}
