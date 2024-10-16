#ifndef RASTER_H
#define RASTER_H

#include "types.h"

/* [TO DO] the functions below are examples. Replace them! */
void plot_bitmap_8(UINT8 *base, int x, int y, 
                    const UINT8 *bitmap, unsigned int height);

void plot_bitmap_16(UINT16 *base, int x, int y, 
                    const UINT16 *bitmap, unsigned int height);
                    
void plot_bitmap_32(UINT32 *base, int x, int y, 
                    const UINT32 *bitmap, unsigned int height);

void plot_space_ship(int x,int y);

void plot_heart(int x,int y);

void plot_number(int x, int y, int n);

void plot_asteroid(int x, int y);

void clear_screen();

#endif
