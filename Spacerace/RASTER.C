#include <osbind.h>
#include "raster.h"
#include "bitmap.h"

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

void clear_screen() {
    UINT32 *FB32 = Physbase();
    UINT32 color = 0x00000000; // Color to clear to (black for 32-bit framebuffer)

    // Clear the framebuffer by setting each pixel to the desired color
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            FB32[y * (SCREEN_WIDTH / 2) + (x / 2)] = color; // Assuming 32 bits per pixel, adjust index calculation as needed
        }
    }
}
