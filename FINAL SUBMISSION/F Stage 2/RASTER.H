#ifndef RASTER_H
#define RASTER_H
#include "TYPES.H"

void plot_bitmap_8(UINT8 *base, int x, int y, 
                    const UINT8 *bitmap, unsigned int height);

void plot_bitmap_16(UINT16 *base, int x, int y, 
                    const UINT16 *bitmap, unsigned int height);
                 
void plot_bitmap_32(UINT32 *base, int x, int y, 
                    const UINT32 *bitmap, unsigned int height);

void plot_bitmap_large(UINT32 *base, int x, int y, const UINT32 *bitmap);

void clear_screen(UINT32 *base, int colour);

void set_video_base(UINT32 *base);

UINT32 *get_video_base();

#endif
