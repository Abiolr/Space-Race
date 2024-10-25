/*
* COMP 2659 Events File
* 
* Purpose: To handle all asynchronus, synchronus, and conditional events
* Authors: Patrick Dang, Abiola Raji
* Date: October 25, 2024
*/

#include <osbind.h>
#include "events.h"

void move_spaceship_up(Model *model){
    model->spaceship.delta_y = -2;    
    if (model->spaceship.y < 0){
        init_spaceship(&model->spaceship);
        point_scored(model);
    }
}

void move_spaceship_down(Model *model){
    model->spaceship.delta_y = 2;
    if (model->spaceship.y > 400){
        model->spaceship.y = 400;
    }
}

void stop_spaceship(Model *model){
    model->spaceship.delta_y = 0;
}

int check_collision(Spaceship *spaceship, Asteroid *asteroid) {
    return (spaceship->x < asteroid->x + 8 &&
            spaceship->x + 32 > asteroid->x &&
            spaceship->y < asteroid->y + ASTEROID_HEIGHT &&
            spaceship->y + SPACESHIP_HEIGHT > asteroid->y);
}

void handle_collison(Model *model, int i){
    if (check_collision(&model->spaceship, &model->asteroid[i])){
        init_spaceship(&model->spaceship);
        model->lives -= 1;
    }
}

void point_scored(Model *model){
    model->score += 1; 
}

void update_asteroids(Model *model){
    int i;

    for (i = 0; i < 33; i++)
    {
        move_asteroid(&model->asteroid[i]);
        handle_collison(model, i);
        if (model->asteroid[i].x > 640) 
        {
            model->asteroid[i].x = 0;
        }
        else if (model->asteroid[i].x < 0)
        {
            model->asteroid[i].x = 640;
        }
    }
}
