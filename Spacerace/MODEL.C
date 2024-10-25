/*
* COMP 2659 Model File
* 
* Purpose: To handle the positioning and movement of objects
* Authors: Patrick Dang, Abiola Raji
* Date: October 25, 2024
*/

#include "model.h"

void init_spaceship(Spaceship *spaceship)
{
    spaceship->x = 320;             /*start middle of screen*/
    spaceship->y = 350;             /*start near bottom of screen*/
    spaceship->delta_y = 0;         /*not moving at start*/
}

void init_asteroid(Asteroid *asteroid, unsigned int x, unsigned int y, int delta_x)
{
    asteroid->x = x;                    
    asteroid->y = y;                    
    asteroid->delta_x = delta_x;        /*add a constant speed later*/
}

void init_model(Model *model)
{
    int i;
    int j = 0;
    int k = 1;

    int asteroid_x_positions[] = {344, 8, 504, 216, 88, 600, 280, 168, 392, 24,
                                    440, 104, 376, 264, 152, 632, 200, 40, 536, 280,
                                    280, 392, 152, 616, 72, 328, 488, 440, 136, 392,
                                    440, 280, 24};

    init_spaceship(&model->spaceship);

    model->lives = 3;
    model->score = 0;

    for (i = 0; i < 33; i += 3)
    {
        int y = (j << 5) + 8;

        init_asteroid(&model->asteroid[i], asteroid_x_positions[i], y, 2 * k);
        init_asteroid(&model->asteroid[i+1], asteroid_x_positions[i+1], y, 2 * k);
        init_asteroid(&model->asteroid[i+2], asteroid_x_positions[i+2], y, 2 * k);

        j += 1;
        k *= -1;
        }
}

void move_asteroid(Asteroid *asteroid)
{
    asteroid->x += asteroid->delta_x;   /*the x is moves delta x spaces*/
}

void move_spaceship(Spaceship *spaceship)
{
    spaceship->y += spaceship->delta_y;     /*the y is moves delta y spaces*/
}
