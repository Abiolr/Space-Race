#ifndef MODEL_H
#define MODEL_H

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
    Asteroid asteroid[40];      
    int lives;
    int score;
} Model;

void init_spaceship(Spaceship *spaceship);

void init_asteroid(Asteroid *asteroid, unsigned int x, unsigned int y, int delta_x);

void move_asteroid(Asteroid *asteroid);

void move_spaceship(Spaceship *spaceship);


#endif