#include <osbind.h>
#include "raster.h"

UINT32 rocket_bitmap[ROCKET_HEIGHT] =
{
	0x00000000,
	0x08000010,
	0x1C000038,
	0x14018028,
	0x14018028,
	0x14018028,
	0x14018028,
	0x14018028,
	0x1423C428,
	0x1423C428,
	0x1463C628,
	0x14624628,
	0x14624628,
	0x14624628,
	0x14624628,
	0x14624628,
	0x146FF628,
	0x146FF628,
	0x147FFE28,
	0x14781E28,
	0x14F3CF28,
	0x14E7E728,
	0x14DFFB28,
	0x17BFFDE8,
	0x167FFE68,
	0x15F7EFA8,
	0x1BF7EFD8,
	0x1F1428F8,
	0x1C0C3038,
	0x10042008,
	0x00000000,
	0x00000000
};

UINT16 heart_bitmap[HEART_HEIGHT] = 
{
	0x381C,
    0x7C3E,
    0xFE7F,
    0XFFFF,
    0XFFFF,
    0XFFFF,
    0XFFFF,
    0xFFFF,
    0xFFFF,
    0x7FFE,
    0x3FFC,
    0x1FF8,
    0x0FF0,
    0x07E0,
    0x03C0,
    0x0180
};

UINT32 number_one[NUMBER_HEIGHT] =
{
    0x00000000,
    0x00000000,
    0x000FF000,
    0x000FF000,
    0x003FF000,
    0x00FFF000,
    0x00FFF000,
    0x00FFF000,
    0x00FFF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x00000000,
    0x00000000
};

UINT32 number_two[NUMBER_HEIGHT] =
{
    0x00000000,
    0x00000000,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x000FFF00,
    0x000FFF00,
    0x000FFF00,
    0x000FFF00,
    0x00FF0000,
    0x00FF0000,
    0x00FF0000,
    0x00FF0000,
    0x0FF00000,
    0x0FF00000,
    0x0FF00000,
    0x0FF00000,
    0x0FFFFFF0,
    0x0FFFFFF0,
    0x0FFFFFF0,
    0x0FFFFFF0,
    0x00000000,
    0x00000000
};

UINT32 number_three[NUMBER_HEIGHT] =
{
    0x00000000,
    0x00000000,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x000FFF00,
    0x000FFF00,
    0x000FFF00,
    0x000FFF00,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x00000000,
    0x00000000
};

UINT32 number_four[NUMBER_HEIGHT] =
{
    0x00000000,
    0x00000000,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x00FFFFF0,
    0x00FFFFF0,
    0x00FFFFF0,
    0x00FFFFF0,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x00000000,
    0x00000000
};

UINT32 number_five[NUMBER_HEIGHT] =
{
    0x00000000,
    0x00000000,
    0x0FFFFFF0,
    0x0FFFFFF0,
    0x0FFFFFF0,
    0x0FFFFFF0,
    0x0FF00000,
    0x0FF00000,
    0x0FF00000,
    0x0FF00000,
    0x0FFFFF00,
    0x0FFFFF00,
    0x0FFFFF00,
    0x0FFFFF00,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x00000000,
    0x00000000
};

UINT32 number_six[NUMBER_HEIGHT] =
{
    0x00000000,
    0x00000000,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00000,
    0x0FF00000,
    0x0FF00000,
    0x0FF00000,
    0x0FFFFF00,
    0x0FFFFF00,
    0x0FFFFF00,
    0x0FFFFF00,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x00000000,
    0x00000000
};

UINT32 number_seven[NUMBER_HEIGHT] =
{
    0x00000000,
    0x00000000,
    0x0FFFFFF0,
    0x0FFFFFF0,
    0x0FFFFFF0,
    0x0FFFFFF0,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x0000FF00,
    0x0000FF00,
    0x0000FF00,
    0x0000FF00,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x000FF000,
    0x00000000,
    0x00000000
};

UINT32 number_eight[NUMBER_HEIGHT] =
{
    0x00000000,
    0x00000000,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x00000000,
    0x00000000
};

UINT32 number_nine[NUMBER_HEIGHT] =
{
    0x00000000,
    0x00000000,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x00FFFFF0,
    0x00FFFFF0,
    0x00FFFFF0,
    0x00FFFFF0,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x00000FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x00000000,
    0x00000000
};

UINT32 number_zero[NUMBER_HEIGHT] =
{
    0x00000000,
    0x00000000,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x0FF00FF0,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x00FFFF00,
    0x00000000,
    0x00000000
};

int main()
{
    UINT32 *FB32 = Physbase();
    UINT16 *FB16 = Physbase();

    int x;
    int y;

/*
    for (x = 0 ; x < SCREEN_WIDTH; x += 64)
    {
        for (y = 0; y < SCREEN_HEIGHT; y += 32)
        {
            plot_bitmap_32(FB32, x, y, rocket_bitmap, ROCKET_HEIGHT);
        }
    }
*/

    plot_bitmap_32(FB32, 320, 10, number_one, ROCKET_HEIGHT);
    plot_bitmap_32(FB32, 352, 10, number_one, ROCKET_HEIGHT);
    plot_bitmap_32(FB32, 288, 10, number_one, ROCKET_HEIGHT);
    plot_bitmap_32(FB32, 320, 350, rocket_bitmap, ROCKET_HEIGHT);
    plot_bitmap_16(FB16, 600, 10, heart_bitmap, HEART_HEIGHT);
    plot_bitmap_16(FB16, 560, 10, heart_bitmap, HEART_HEIGHT);
    plot_bitmap_16(FB16, 639, 10, heart_bitmap, HEART_HEIGHT);
    return 0;
}
