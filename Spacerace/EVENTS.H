#ifndef EVENTS_H
#define EVENTS_H
#include "MODEL.H"
#include "TYPES.H"

void move_spaceship_up(Model *model);

void move_spaceship_down(Model *model);

void stop_spaceship(Model *model);

int check_collision(Spaceship *spacship, Asteroid *asteroid);

void asteroid_collision(Model *model, int i);

void spaceship_collision(Model *model);

void point_scored(Model *model);

void update_asteroids(Model *model);

#endif
