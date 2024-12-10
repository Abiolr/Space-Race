/*
* COMP 2659 Game File
* 
* Purpose: To manage the main game logic, including initialization, rendering, and cleanup.
* Authors: Patrick Dang, Abiola Raji
* Date: December 9, 2024
*/

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

/* Global quit flag */
int quit = FALSE;

/*
 * Function: main
 * ----------------
 * The entry point of the game. Initializes buffers, displays the splash screen, 
 * runs the game loop, and handles cleanup upon exit.
 *
 */
int main() {
    init_buffers();
    splash_screen();
    game_loop();
    cleanup();
    return 0;
}

/*
 * Function: game_loop
 * ---------------------
 * Implements the main game loop, managing rendering, input, and timing.
 */
void game_loop() {
    UINT32 timeThen, timeNow, timeElapsed;
    Model model;

    init_model(&model);

    clear_screen(frontBuffer, BLACK);
    clear_screen(backBuffer, BLACK);

    render(backBuffer, &model);
    Vsync();

    start_music();

    timeThen = get_time();

    while (!check_exit_conditions(&model)) {
        timeNow = get_time();
        timeElapsed = timeNow - timeThen;
        
        handle_input(&model);

        if (timeElapsed > 0) {
   
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

/*
 * Function: init_buffers
 * ------------------------
 * Initializes front and back buffers for double buffering.
 */
void init_buffers() {
    UINT32 aligned_addr;
    frontBuffer = get_video_base();

    aligned_addr = ((UINT32)buffer_storage + ALIGNMENT - 1) & ~(ALIGNMENT - 1);
    backBuffer = (UINT32 *)aligned_addr;
}

/*
 * Function: swap_buffers
 * ------------------------
 * Swaps the front and back buffers for rendering.
 */
void swap_buffers() {
    UINT32 *temp = frontBuffer;
    frontBuffer = backBuffer;
    backBuffer = temp;
}

/*
 * Function: cleanup
 * -------------------
 * Cleans up resources and waits for the user to exit the game.
 */
void cleanup() {    
    int input;
    frontBuffer = get_video_base();
    set_video_base(backBuffer);
    splash_screen();
    input = Cnecin();
    while (input != ESC) {
        input = Cnecin();
    }
}

/*
 * Function: get_time
 * --------------------
 * Retrieves the current system time from the hardware timer.
 *
 * Returns:
 *   Current time as a 32-bit unsigned integer.
 */
UINT32 get_time() {
    long *timer = (long *)0x462;
    long old_spp = Super(0);
    UINT32 timeNow = *timer;
    Super(old_spp);
    return timeNow;
}

/*
 * Function: check_exit_conditions
 * ---------------------------------
 * Checks whether the game should exit based on user input or game state.
 *
 * Parameters:
 *   model: A pointer to the Model structure.
 *
 * Returns:
 *   1 if the game should exit, 0 otherwise.
 */
int check_exit_conditions(Model *model) {
    return quit || model->lives <= 0;
}

/*
 * Function: handle_input
 * ------------------------
 * Handles user input to control the spaceship or exit the game.
 *
 * Parameters:
 *   model: A pointer to the Model structure.
 */
void handle_input(Model *model) {
    char input = NO_INPUT;

    if (Cconis()) {
        input = Cnecin();
    }

    if (input != NO_INPUT) {
        stop_sound();
        switch (input) {
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

/*
 * Function: splash_screen
 * -------------------------
 * Displays the splash screen and waits for user input to proceed.
 */
void splash_screen() {
    clear_screen(frontBuffer, WHITE);
    render_splash_screen(frontBuffer);
    Cnecin();
}
