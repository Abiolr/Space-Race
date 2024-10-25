#ifndef RASTER_H
#define RASTER_H
#include "BITMAP.H" 

/*
* Plots a 8px by 8px bitmap
*/
void plot_bitmap_8(UINT8 *base, int x, int y, 
                    const UINT8 *bitmap, unsigned int height);

/*
* Plots a 16px by 16px bitmap
*/
void plot_bitmap_16(UINT16 *base, int x, int y, 
                    const UINT16 *bitmap, unsigned int height);

/*
* Plots a 32px by 32px bitmap
*/                  
void plot_bitmap_32(UINT32 *base, int x, int y, 
                    const UINT32 *bitmap, unsigned int height);

/*
* Plots a 32px by 32px bitmap of a spaceship
*/          
void plot_spaceship(int x,int y);

/*
* Plots a 16px by 16px bitmap of a heart
*/    
void plot_heart(int x,int y);

/*
* Plots a 32px by 32px bitmap of a number
*/    
void plot_number(int x, int y, int n);

/*
* Plots a 8px by 8px bitmap of a asteroid
*/    
void plot_asteroid(int x, int y);

void clear_32(int x, int y);

void clear_16(int x, int y);

void clear_8(int x, int y);

void clear_screen();

#endif
