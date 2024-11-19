#include "MUSIC.H"
#include "TYPES.H"
#include <stdio.h>

UINT32 get_time2(){
    long *timer = (long *)0x462;
    long old_spp = Super(0);
    UINT32 timeNow = *timer;
    Super(old_spp);
    return timeNow;
}

int main()
{
    UINT32 timeThen, timeNow, timeElapsed;
    int i;
    MusicState music_state;

    music_state.current_note_index = 0;

    /*long old_ssp = Super(0);*/

    printf("Starting music test driver...\n");
    stop_sound();  
    printf("Sound Muted.\n");
    /*Super(old_ssp);*/

    start_music(&music_state);
    printf("Music started.\n");


    timeThen = get_time2();

    for (i; i < TEST_DURATION; i++){
        timeNow = get_time2();

        timeElapsed = timeThen - timeNow;
        delay(10000);
        if (timeElapsed > 0) {
                update_music(&music_state, timeElapsed);
                timeThen = timeNow;
            }  

    }

    printf("Melody done.\n");

    stop_sound();
    printf("Music stopped.\n");

    printf("Music test driver completed.\n");
    return 0;

}
