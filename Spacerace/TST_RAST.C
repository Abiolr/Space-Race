#include <osbind.h>
#include "raster.h"
#include "bitmap.h"


int main()
{
   
/*
    for (x = 0 ; x < SCREEN_WIDTH; x += 64)
    {
        for (y = 0; y < SCREEN_HEIGHT; y += 32)
        {
            plot_bitmap_32(FB32, x, y, rocket_bitmap, ROCKET_HEIGHT);
        }
    }
*/
    clear_screen();
    plot_number(288,10,number_one);
    plot_number(320,10,number_two);
    plot_number(352,10,number_three);
    plot_space_ship(320,350);
    plot_asteroid(110, 300);
    plot_asteroid(302, 300);
    plot_asteroid(200, 300);
    plot_heart(610,10);
    plot_heart(580,10);
    plot_heart(550,10);
    return 0;
}
