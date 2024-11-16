#include "RENDER.H"
#include "raster.h"


/*
 * Function: render
 * -----------------
 * Clears the screen and renders the game model, including the spaceship, asteroids,
 * score, and hearts.
 *
 * Parameters:
 *   model: A pointer to the Model structure that contains the game state to be rendered.
 *
 * Returns:
 *   This function does not return a value.
 *
 * Assumptions:
 *   The model pointer is valid and points to an allocated Model structure.
 */
void render(const Model *model)
{
    render_spaceship(&model->spaceship);
    render_asteroids(model);
    render_score(model);
    render_hearts(model);
}

/*
 * Function: render_asteroids
 * ----------------------------
 * Renders all asteroids in the game model.
 *
 * Parameters:
 *   model: A pointer to the Model structure containing the asteroid data.
 *
 * Returns:
 *   This function does not return a value.
 *
 * Assumptions:
 *   The model pointer is valid and points to an allocated Model structure.
 */
void render_asteroids(const Model *model)
{
    int i = 0;
    for (i; i < 33; i += 1) {
        clear_8(model->asteroid[i].prev_x, model->asteroid[i].cur_y );
        plot_asteroid(model->asteroid[i].cur_x, model->asteroid[i].cur_y);
    }
}

/*
 * Function: render_spaceship
 * ----------------------------
 * Renders the spaceship in the specified position.
 *
 * Parameters:
 *   spaceship: A pointer to the Spaceship structure containing its position.
 *
 * Returns:
 *   This function does not return a value.
 *
 * Assumptions:
 *   The spaceship pointer is valid and points to an allocated Spaceship structure.
 */
void render_spaceship(const Spaceship *spaceship)
{
    clear_32(spaceship->cur_x, spaceship->prev_y);
    plot_spaceship(spaceship->cur_x, spaceship->cur_y);
}

/*
 * Function: render_hearts
 * -------------------------
 * Renders the player's remaining lives as hearts on the screen.
 *
 * Parameters:
 *   model: A pointer to the Model structure containing the player's lives.
 *
 * Returns:
 *   This function does not return a value.
 *
 * Assumptions:
 *   The model pointer is valid and points to an allocated Model structure.
 */

void render_hearts(const Model *model)
{
    switch (model->lives) {
        case 3:
            plot_heart(610, 50);
            plot_heart(600, 50);
            plot_heart(580, 50);
            break;
        case 2:
            plot_heart(610, 50);
            plot_heart(600, 50);
            clear_16(580,50); 
            break;
        case 1:
            plot_heart(610, 50);
            clear_16(600,50); 
            clear_16(580,50); 
            break;
        case 0:
            clear_16(610,50); 
            clear_16(600,50); 
            clear_16(580,50); 
    }
}

/*
 * Function: render_score
 * ------------------------
 * Renders the player's score by displaying each digit separately.
 *
 * Parameters:
 *   model: A pointer to the Model structure containing the score data.
 *
 * Returns:
 *   This function does not return a value.
 *
 * Assumptions:
 *   The model pointer is valid and points to an allocated Model structure.
 */
void render_score(const Model *model)
{
    int hundreds = (model->score / 100) %10;
    int tens = (model->score / 10) % 10;
    int ones = model->score % 10;

    clear_32(FIRST_DIGIT, SCORE_ROW);
    clear_32(SECOND_DIGIT,SCORE_ROW);
    clear_32(THIRD_DIGIT, SCORE_ROW);

    plot_number(FIRST_DIGIT, SCORE_ROW, hundreds);
    plot_number(SECOND_DIGIT, SCORE_ROW, tens);
    plot_number(THIRD_DIGIT, SCORE_ROW, ones);
}
