#include "events.h"

void move_spaceship_up(Model *model){
    model->spaceship.delta_y = 2;
}

void move_spaceship_up(Model *model){
    model->spaceship.delta_y = -2;
}
void stop_spaceship_up(Model *model){
    model->spaceship.delta_y = 0;
}

void spaceship_collison(Model *model){
    reset_spaceship(model->spaceship);
    model->lives -= 1;
}

void point_scored(Model *model){
    model->score += 1; 
}

void update_asteroids(Model *model)
{
    for (int i = 0; i < 33; i++)
    {
        move_asteroid(&model->asteroid[i]);

        // Wrap asteroids around the screen if they go off the edge
        if (model->asteroid[i].x > 640)  // Assuming 640 is screen width
        {
            model->asteroid[i].x = 0;
        }
        else if (model->asteroid[i].x < 0)
        {
            model->asteroid[i].x = 640;
        }
    }
}