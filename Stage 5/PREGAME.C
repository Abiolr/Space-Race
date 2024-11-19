#include <stdio.h>
#include <osbind.h>
#include "RENDER.H"
#include "MODEL.H"
#include "raster.h"
#include "EVENTS.H"

int quit = FALSE;

int main(){
    game_loop();
    return 0;
}

void game_loop(){
    UINT32 timeThen, timeNow, timeElapsed;
    Model model;
    UINT32 frontBuffer = Physbase();

    init_model(&model);

    clear_screen(frontBuffer);

    timeThen = get_time();

    while (!check_exit_conditions(&model)){

        timeNow = get_time();
        timeElapsed = timeNow - timeThen;

        if (timeElapsed > 0){

            handle_input(&model); 

            while (get_time() == timeNow);

            update_asteroids(&model); 

            render(frontBuffer, &model); 
       
            timeThen = timeNow;
        }
    }
}

UINT32 get_time(){
    long *timer = (long *)0x462;
    long old_spp = Super(0);
    UINT32 timeNow = *timer;
    Super(old_spp);
    return timeNow;
}

int check_exit_conditions(Model *model) {
    return quit || model->lives <= 0;
}

void handle_input(Model *model){
    char input;
    if (Cconis()){
        input = Cnecin();
    }
    else{
        input = NO_INPUT; 
    }
    if (input != NO_INPUT){
        switch(input) {
            case 'w':
            move_spaceship_up(model);
            move_spaceship(&model->spaceship);
            break;
            case 's':
            move_spaceship_down(model);
            move_spaceship(&model->spaceship);
            break;
            case ESC:
            quit = TRUE;
            break;
            } 
        }
}