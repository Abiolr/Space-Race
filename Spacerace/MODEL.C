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
    init_spaceship(&model->spaceship);

    int i;
    int j = 0;
    int k = 1;

    int x[] = {344, 8, 504, 216, 88, 600, 280, 168, 392, 24,
                440, 104, 376, 264, 152, 632, 200, 40, 536, 280,
                280, 392, 152, 616, 72, 328, 488, 440, 136, 392,
                440, 280, 24, 488, 88};

    for (i = 0; i < 33; i += 3)
    {
        int y = (j << 5) + 8;

        init_asteroid(&model->asteroid, x[i], y, 2 * k);
        init_asteroid(&model->asteroid, x[i+1], y, 2 * k);
        init_asteroid(&model->asteroid, x[i+2], y, 2 * k);

        j += 1;
        k *= -1;
        }
    
    int lives = 3;
    int score = 0;
}

void move_asteroid(Asteroid *asteroid)
{
    asteroid->x += asteroid->delta_x;   /*the x is moves delta x spaces*/
}

void move_spaceship(Spaceship *spaceship)
{
    spaceship->y += spaceship->delta_y;     /*the y is moves delta y spaces*/
}

