#ifndef MODEL_H
#define MODEL_H


typedef struct
{
    unsigned int cur_x, cur_y, prev_y;
    int delta_y;
} Spaceship;

typedef struct
{
    unsigned int cur_x, cur_y, prev_x;
    int delta_x;
} Asteroid;


typedef struct {
    Spaceship spaceship;        
    Asteroid asteroid[33];      
    int lives;
    int score;
} Model;

void init_spaceship(Spaceship *spaceship);

void init_asteroid(Asteroid *asteroid, unsigned int x, unsigned int y, int delta_x);

void init_model(Model *model);

void move_asteroid(Asteroid *asteroid);

void move_spaceship(Spaceship *spaceship);

#endif
