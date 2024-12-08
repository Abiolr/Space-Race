#include <stdio.h>
#include <osbind.h>
#include "RENDER.H"
#include "MODEL.H"
#include "PSG.H"
#include "EVENTS.H"
#include "raster.h"
#include "MUSIC.H"
#include "RAST_ASM.H"

UINT32 buffer_storage[(BUFFER_SIZE + ALIGNMENT)];
UINT32 *frontBuffer;
UINT32 *backBuffer;

void splash_screen();
void handle_input(Model *model);
int check_exit_conditions(Model *model);
UINT32 get_time();
void cleanup();
void swap_buffers();
void init_buffers();
void game_loop();

int quit = FALSE;

int main(){
    init_buffers();
    splash_screen();
    game_loop();
    cleanup();
    return 0;
}

void game_loop(){
    UINT32 timeThen, timeNow, timeElapsed;
    Model model;

    init_model(&model);

    clear_screen(frontBuffer, BLACK);
    clear_screen(backBuffer, BLACK);

    render(backBuffer, &model);
    Vsync();

    stop_sound();
    start_music();

    timeThen = get_time();

    while (!check_exit_conditions(&model)){

        timeNow = get_time();
        timeElapsed = timeNow - timeThen;

        if (timeElapsed > 0){

            handle_input(&model);          

            set_video_base(backBuffer);

            swap_buffers(); 

            while (get_time() == timeNow);

            update_asteroids(&model); 
            render(backBuffer, &model); 
            update_music(timeElapsed);
     
            timeThen = timeNow;
        }
    }
}

void init_buffers() {
    UINT32 aligned_addr;
    frontBuffer = get_video_base();

    aligned_addr = ((UINT32)buffer_storage + ALIGNMENT - 1) & ~(ALIGNMENT - 1);
    backBuffer = (UINT32 *)aligned_addr;  
}

void swap_buffers(){
    UINT32 *temp = frontBuffer;
    frontBuffer = backBuffer;
    backBuffer = temp;
}

void cleanup() {    
    int input;
    frontBuffer = get_video_base();
    set_video_base(backBuffer);
    splash_screen();
    input = Cnecin();
    while (input != ESC){
        input = Cnecin();
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
    char input = NO_INPUT;

    if (Cconis()){
        input = Cnecin();
    }

    if (input != NO_INPUT){
        switch(input) {
            case 'w':
            move_spaceship_up(model);
            break;
            case 's':
            move_spaceship_down(model);
            break;
            case ESC:
            quit = TRUE;
            break;
            } 
        }
}

void splash_screen(){
    clear_screen(frontBuffer, WHITE);
    render_splash_screen(frontBuffer);
    Cnecin();
}