/*
* COMP 2659 Events File
* 
* Purpose: To handle all asynchronus, synchronus, and conditional events
* Authors: Patrick Dang, Abiola Raji
* Date: October 25, 2024
*/

#include "events.h"

void move_spaceship_up(Model *model){
    clear_spaceship(model->spaceship.x,model->spaceship.y);
    model->spaceship.delta_y = 10;
    plot_spaceship(model->spaceship.x,model->spaceship.y);
}

void move_spaceship_down(Model *model){
    model->spaceship.delta_y = -2;
}
void stop_spaceship(Model *model){
    model->spaceship.delta_y = 0;
}

void spaceship_collison(Model *model){
    reset_spaceship(&model->spaceship);
    model->lives -= 1;
}

void point_scored(Model *model){
    model->score += 1; 
}

void update_asteroids(Model *model){
    int i;

    for (i = 0; i < 33; i++)
    {
        move_asteroid(&model->asteroid[i]);

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