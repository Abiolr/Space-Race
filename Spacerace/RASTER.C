/*
* COMP 2659 Raster File
* 
* Purpose: To handle the plotting and clearing of objects
* Authors: Patrick Dang, Abiola Raji
* Date: October 25, 2024
*/

#include <osbind.h>
#include "raster.h"

void plot_bitmap_8(UINT8 *base, int x, int y, 
                    const UINT8 *bitmap, unsigned int height)
{
    UINT8 *next = base + (y << 6) + (y << 4) + (x >> 3);                       /**/
    int i = 0;
    while (i < height)
    {
        *next = bitmap[i];
        next += 80;
        i += 1;                
        }
}

void plot_bitmap_16(UINT16 *base, int x, int y, 
                    const UINT16 *bitmap, unsigned int height)
{
    UINT16 *next = base + (y << 5) + (y << 3) + (x >> 4);
    int i = 0;
    while (i < height)
    {
        *next = bitmap[i];
        next += 40;
        i += 1;
        }
}

void plot_bitmap_32(UINT32 *base, int x, int y, 
                    const UINT32 *bitmap, unsigned int height)
{
    UINT32 *next = base + (y << 4) + (y << 2) + (x >> 5);
    int i = 0;
    while (i < height)
    {
        *next = bitmap[i];
        next += 20;
        i += 1;
        }
}

void plot_spaceship(int x,int y){
    UINT32 *FB32 = Physbase();
    plot_bitmap_32(FB32, x, y, spaceship_bitmap, SPACESHIP_HEIGHT);
}

void plot_heart(int x,int y){
    UINT16 *FB16 = Physbase();
    plot_bitmap_16(FB16, x, y, heart_bitmap, HEART_HEIGHT);
}

void plot_number(int x, int y, int n){
    UINT32 *FB32 = Physbase();

    if (n == 0){
        plot_bitmap_32(FB32, x, y, number_zero, NUMBER_HEIGHT);
    }
    else if (n == 1){
        plot_bitmap_32(FB32, x, y, number_one, NUMBER_HEIGHT);
    }
    else if (n == 2){
        plot_bitmap_32(FB32, x, y, number_two, NUMBER_HEIGHT);
    }
    else if (n == 3){
        plot_bitmap_32(FB32, x, y, number_three, NUMBER_HEIGHT);
    }
    else if (n == 4){
        plot_bitmap_32(FB32, x, y, number_four, NUMBER_HEIGHT);
    }
    else if (n == 5){
        plot_bitmap_32(FB32, x, y, number_five, NUMBER_HEIGHT);
    }
    else if (n == 6){
        plot_bitmap_32(FB32, x, y, number_six, NUMBER_HEIGHT);
    }
    else if (n == 7){
        plot_bitmap_32(FB32, x, y, number_seven, NUMBER_HEIGHT);
    }
    else if (n == 8){
        plot_bitmap_32(FB32, x, y, number_eight, NUMBER_HEIGHT);
    }
    else if (n == 9){
        plot_bitmap_32(FB32, x, y, number_nine, NUMBER_HEIGHT);
    }
}

void plot_asteroid(int x, int y){
    UINT8 *FB8 = Physbase();
    plot_bitmap_8(FB8, x, y, asteroid_bitmap, ASTEROID_HEIGHT); 
}

void clear_spaceship(int x, int y){
    UINT32 *FB32 = Physbase();
    plot_bitmap_32(FB32, x, y, clear32, 32);
}

void clear_heart(int x, int y){
    UINT16 *FB16 = Physbase();
    plot_bitmap_16(FB16, x, y, clear16, 16);
}

void clear_number(int x, int y){
    UINT32 *FB32 = Physbase();
    plot_bitmap_32(FB32, x, y, clear32, 32);
}

void clear_asteroid(int x,int y){
    UINT8 *FB8 = Physbase();
    plot_bitmap_8(FB8, x, y, clear8, 8);
}

void clear_screen() {
    UINT32 *base = Physbase();
    UINT32 color = 0x00000000; 
 
    int i = 0;

    while (i < SCREEN_HEIGHT) {
        UINT32 *next = base + (i * (SCREEN_WIDTH >> 5)); 
        int j;
        for (j = 0; j < (SCREEN_WIDTH >> 5); j++) { 
            *next++ = color; 
        }
        i += 1;
    }
}