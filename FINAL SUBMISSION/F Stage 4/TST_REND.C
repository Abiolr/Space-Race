#include <stdio.h>
#include <osbind.h>
#include "RENDER.H"
#include "MODEL.H"
#include "EVENTS.C"
#include "raster.h"
#include "types.h"

UINT32 *frontbuffer;


int main(){

    

    char input = NO_INPUT;
    Model model;

    frontbuffer = Physbase();

    
    init_model(&model);
    clear_screen(frontbuffer, BLACK);
    render(frontbuffer, &model);
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
        render(frontbuffer, &model);

        if (input != NO_INPUT){
            switch(input) {
                case w:
                move_spaceship_up(&model);
                break;
                case s:
                move_spaceship_down(&model);
                break;
                }
            }
    }
    return 0;
}