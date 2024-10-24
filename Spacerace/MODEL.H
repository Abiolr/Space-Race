#ifndef MODEL_H
#define MODEL_H
#include "RASTER.H"

typedef struct
{
    unsigned int x, y;
    int delta_y;
} Spaceship;

typedef struct
{
    unsigned int x, y;
    int delta_x;
} Asteroid;


typedef struct {
    Spaceship spaceship;        
    Asteroid asteroid[33];      
    int lives;
    int score;
} Model;

/*
* Sets the spaceship's coordinates to its starting position, (320,350)
*/
void init_spaceship(Spaceship *spaceship);

/*
* Sets the asteroids' coordinates to their starting positions
* x - a randomly generated x coordinate between 8 and 632
* y - a fixed y coordinate for each individual asteroid
* delta_x - the rate of change of each asteroid
*/
void init_asteroid(Asteroid *asteroid, unsigned int x, unsigned int y, int delta_x);

/*
* Plots the spaceships and asteroids to their starting positions
*/
void init_model(Model *model);

/*
* Moves a single asteroid x spaces
*/
void move_asteroid(Asteroid *asteroid);

/*
* Moves the spaceship y spaces
*/
void move_spaceship(Spaceship *spaceship);

#endif