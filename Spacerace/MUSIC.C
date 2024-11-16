/*
Author: Abiola, Patrick
*/

#include "MUSIC.H"
#include "psg.h"

const Note game_music[]{
    {F_FLAT, 4, 32},
    {F_FLAT, 4, 32},
    {F_FLAT, 4, 32},
    {F_FLAT, 3, 32},
    {D_SHARP, 4, 32},
    {D_SHARP, 4, 32},
    {D_SHARP, 4, 32},
    {D_SHARP, 3, 32},
    {C_SHARP, 4, 32},
    {C_SHARP, 4, 32},
    {C_SHARP, 4, 32},
    {C_SHARP, 3, 32},
    {A, 3, 32},
    {A, 3, 32},
    {G_SHARP, 3, 32},
    {F_FLAT, 4, 32}
}

void start_music(){
    long oldssp = Super(0);

    write_psg(CHANNEL_A, MIXER_NONE); 

    /*first note of the song*/
    set_tone(0, game_music[0].tuning);
     
    enable_channel(0, 1, 0);

    set_volume(0, 0x0C);
   
    Super(oldssp);
}

void update_music(){

}

void stop_music(){
	long old_ssp = Super(0);

	stop_sound();

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