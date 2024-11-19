#include <stdio.h>
#include <osbind.h>
#include "RENDER.H"
#include "MODEL.H"
#include "raster.h"
#include "EVENTS.H"

UINT32 buffer_storage[(BUFFER_SIZE + ALIGNMENT)];
UINT32 *frontBuffer;
UINT32 *backBuffer;

typedef struct Snapshot {
    int spaceship_x;
    int spaceship_y;
    int asteroid_positions[MAX_ASTEROIDS][2];
} Snapshot;

Snapshot snapshot = {0};

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
    printf("Died or exited game \n");
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

void clear_old_positions(UINT32 *buffer, Snapshot *snapshot, Model *model) {
    int i;

    for (i = 0; i < MAX_ASTEROIDS; i++) {
        clear_8_bitmap((UINT8 *)buffer, snapshot->asteroid_positions[i][0], snapshot->asteroid_positions[i][1]);
    }
}

void update_snapshot(Snapshot *snapshot, Model *model) {
    int i;

    for (i = 0; i < MAX_ASTEROIDS; i++) {
        snapshot->asteroid_positions[i][0] = model->asteroid[i].cur_x;
        snapshot->asteroid_positions[i][1] = model->asteroid[i].cur_y;
    }
}


void game_loop(){
    UINT32 timeThen, timeNow, timeElapsed;
    Model model;
    Snapshot snapshot = {0};

    init_buffers();
    init_model(&model);

    clear_screen(frontBuffer);
    clear_screen(backBuffer);

    timeThen = get_time();

    while (!check_exit_conditions(&model)){

        timeNow = get_time();
        timeElapsed = timeNow - timeThen;

        if (timeElapsed > 0){

            handle_input(&model);

            Setscreen(backBuffer, -1, -1);

            swap_buffers(); 

            while (get_time() == timeNow);

            clear_old_positions(backBuffer, &snapshot, &model);

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