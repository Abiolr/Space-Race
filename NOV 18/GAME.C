/**
 * COMP 2659 main.c file
 * A simple game engine for rendering a spaceship and asteroids with double buffering.
 *
 * Purpose: This program implements a basic game loop that handles spaceship and asteroid interactions,
 * updates the display using double buffering, and handles user input. The game ends when
 * the player quits or loses all lives.
 *
 * Authors: - Abiola Raji Patrick Dang
 * 
 * 
 * 
 * Date: Nov 18, 2024
 */

#include <stdio.h>
#include <osbind.h>
#include "RENDER.H"
#include "MODEL.H"
#include "raster.h"
#include "EVENTS.H"

/* Double buffering setup */
UINT32 buffer_storage[(BUFFER_SIZE + ALIGNMENT)];
UINT32 *frontBuffer;
UINT32 *backBuffer;

/* Snapshot structure to track asteroid and spaceship positions */
typedef struct Snapshot {
    int spaceship_x;
    int spaceship_y;
    int asteroid_positions[MAX_ASTEROIDS][2];
} Snapshot;

/* Quit flag */
int quit = FALSE;

/**
 * Main program. Starts the game loop and handles cleanup.
 * 
 * @returns 0 to exit.
 */
int main(){
    game_loop();
    cleanup();
    return 0;
}

/**
 * Main game loop that handles rendering, input, and game updates.
 */
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

/**
 * Initializes the double buffering system by setting up front and back buffers.
 */
void init_buffers() {
    UINT32 aligned_addr;
    frontBuffer = Physbase();
    aligned_addr = ((UINT32)buffer_storage + ALIGNMENT - 1) & ~(ALIGNMENT - 1);
    backBuffer = (UINT32 *)aligned_addr;  
}

/**
 * Swaps the front and back buffers for double buffering.
 */
void swap_buffers(){
    UINT32 *temp = frontBuffer;
    frontBuffer = backBuffer;
    backBuffer = temp;
}

/**
 * Cleans up the screen and resets the environment after the game ends.
 */
void cleanup() {    
    frontBuffer = Physbase();
    Setscreen(frontBuffer, -1, -1);
    clear_screen(frontBuffer);
    printf("Game over\n");
}

/**
 * Enters supervisor mode to point to clock in memory.
 * 
 * @return Current system time.
 */
UINT32 get_time(){
    long *timer = (long *)0x462;
    long old_spp = Super(0);
    UINT32 timeNow = *timer;
    Super(old_spp);
    return timeNow;
}

/**
 * Checks if the game should exit based on ESC key press or game over conditions.
 * 
 * @param model Pointer to the game model.
 * @return true if the game should exit; otherwise, false.
 */
int check_exit_conditions(Model *model) {
    return quit || model->lives <= 0;
}

/**
 * Handles user input to control the spaceship and game state.
 * 
 * @param model Pointer to the game model containing the spaceship state.
 */
void handle_input(Model *model){
    char input;
    if (Cconis()){
        input = Cnecin();
    } else {
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

/**
 * Clears the old positions of asteroids from the buffer.
 * 
 * @param buffer Pointer to the buffer where the screen is being rendered.
 * @param snapshot Pointer to the snapshot containing asteroid positions.
 * @param model Pointer to the game model containing the current game state.
 *
 * TO DO: clearing seems to make game run choppy, but not clearing leaves asteroid trails.
 * need to fix with proper implementation of snapshots between buffers
 */
void clear_old_positions(UINT32 *buffer, Snapshot *snapshot, Model *model) {
    int i;
    for (i = 0; i < MAX_ASTEROIDS; i++) {
        clear_8_bitmap((UINT8 *)buffer, snapshot->asteroid_positions[i][0], snapshot->asteroid_positions[i][1]);
    }
}

/**
 * Updates the snapshot structure with the current positions of asteroids.
 * 
 * @param snapshot Pointer to the snapshot to update.
 * @param model Pointer to the game model containing the current game state.
 */
void update_snapshot(Snapshot *snapshot, Model *model) {
    int i;
    for (i = 0; i < MAX_ASTEROIDS; i++) {
        snapshot->asteroid_positions[i][0] = model->asteroid[i].cur_x;
        snapshot->asteroid_positions[i][1] = model->asteroid[i].cur_y;
    }
}
