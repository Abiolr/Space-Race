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
    if(Cconis()){
        char input = Cnecin();
        if (input == 119){
            model->spaceship.delta_y = -2;
        } 
    }
    else{
        stop_spaceship(model);
    }
}

void move_spaceship_down(Model *model){
    if(Cconis()){
        char input = Cnecin();
        if (input == 114){
            model->spaceship.delta_y = 2;
        } 
    } 
    else{
        stop_spaceship(model);
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

void handle_collison(Model *model){
    if (check_collision){
        init_spaceship(model);
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