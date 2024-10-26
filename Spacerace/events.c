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
    if (model->spaceship.y = -4){
        stop_spaceship(model);
        model->spaceship.y = 350;
        point_scored(model);
    }
    spaceship_collision(model);
}

void move_spaceship_down(Model *model){
    model->spaceship.delta_y = 2;
    if (model->spaceship.y > 400){
        stop_spaceship(model);
        model->spaceship.y = 398;
    }
    spaceship_collision(model);
}

void stop_spaceship(Model *model){
    model->spaceship.delta_y = 0;
    spaceship_collision(model);
}

int check_collision(Spaceship *spaceship, Asteroid *asteroid){
    return (spaceship->x < asteroid->x + 8 &&
            spaceship->x + 32 > asteroid->x &&
            spaceship->y < asteroid->y + ASTEROID_HEIGHT &&
            spaceship->y + SPACESHIP_HEIGHT > asteroid->y);
}

void asteroid_collision(Model *model, int i){
    if (check_collision(&model->spaceship, &model->asteroid[i])){
        model->spaceship.y = 350;
        model->spaceship.delta_y = 0;
        model->lives -= 1;
    }
}

void spaceship_collision(Model *model){
    int i;
    for (i = 0; i < 33; i += 1){
        if(check_collision(&model->spaceship, &model->asteroid[i])){
            model->spaceship.y = 350;
        }
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
        asteroid_collision(model, i);
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
