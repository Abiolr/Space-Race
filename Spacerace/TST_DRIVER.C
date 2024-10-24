/*
* COMP 2659 Test Driver File
* 
* Purpose: To handle the testing of the model and the events
* Authors: Patrick Dang, Abiola Raji
* Date: October 25, 2024
*/

#include <stdio.h>
#include <osbind.h>
#include "events.h"

int main2()
{
    Model model;
    init_model(&model);

    printf("Initial Spaceship position: x=%d, y=%d\n", model.spaceship.x, model.spaceship.y);

    move_spaceship_up(&model);
    move_spaceship(&model.spaceship);
    printf("Spaceship after moving up: x=%d, y=%d\n", model.spaceship.x, model.spaceship.y);

    move_spaceship_down(&model.spaceship);
    move_spaceship(&model.spaceship);
    printf("Spaceship after moving down: x=%d, y=%d\n", model.spaceship.x, model.spaceship.y);

    return 0;
}
