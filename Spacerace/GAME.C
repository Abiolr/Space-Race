#include <stdio.h>
#include <osbind.h>
#include <stdlib.h>
#include "RENDER.H"
#include "MODEL.H"
#include "raster.h"
#include "EVENTS.H"


UINT32 buffer_storage[(BUFFER_SIZE + ALIGNMENT)];
UINT32 *frontBuffer;
UINT32 *backBuffer;

int quit = FALSE;

void init_buffers() {
    UINT32 aligned_addr;
    frontBuffer = Physbase();

    aligned_addr = ((UINT32)buffer_storage + ALIGNMENT - 1) & ~(ALIGNMENT - 1);
    backBuffer = (UINT32 *)aligned_addr;  
}

void swap_buffers(){
    UINT32 *temp = frontBuffer;
    frontBuffer = backBuffer;
    backBuffer = temp;
}

void cleanup() {    
    frontBuffer = Physbase();
    Setscreen(frontBuffer, -1, -1);
    clear_screen(frontBuffer);
    printf("Cleanup complete: Screen set to frontBuffer at address %p\n", frontBuffer);
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


void game_loop(){
    UINT32 timeThen, timeNow, timeElapsed;
    Model model;

    init_buffers();
    init_model(&model);

    clear_screen(frontBuffer);
    clear_screen(backBuffer);

    timeThen = get_time();

    while (!check_exit_conditions(&model)){

        timeNow = get_time();
        timeElapsed = timeNow - timeThen;

        if (timeElapsed > 0){

            Setscreen(backBuffer, -1, -1);
            swap_buffers(); 

            while (get_time() == timeNow);  

            handle_input(&model);
            update_asteroids(&model);   

            render(backBuffer, &model);
           
            timeThen = timeNow;
        }
    }
}

int main(){
    game_loop();
    cleanup();
    return 0;
}