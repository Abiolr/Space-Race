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

void move_asteroid(Asteroid *asteroid)
{
    asteroid->x += asteroid->delta_x;   /*the x is moves delta x spaces*/
}

void move_spaceship(Spaceship *spaceship)
{
    spaceship->y += spaceship->delta_y;     /*the y is moves delta y spaces*/
}

