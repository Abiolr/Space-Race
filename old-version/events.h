#ifndef EVENTS_H
#define EVENTS_H
#include "MODEL.H"
#include "TYPES.H"

/*
* Updates the displacment of spaceship object towards 
* the top of the screen by adding a negative value
*/
void move_spaceship_up(Model *model);

/*
* Updates the displacment of spaceship object towards 
* the bottom of the screen by adding a postive value
*/
void move_spaceship_down(Model *model);

/*
* stops the displacment of spaceship 
* by setting the value to 0
*/
void stop_spaceship(Model *model);


/*
*
*/
int check_collision(Spaceship *spacship, Asteroid *asteroid);

/*
* Checks for conflicting hitboxes between 
* asteroids and spacship
*/
void asteroid_collision(Model *model, int i);
/*
void spaceship_collision(Model *model);
*/
/*
* updates the score by adding 1 to the model
*/
void point_scored(Model *model);

/*
* updates asteroids by moving them in alternating directions
* moving them all 2 pixels in either direction and checking if they
* are out of screen bounds if so move to edge of screen on other side
*/
void update_asteroids(Model *model);

#endif
