#ifndef RENDER_H
#define RENDER_H

#include "MODEL.H"
#include "RASTER.H"

void render(const Model *model);

void render_asteroids(const Model *model);

void render_spaceship(const Spaceship *spaceship);

void render_hearts(const Model *model);

void render_score(const Model *model);

#endif