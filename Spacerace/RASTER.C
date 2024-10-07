#include <osbind.h>
#include "raster.h"
#include "bitmap.h"

void plot_bitmap_8(UINT8 *base, int x, int y, 
                    const UINT8 *bitmap, unsigned int height)
{
    UINT8 *next = base + (y * 80) + (x >> 3);
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
    UINT16 *next = base + (y * 40) + (x >> 4);
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
    UINT32 *next = base + (y * 20) + (x >> 5);
    int i = 0;
    while (i < height)
    {
        *next = bitmap[i];
        next += 20;
        i += 1;
        }
}

void plot_space_ship(int x,int y){
    UINT32 *FB32 = Physbase();
    plot_bitmap_32(FB32, 320, 350, rocket_bitmap, ROCKET_HEIGHT);
}

void plot_heart(int x,int y){
    UINT16 *FB16 = Physbase();
    plot_bitmap_16(FB16, x, y, heart_bitmap, HEART_HEIGHT);
}

void plot_number(int x, int y,const UINT32 *bitmap){
    UINT32 *FB32 = Physbase();
    plot_bitmap_32(FB32, x, y, bitmap, NUMBER_HEIGHT);
}

void plot_asteroid(int x, int y){
    UINT8 *FB8 = Physbase();
    plot_bitmap_8(FB8, x, y, asteroid_bitmap, ASTEROID_HEIGHT); 
}

void clear_screen() {
    UINT32 *base = Physbase();
    UINT32 color = 0x00000000; 
 
    int i = 0;

    while (i < SCREEN_HEIGHT) {
        UINT32 *next = base + (i * (SCREEN_WIDTH >> 1)); 
        int j;
        for (j = 0; j < (SCREEN_WIDTH >> 1); j++) { 
            *next++ = color; 
        }
        i += 1;
    }
}
