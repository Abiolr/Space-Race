/*
* COMP 2659 Model File
* 
* Purpose: To handle the positioning and movement of objects in the game model.
* Authors: Patrick Dang, Abiola Raji
* Date: October 25, 2024
*/

#include "MODEL.H"

/*
 * Function: init_spaceship
 * -------------------------
 * Initializes the spaceship's position and movement state.
 *
 * Parameters:
 *   spaceship: A pointer to the Spaceship structure that needs to be initialized.
 *
 * Returns:
 *   This function does not return a value.
 *
 * Assumptions:
 *   The spaceship pointer is valid and points to an allocated Spaceship structure.
 */
void init_spaceship(Spaceship *spaceship)
{
    spaceship->cur_x = 320;             
    spaceship->cur_y = 350;      
    spaceship->prev_y = spaceship->cur_y;
    spaceship->delta_y = 0;         
}

/*
 * Function: init_asteroid
 * -------------------------
 * Initializes the position and movement speed of an asteroid.
 *
 * Parameters:
 *   asteroid: A pointer to the Asteroid structure that needs to be initialized.
 *   x: The initial x-coordinate of the asteroid.
 *   y: The initial y-coordinate of the asteroid.
 *   delta_x: The speed of the asteroid's movement in the x-direction.
 *
 * Returns:
 *   This function does not return a value.
 *
 * Assumptions:
 *   The asteroid pointer is valid and points to an allocated Asteroid structure.
 */
void init_asteroid(Asteroid *asteroid, unsigned int x, unsigned int y, int delta_x)
{
    asteroid->cur_x = x;                    
    asteroid->cur_y = y;
    asteroid->prev_x = asteroid->cur_x;
    asteroid->delta_x = delta_x;        
}

/*
 * Function: init_model
 * ---------------------
 * Initializes the game model, including the spaceship and a set of asteroids.
 *
 * Parameters:
 *   model: A pointer to the Model structure that needs to be initialized.
 *
 * Returns:
 *   This function does not return a value.
 *
 * Assumptions:
 *   The model pointer is valid and points to an allocated Model structure.
 */
void init_model(Model *model)
{
    int i;
    int j = 0;
    int k = 1;

    int asteroid_x_positions[] = {
        344, 8, 504, 216, 88, 600, 280, 168, 392, 24,
        440, 104, 376, 264, 152, 632, 200, 40, 536, 280,
        280, 392, 152, 616, 72, 328, 488, 440, 136, 392,
        440, 280, 24
    };

    init_spaceship(&model->spaceship);

    model->lives = 3;
    model->score = 0;

    for (i = 0; i < 33; i += 3)
    {
        int y = (j << 5) + 8;

        init_asteroid(&model->asteroid[i], asteroid_x_positions[i], y, 2 * k);
        init_asteroid(&model->asteroid[i + 1], asteroid_x_positions[i + 1], y, 2 * k);
        init_asteroid(&model->asteroid[i + 2], asteroid_x_positions[i + 2], y, 2 * k);

        j += 1;
        k *= -1;
    }
}

/*
 * Function: move_asteroid
 * -------------------------
 * Updates the x-position of an asteroid based on its movement speed.
 *
 * Parameters:
 *   asteroid: A pointer to the Asteroid structure whose position will be updated.
 *
 * Returns:
 *   This function does not return a value.
 *
 * Assumptions:
 *   The asteroid pointer is valid and points to an allocated Asteroid structure.
 */
void move_asteroid(Asteroid *asteroid)
{
    asteroid->cur_x += asteroid->delta_x;
}

/*
 * Function: move_spaceship
 * -------------------------
 * Updates the y-position of the spaceship based on its movement speed.
 *
 * Parameters:
 *   spaceship: A pointer to the Spaceship structure whose position will be updated.
 *
 * Returns:
 *   This function does not return a value.
 *
 * Assumptions:
 *   The spaceship pointer is valid and points to an allocated Spaceship structure.
 */
void move_spaceship(Spaceship *spaceship)
{
    spaceship->cur_y += spaceship->delta_y;
}
