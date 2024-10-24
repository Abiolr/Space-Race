#ifndef EVENTS_H
#define EVENTS_H
#include "MODEL.H"

void move_spaceship_up(Model *model);

void move_spaceship_down(Model *model);

void stop_spaceship(Model *model);

void spaceship_collison(Model *model);

void point_scored(Model *model);

void update_asteroids(Model *model);

#endif