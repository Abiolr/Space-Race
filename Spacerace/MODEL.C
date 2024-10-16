#include "model.h"

void init_spaceship(Spaceship *spaceship)
{
    spaceship->x = 320;             /*start middle of screen*/
    spaceship->y = 350;             /*start near bottom of screen*/
    spaceship->delta_y = 0;         /*not moving at start*/
}

void init_asteroid(Asteroid *asteroid, unsigned int x, unsigned int y, int delta_x)
{
    asteroid->x = x;                    /*find a way to randomize positon*/
    asteroid->y = y;                    /*find a way to randomize positon*/
    asteroid->delta_x = delta_x;        /*add a constant speed later*/
}

void init_model(Model *model)
{
    init_spaceship(&model->spaceship);

    int i;
    int j = 0;
    int k = 1;

    int x[] = {0, 8, 16, 24, 32, 40, 48, 56, 64, 72,
                80, 88, 96, 104, 112, 120, 128, 136, 144, 152,
                160, 168, 176, 184, 192, 200, 208, 216, 224, 232,
                240, 248, 256, 264, 272, 280, 288, 296, 304, 312,
                320};

    for (i = 0; i < 42; i += 3)
    {
        int y = 32 * j >> + 8;

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

