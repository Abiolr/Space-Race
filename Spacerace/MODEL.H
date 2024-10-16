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

#endif