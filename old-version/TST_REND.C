#include <stdio.h>
#include <osbind.h>
#include "RENDER.H"
#include "MODEL.H"
#include "EVENTS.C"
#include "raster.h"


int main(){

    char input;

    Model model;
    init_model(&model);
    clear_screen();

    input = Cnecin();

    while (input != ESC)
    {
        switch(input) {
            case w:
            move_spaceship_up(&model);
            move_spaceship(&model.spaceship);
            render(&model);
            break;
            case s:
            move_spaceship_down(&model);
            move_spaceship(&model.spaceship);
            render(&model);
            break;
            case SPACE:
            update_asteroids(&model);
            render(&model);
            break;
            }
        input = Cnecin();
    }
    return 0;
}
