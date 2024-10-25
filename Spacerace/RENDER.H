#ifndef RENDER_H
#define RENDER_H

#include "MODEL.H"

void render(const Model *model, UINT32 *base);

void render_asteroids(const Asteroid[] *asteroids, UINT8 *base);

void render_spaceship(const Spaceship *spaceship, UINT32 *base);

void render_hearts(int *lives, UINT16 *base);

void render_score(int *score , UINT32 *base);

#endif