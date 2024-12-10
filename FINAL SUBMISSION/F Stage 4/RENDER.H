#ifndef RENDER_H
#define RENDER_H
#include "types.h"
#include "MODEL.H"

void render(UINT32 *buffer, Model *model);

void render_asteroids(UINT8 *base, Model *model);

void render_spaceship(UINT32 *base, const Spaceship *spaceship);

void render_hearts(UINT16 *base, const Model *model);

void render_score(UINT32 *base, const Model *model);

/*
* Plots a 32px by 32px bitmap of a number
*/    
void plot_number(UINT32 *base, int x, int y, int n);

#endif