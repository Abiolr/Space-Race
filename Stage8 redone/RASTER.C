/*
 * COMP 2659 Raster File
 * 
 * Purpose: To handle the plotting and clearing of objects on the screen, including different-sized 
 *          bitmaps for the spaceship, asteroid, hearts, and score numbers.
 * 
 * Authors: Patrick Dang, Abiola Raji
 * Date: October 25, 2024
 */

#include <osbind.h>
#include "raster.h"

/*
 * Function: plot_bitmap_8
 * Purpose: Plots an 8-bit bitmap at specified coordinates on the screen.
 * Parameters:
 *      base - Pointer to the screen's framebuffer.
 *      x, y - Coordinates where the bitmap should be plotted.
 *      bitmap - Pointer to the bitmap data.
 *      height - Height of the bitmap in pixels.
 */
void plot_bitmap_8(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height)
{
    UINT8 *next = base + (y << 6) + (y << 4) + (x >> 3);                       
    int i = 0;
    while (i < height)
    {
        *next = bitmap[i];
        next += 80;
        i += 1;                
    }
}

/*
 * Function: plot_bitmap_16
 * Purpose: Plots a 16-bit bitmap at specified coordinates on the screen.
 * Parameters:
 *      base - Pointer to the screen's framebuffer.
 *      x, y - Coordinates where the bitmap should be plotted.
 *      bitmap - Pointer to the bitmap data.
 *      height - Height of the bitmap in pixels.
 *      base: A pointer to the display buffer
 */
void plot_bitmap_16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height)
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

/*
 * Function: plot_bitmap_32
 * Purpose: Plots a 32-bit bitmap at specified coordinates on the screen.
 * Parameters:
 *      base - Pointer to the screen's framebuffer.
 *      x, y - Coordinates where the bitmap should be plotted.
 *      bitmap - Pointer to the bitmap data.
 *      height - Height of the bitmap in pixels.
 *      base: A pointer to the display buffer
 */
void plot_bitmap_32(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height)
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

void plot_bitmap_large(UINT32 *base, int x, int y, const UINT32 *bitmap)
{
    int width = 640;  
    int height = 400; 
    int row_words = width / 32; 
    int i, j;

   
    UINT32 *framebuffer_row = base + (y * row_words) + (x / 32);

   
    for (i = 0; i < height; i++)
    {
       
        const UINT32 *bitmap_row = bitmap + (i * row_words);

       
        for (j = 0; j < row_words; j++)
        {
            framebuffer_row[j] = bitmap_row[j];
        }

        
        framebuffer_row += row_words;
    }
}

/*
 * Function: clear_screen
 * Purpose: Clears the entire screen by setting each pixel to a black color value (0x00000000).
 * Parameters:
 *      base: A pointer to the display buffer
 */
void clear_screen(UINT32 *base, int colour)
{
    int i = 0;
    UINT32 screen;

    if (colour == BLACK){
        screen = 0xFFFFFFFF; 
    }
    else if (colour == WHITE){
        screen = 0x00000000; 
    }

    while (i < SCREEN_HEIGHT) {
        UINT32 *next = base + (i * (SCREEN_WIDTH >> 5)); 
        int j;
        for (j = 0; j < (SCREEN_WIDTH >> 5); j++) { 
            *next++ = screen; 
        }
        i += 1;
    }
}

void set_video_base(UINT32 *base) {
    if (base != (UINT32 *)0x3F8000) {    
    }
}