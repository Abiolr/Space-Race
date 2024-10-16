#include <osbind.h>
#include "raster.h"
#include "bitmap.h"


int main()
{

    int i;
    int j = 0;
    int k = 1;

    int x[] = {344, 8, 504, 216, 88, 600, 280, 168, 392, 24,
                440, 104, 376, 264, 152, 632, 200, 40, 536, 280,
                280, 392, 152, 616, 72, 328, 488, 440, 136, 392,
                440, 280, 24, 488, 88};
                
    clear_screen();
    plot_number(610,10,number_one);
    plot_number(580,10,number_two);
    plot_number(550,10,number_three);
    plot_space_ship(320,350);


    for (i = 0; i < 33; i += 3)
    {
        int y = (j << 5) + 8;

        plot_asteroid(x[i], y);
        plot_asteroid(x[i+1], y);
        plot_asteroid(x[i+2], y);

        j += 1;
        }
    
    plot_heart(610,50);
    plot_heart(600,50);
    plot_heart(580,50);
    return 0;
}
