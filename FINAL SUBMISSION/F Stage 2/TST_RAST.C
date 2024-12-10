/*
* COMP 2659 Test Raster File
* 
* Purpose: To handle the testing of plotting and clearing of objects
* Authors: Patrick Dang, Abiola Raji
* Date: October 25, 2024
*/
#include <osbind.h>
#include "RASTER.H"
#include "BITMAP.H"
UINT32 *frontBuffer;

/*
int main()
{
    int i = 0;
    int j = 0;

    int x[] = {344, 8, 504, 216, 88, 600, 280, 168, 392, 24,
                440, 104, 376, 264, 152, 632, 200, 40, 536, 280,
                280, 392, 152, 616, 72, 328, 488, 440, 136, 392,
                440, 280, 24};
                
    clear_screen();

    for (i = 0; i < 33; i += 3)
    {
        int y = (j << 5) + 8;

        plot_asteroid(x[i], y);
        plot_asteroid(x[i + 1], y);
        plot_asteroid(x[i + 2], y);

        j += 1;
        }

    plot_number(FIRST_DIGIT,SCORE_ROW,4);
    plot_number(SECOND_DIGIT,SCORE_ROW,2);
    plot_number(THIRD_DIGIT,SCORE_ROW,0);

    plot_spaceship(320,350);
    
    plot_heart(610,50);
    plot_heart(600,50);
    plot_heart(580,50);

    return 0;
    
}
*/

int main(){
    int i;
    frontBuffer = Physbase();
    clear_screen(frontBuffer, BLACK);

    for (i = 0; i < 640; i += 32){
        plot_bitmap_32(frontBuffer, i, 0, spaceship_bitmap, SPACESHIP_HEIGHT);
    }

    for (i = 0; i < 640; i += 16){
        plot_bitmap_8((UINT8 *)frontBuffer, i, 64, asteroid_bitmap, ASTEROID_HEIGHT);
    }

    for (i = 0; i < 640; i += 16){
        plot_bitmap_16((UINT16 *)frontBuffer, i, 256, heart_bitmap, HEART_HEIGHT);
    }

    plot_bitmap_32(frontBuffer, 0, 128, number_one, NUMBER_HEIGHT);
    plot_bitmap_32(frontBuffer, 32, 128, number_two, NUMBER_HEIGHT);
    plot_bitmap_32(frontBuffer, 64, 128, number_three, NUMBER_HEIGHT);
    plot_bitmap_32(frontBuffer, 96, 128, number_four, NUMBER_HEIGHT);
    plot_bitmap_32(frontBuffer, 128, 128, number_five, NUMBER_HEIGHT);
    plot_bitmap_32(frontBuffer, 160, 128, number_six, NUMBER_HEIGHT);
    plot_bitmap_32(frontBuffer, 192, 128, number_seven, NUMBER_HEIGHT);
    plot_bitmap_32(frontBuffer, 224, 128, number_eight, NUMBER_HEIGHT);
    plot_bitmap_32(frontBuffer, 256, 128, number_nine, NUMBER_HEIGHT);
    plot_bitmap_32(frontBuffer, 288, 128, number_zero, NUMBER_HEIGHT);




    return 0;
}
