/**
 * GAME_LOOP.C file
 * A simple game engine loop for rendering and updating game state.
 *
 * Purpose: This program implements a basic game loop that handles user input,
 * updates game models, and renders the game state 
 * to the screen in a single-buffered environment.
 *
 * Authors: - Abiola Raji Patrick Dang
 * 
 * Date: Nov 18, 2024
 */

#include <stdio.h>
#include <osbind.h>
#include "RENDER.H"
#include "MODEL.H"
#include "raster.h"
#include "EVENTS.H"

int quit = FALSE;

/**
 * Main function. Entry point for the game engine.
 * 
 * It initializes the game loop and exits gracefully upon completion.
 * 
 * @return 0 on successful execution.
 */
int main(){
    game_loop();
    return 0;
}

/**
 * Core game loop for handling game updates and rendering.
 * 
 * The loop tracks time, processes user input, updates the game model,
 * and renders the game state until exit conditions are met.
 */
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

/**
 * Gets the current system time from a memory address.
 * 
 * @return Current system time in ticks.
 */
UINT32 get_time(){
    long *timer = (long *)0x462;
    long old_spp = Super(0);
    UINT32 timeNow = *timer;
    Super(old_spp);
    return timeNow;
}

/**
 * Checks whether the game should exit.
 * 
 * Exit conditions are met if the global quit flag is set or 
 * the player has no remaining lives.
 * 
 * @param model Pointer to the game model.
 * @return Non-zero (true) if the game should exit; otherwise, zero (false).
 */
int check_exit_conditions(Model *model) {
    return quit || model->lives <= 0;
}

/**
 * Handles user input and updates the game model accordingly.
 * 
 * The function reads input from the console, processes specific
 * keypresses (e.g., 'w', 's', and ESC), and updates the spaceship's position
 * or sets the quit flag to exit the game loop.
 * 
 * @param model Pointer to the game model containing the spaceship state.
 */
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
