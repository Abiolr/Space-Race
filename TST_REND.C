#include <stdio.h>
#include <osbind.h>
#include "RENDER.H"
#include "MODEL.H"
#include "EVENTS.C"
#include "raster.h"
#include "types.h"


int main(){

    char input = NO_INPUT;

    Model model;
    init_model(&model);
    clear_screen();
    render(&model);
    input = Cnecin();

    while (input != ESC)
    {
        Vsync();
        if (Cconis()){
            input = Cnecin();
        }
        else{
            input = NO_INPUT; 
        }

        update_asteroids(&model);
        render(&model);

        if (input != NO_INPUT){
            switch(input) {
                case w:
                move_spaceship_up(&model);
                move_spaceship(&model.spaceship);
                break;
                case s:
                move_spaceship_down(&model);
                move_spaceship(&model.spaceship);
                break;
                }
            }
    }
    return 0;
}