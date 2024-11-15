#include <stdio.h>
#include <osbind.h>
#include <stdlib.h>
#include "RENDER.H"
#include "MODEL.H"
#include "raster.h"
#include "EVENTS.H"


UINT8 buffer_storage[(BUFFER_SIZE + ALIGNMENT) / sizeof(UINT32)];
UINT8 *frontBuffer;
UINT8 *backBuffer;

int quit = FALSE;

void init_buffers() {
    UINT32 aligned_addr;
    frontBuffer = (UINT8 *) Physbase();

    aligned_addr = ((UINT32)buffer_storage + ALIGNMENT - 1) & ~(ALIGNMENT - 1);
    backBuffer = (UINT8 *)aligned_addr;  
}

void swap_buffers(){
    UINT8 *temp = frontBuffer;
    frontBuffer = backBuffer;
    backBuffer = temp;
}

void cleanup() {
    clear_screen((UINT32 *)backBuffer);
    Setscreen((UINT8 *)frontBuffer, (void *)-1, (void *)-1);  
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
    clear_screen((UINT32 *)frontBuffer);
    init_model(&model);
    
    render(backBuffer, &model);
    Setscreen((void *)frontBuffer, (void *)-1, (void *)-1);
    timeThen = get_time();

    while (!check_exit_conditions(&model)){
        handle_input(&model);
        
        timeNow = get_time();
        timeElapsed = timeNow - timeThen;

        if (timeElapsed > 0){

            update_asteroids(&model);
            render(backBuffer, &model);  

            Setscreen((UINT8 *)backBuffer, (void *)-1, (void *)-1);

            while (get_time() == timeNow);      

            swap_buffers(); 

            timeThen = timeNow;
        }
    }
}

int main(){
    game_loop();
    cleanup();
    return 0;
}