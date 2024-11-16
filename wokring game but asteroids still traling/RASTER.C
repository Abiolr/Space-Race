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
#include "BITMAP.H" 

/*
 * Function: plot_bitmap_8
 * Purpose: Plots an 8-bit bitmap at specified coordinates on the screen.
 * Parameters:
 *      base - Pointer to the screen's framebuffer.
 *      x, y - Coordinates where the bitmap should be plotted.
 *      bitmap - Pointer to the bitmap data.
 *      height - Height of the bitmap in pixels.
 * Returns:
 *      None.
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
 * Returns:
 *      None.
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
 * Returns:
 *      None.
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

/*
 * Function: plot_spaceship
 * Purpose: Plots the spaceship bitmap at the specified screen coordinates.
 * Parameters:
 *      x, y - Coordinates where the spaceship should be plotted.
 * Returns:
 *      None.
 */
void plot_spaceship(UINT32 *base, int x, int y)
{
    plot_bitmap_32(base, x, y, spaceship_bitmap, SPACESHIP_HEIGHT);
}

/*
 * Function: plot_heart
 * Purpose: Plots a heart bitmap at the specified screen coordinates.
 * Parameters:
 *      x, y - Coordinates where the heart should be plotted.
 * Returns:
 *      None.
 */
void plot_heart(UINT16 *base, int x, int y)
{
    plot_bitmap_16(base, x, y, heart_bitmap, HEART_HEIGHT);
}

/*
 * Function: plot_number
 * Purpose: Plots a specific number bitmap at the specified screen coordinates.
 * Parameters:
 *      x, y - Coordinates where the number should be plotted.
 *      n - Integer representing the number (0-9) to be plotted.
 * Returns:
 *      None.
 */
void plot_number(UINT32 *base, int x, int y, int n)
{
    switch (n) {
        case 0: plot_bitmap_32(base, x, y, number_zero, NUMBER_HEIGHT); break;
        case 1: plot_bitmap_32(base, x, y, number_one, NUMBER_HEIGHT); break;
        case 2: plot_bitmap_32(base, x, y, number_two, NUMBER_HEIGHT); break;
        case 3: plot_bitmap_32(base, x, y, number_three, NUMBER_HEIGHT); break;
        case 4: plot_bitmap_32(base, x, y, number_four, NUMBER_HEIGHT); break;
        case 5: plot_bitmap_32(base, x, y, number_five, NUMBER_HEIGHT); break;
        case 6: plot_bitmap_32(base, x, y, number_six, NUMBER_HEIGHT); break;
        case 7: plot_bitmap_32(base, x, y, number_seven, NUMBER_HEIGHT); break;
        case 8: plot_bitmap_32(base, x, y, number_eight, NUMBER_HEIGHT); break;
        case 9: plot_bitmap_32(base, x, y, number_nine, NUMBER_HEIGHT); break;
    }
}

/*
 * Function: plot_asteroid
 * Purpose: Plots an asteroid bitmap at the specified screen coordinates.
 * Parameters:
 *      x, y - Coordinates where the asteroid should be plotted.
 * Returns:
 *      None.
 */
void plot_asteroid(UINT8 *base, int x, int y)
{
    plot_bitmap_8(base, x, y, asteroid_bitmap, ASTEROID_HEIGHT); 
}

/*
 * Function: clear_32
 * Purpose: Clears a 32-bit area of the screen at the specified coordinates.
 * Parameters:
 *      x, y - Coordinates where the clearing should begin.
 * Returns:
 *      None.
 */
void clear_32(UINT32 *base, int x, int y)
{
    plot_bitmap_32(base, x, y, clear32, 32);
}

/*
 * Function: clear_16
 * Purpose: Clears a 16-bit area of the screen at the specified coordinates.
 * Parameters:
 *      x, y - Coordinates where the clearing should begin.
 * Returns:
 *      None.
 */
void clear_16(UINT16 *base, int x, int y)
{
    plot_bitmap_16(base, x, y, clear16, 16);
}

/*
 * Function: clear_8
 * Purpose: Clears an 8-bit area of the screen at the specified coordinates.
 * Parameters:
 *      x, y - Coordinates where the clearing should begin.
 * Returns:
 *      None.
 */
void clear_8(UINT8 *base, int x, int y)
{
    plot_bitmap_8(base, x, y, clear8, 8);
}

/*
 * Function: clear_screen
 * Purpose: Clears the entire screen by setting each pixel to a black color value (0x00000000).
 * Parameters:
 *      None.
 * Returns:
 *      None.
 * Assumptions:
 *      The screen dimensions are defined by SCREEN_WIDTH and SCREEN_HEIGHT.
 */
void clear_screen(UINT32 *base)
{
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