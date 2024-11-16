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
 *
 * Returns:
 *   This function does not return a value.
 *
 * Assumptions:
 *   The model pointer is valid and points to an allocated Model structure.
 * To do:
 *  Implement logic to increase speed of asteroids after each score
 */
void move_spaceship_up(Model *model) {
    model->spaceship.prev_y = model->spaceship.cur_y;
    model->spaceship.delta_y = -5;    
    if (model->spaceship.cur_y == 0) {
        stop_spaceship(model);
        model->spaceship.cur_y = 350;
        point_scored(model);
    }
    spaceship_collision(model);
}

/*
 * Function: move_spaceship_down
 * -------------------------------
 * Moves the spaceship downwards by updating its vertical speed.
 * If the spaceship reaches a certain height, it stops at the bottom boundary.
 *
 * Parameters:
 *   model: A pointer to the Model structure containing the spaceship data.
 *
 * Returns:
 *   This function does not return a value.
 *
 * Assumptions:
 *   The model pointer is valid and points to an allocated Model structure.
 */
void move_spaceship_down(Model *model) {
    model->spaceship.prev_y = model->spaceship.cur_y;
    model->spaceship.delta_y = 5;
    if (model->spaceship.cur_y > 400) {
        stop_spaceship(model);
        model->spaceship.cur_y = 398;
    }
    spaceship_collision(model);
}

/*
 * Function: stop_spaceship
 * --------------------------
 * Stops the spaceship by setting its vertical speed to zero and checks for collisions.
 *
 * Parameters:
 *   model: A pointer to the Model structure containing the spaceship data.
 *
 * Returns:
 *   This function does not return a value.
 *
 * Assumptions:
 *   The model pointer is valid and points to an allocated Model structure.
 */
void stop_spaceship(Model *model) {
    model->spaceship.delta_y = 0;
    spaceship_collision(model);
}

/*
 * Function: check_collision
 * --------------------------
 * Checks for a collision between the spaceship and an asteroid.
 *
 * Parameters:
 *   spaceship: A pointer to the Spaceship structure.
 *   asteroid: A pointer to the Asteroid structure.
 *
 * Returns:
 *   Returns 1 if there is a collision; otherwise, returns 0.
 *
 * Assumptions:
 *   Both spaceship and asteroid pointers are valid and point to allocated structures.
 */
int check_collision(Spaceship *spaceship, Asteroid *asteroid) {
    return (spaceship->cur_x < asteroid->cur_x + 8 &&
            spaceship->cur_x + 32 > asteroid->cur_x &&
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
 *
 * Returns:
 *   This function does not return a value.
 *
 * Assumptions:
 *   The model pointer is valid and points to an allocated Model structure.
 */
void asteroid_collision(Model *model, int i) {
    if (check_collision(&model->spaceship, &model->asteroid[i])) {
        model->spaceship.cur_y = 350;
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
 *
 * Returns:
 *   This function does not return a value.
 *
 * Assumptions:
 *   The model pointer is valid and points to an allocated Model structure.
 */
void spaceship_collision(Model *model) {
    int i;
    for (i = 0; i < 33; i += 1) {
        if (check_collision(&model->spaceship, &model->asteroid[i])) {
            model->spaceship.cur_y = 350;
            model->lives -= 1;
        }
    }
}

/*
 * Function: point_scored
 * ------------------------
 * Updates the score in the model when the player scores a point.
 *
 * Parameters:
 *   model: A pointer to the Model structure containing the score.
 *
 * Returns:
 *   This function does not return a value.
 *
 * Assumptions:
 *   The model pointer is valid and points to an allocated Model structure.
 */
void point_scored(Model *model) {
    model->score += 1; 
}

/*
 * Function: update_asteroids
 * ----------------------------
 * Updates the position of each asteroid and checks for collisions with the spaceship.
 * Resets the position of asteroids that go off-screen.
 *
 * Parameters:
 *   model: A pointer to the Model structure containing the asteroids.
 *
 * Returns:
 *   This function does not return a value.
 *
 * Assumptions:
 *   The model pointer is valid and points to an allocated Model structure.
 */
void update_asteroids(Model *model) {
    int i;

    for (i = 0; i < 33; i++) {
        model->asteroid[i].prev_x = model->asteroid[i].cur_x;
        move_asteroid(&model->asteroid[i]);
        asteroid_collision(model, i);
        if (model->asteroid[i].cur_x > 640) {
            model->asteroid[i].cur_x = 0;
        } else if (model->asteroid[i].cur_x < 1) {
            model->asteroid[i].cur_x = 640;
        }
    }
}