/*
* COMP 2659 Effects File
* 
* Purpose: To implement sound effects for the game, such as crashes or other events.
* Authors: Patrick Dang, Abiola Raji
* Date: December 9, 2024
*/

#include <stdio.h>
#include "psg.h"
#include "TYPES.H"
#include "MUSIC.H"
#include "EFFECTS.H"

/*
 * Function: play_crash
 * ----------------------
 * Plays the sound effect for a crash using the PSG sound chip.
 * Configures tones, noise, and volume for the relevant channels.
 */
void play_crash() {
    long old_ssp = Super(0);

    set_tone(CHANNEL_B, G_FLAT / 6);       
    set_tone(CHANNEL_C, G_FLAT / 6);       
    set_noise(0x0F);                     
    set_volume(CHANNEL_B, 16);            
    set_volume(CHANNEL_C, 16);             
    enable_channel(CHANNEL_B, 1, 0);       
    enable_channel(CHANNEL_C, 1, 0);       

    Super(old_ssp);                        
}
