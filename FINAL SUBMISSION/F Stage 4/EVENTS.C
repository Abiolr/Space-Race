/*
* COMP 2659 Events File
* 
* Purpose: To handle all asynchronous, synchronous, and conditional events in the game.
* Authors: Patrick Dang, Abiola Raji
* Date: October 25, 2024
*/

#include <osbind.h>
#include "EVENTS.H"

/*
 * Function: move_spaceship_up
 * -----------------------------
 * Moves the spaceship upwards by updating its vertical speed.
 * If the spaceship reaches a certain height, it stops and the score is updated.
 *
 * Parameters:
 *   model: A pointer to the Model structure containing the spaceship data.
 */
void move_spaceship_up(Model *model) {
    model->spaceship.prev_y = model->spaceship.cur_y;
    model->spaceship.delta_y = SPACESHIP_UP_SPEED;    
    if (model->spaceship.cur_y == 0) {

        model->spaceship.cur_y = SPACESHIP_START_Y;
        model->score += 1; 
    }
    spaceship_collision(model); 
    move_spaceship(&model->spaceship);
}

/*
 * Function: move_spaceship_down
 * -------------------------------
 * Moves the spaceship downwards by updating its vertical speed.
 * If the spaceship reaches a certain height, it stops at the bottom boundary.
 *
 * Parameters:
 *   model: A pointer to the Model structure containing the spaceship data.
 */
void move_spaceship_down(Model *model) {
    model->spaceship.prev_y = model->spaceship.cur_y;
    model->spaceship.delta_y = SPACESHIP_DOWN_SPEED;
    if (model->spaceship.cur_y > SPACESHIP_START_Y) {
        model->spaceship.cur_y = SPACESHIP_START_Y;
    }
    spaceship_collision(model);
    move_spaceship(&model->spaceship);
}


/*
 * Function: check_collision
 * --------------------------
 * Checks for a collision between the spaceship and an asteroid.
 *
 * Parameters:
 *   spaceship: A pointer to the Spaceship structure.
 *   asteroid: A pointer to the Asteroid structure.
 */
int check_collision(Spaceship *spaceship, Asteroid *asteroid) {
    return (spaceship->cur_x < asteroid->cur_x + 6 &&
            spaceship->cur_x + 30 > asteroid->cur_x &&
            spaceship->cur_y < asteroid->cur_y + ASTEROID_HEIGHT &&
            spaceship->cur_y + SPACESHIP_HEIGHT > asteroid->cur_y);
}

/*
 * Function: asteroid_collision
 * ------------------------------
 * Checks for a collision between the spaceship and a specific asteroid.
 * Updates the model state if a collision occurs.
 *
 * Parameters:
 *   model: A pointer to the Model structure containing the spaceship and asteroids.
 *   i: The index of the asteroid being checked for collision.
 */
void asteroid_collision(Model *model, int i) {
    if (check_collision(&model->spaceship, &model->asteroid[i])) {
        model->spaceship.cur_y = SPACESHIP_START_Y;
        model->spaceship.delta_y = 0;
        model->lives -= 1;
    }
}

/*
 * Function: spaceship_collision
 * -------------------------------
 * Checks for collisions between the spaceship and all asteroids.
 * Resets the spaceship's position if a collision occurs.
 *
 * Parameters:
 *   model: A pointer to the Model structure containing the spaceship and asteroids.
 */
void spaceship_collision(Model *model) {
    int i;
    for (i = 0; i < MAX_ASTEROIDS; i += 1) {
        if (check_collision(&model->spaceship, &model->asteroid[i])) {
    
            model->spaceship.cur_y = SPACESHIP_START_Y;
            model->spaceship.delta_y = 0;
            model->lives -= 1;
        }
    }
}


/*
 * Function: update_asteroids
 * ----------------------------
 * Updates the position of each asteroid and checks for collisions with the spaceship.
 * Resets the position of asteroids that go off-screen.
 *
 * Parameters:
 *   model: A pointer to the Model structure containing the asteroids.
 */
void update_asteroids(Model *model) {
    int i;

    for (i = 0; i < MAX_ASTEROIDS; i++) {
        model->asteroid[i].prev_x = model->asteroid[i].cur_x;
        move_asteroid(&model->asteroid[i]);
        asteroid_collision(model, i);
        if (model->asteroid[i].cur_x > END_RIGHT_SCREEN) {
            model->asteroid[i].cur_x = END_LEFT_SCREEN;
        } else if (model->asteroid[i].cur_x < END_LEFT_SCREEN) {
            model->asteroid[i].cur_x = END_RIGHT_SCREEN;
        }
    }
}
