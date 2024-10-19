#include <osbind.h>
#include "raster.h"
#include "events.h"
#include "model.h"

int main()
{
    Model model;
    init_model(&model);

    printf("Initial Spaceship position: x=%d, y=%d\n", model.spaceship.x, model.spaceship.y);

    move_spaceship_up(&model);
    move_spaceship(&model.spaceship);
    printf("Spaceship after moving up: x=%d, y=%d\n", model.spaceship.x, model.spaceship.y);

    move_spaceship_down(&model);
    move_spaceship(&model.spaceship);
    printf("Spaceship after moving down: x=%d, y=%d\n", model.spaceship.x, model.spaceship.y);

    update_asteroids(&model);
    printf("Asteroid[0] after move: x=%d, y=%d\n", model.asteroid[0].x, model.asteroid[0].y);

    check_collisions(&model);
    printf("Lives remaining: %d\n", model.lives);

    return 0;

/*
    int i;
    int j = 0;
    int k = 1;

    int x[] = {344, 8, 504, 216, 88, 600, 280, 168, 392, 24,
                440, 104, 376, 264, 152, 632, 200, 40, 536, 280,
                280, 392, 152, 616, 72, 328, 488, 440, 136, 392,
                440, 280, 24};
                
    clear_screen();

    for (i = 0; i < 33; i += 3)
    {
        int y = (j << 5) + 8;

        plot_asteroid(x[i], y);
        plot_asteroid(x[i+1], y);
        plot_asteroid(x[i+2], y);

        j += 1;
        }

    plot_number(FIRST_DIGIT,SCORE_ROW,4);
    plot_number(SECOND_DIGIT,SCORE_ROW,2);
    plot_number(THIRD_DIGIT,SCORE_ROW,0);

    plot_space_ship(320,350);
    
    plot_heart(610,50);
    plot_heart(600,50);
    plot_heart(580,50);
    return 0;
    */
}
