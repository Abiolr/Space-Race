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
#include "TYPES.H"

int main()
{
    char input;

    Model model;
    init_model(&model);

    printf("Initial Spaceship position: x=%d, y=%d\n", model.spaceship.x, model.spaceship.y);
    printf("Asteroid[31] before moving: x=%d, y=%d\n", model.asteroid[31].x, model.asteroid[31].y);

    input = Cnecin();

    while (input != ESC)
    {
        switch(input) {
            case w:
            move_spaceship_up(&model);
            move_spaceship(&model.spaceship);
            printf("Spaceship after moving up: x=%d, y=%d\n", model.spaceship.x, model.spaceship.y);
            break;
            case s:
            move_spaceship_down(&model);
            move_spaceship(&model.spaceship);
            printf("Spaceship after moving down: x=%d, y=%d\n", model.spaceship.x, model.spaceship.y);
            break;
            case SPACE:
            update_asteroids(&model);
            printf("Asteroid[31] after moving: x=%d, y=%d\n", model.asteroid[31].x, model.asteroid[31].y);
            break;
            }
            
        input = Cnecin();
    }
    return 0;
}
