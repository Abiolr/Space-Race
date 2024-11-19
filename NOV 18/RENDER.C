#include "RENDER.H"
#include "raster.h"
#include "EVENTS.H"
#include "types.h"

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

void render(UINT32 *buffer, Model *model) {
    render_hearts((UINT16 *)buffer, model);
    render_score((UINT32 *)buffer, model);
    render_asteroids((UINT8 *)buffer, model);
    render_spaceship((UINT32 *)buffer, &model->spaceship);
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
void render_asteroids(UINT8 *base, Model *model)
{
    int i;
    for (i = 0; i < MAX_ASTEROIDS; i += 1) {
        clear_8_bitmap(base, model->asteroid[i].prev_x, model->asteroid[i].cur_y );
        plot_asteroid(base, model->asteroid[i].cur_x, model->asteroid[i].cur_y);
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
void render_spaceship(UINT32 *base, const Spaceship *spaceship)
{
    clear_32_bitmap(base, spaceship->cur_x, spaceship->prev_y);
    plot_spaceship(base, spaceship->cur_x, spaceship->cur_y);
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

void render_hearts(UINT16 *base, const Model *model)
{
    switch (model->lives) {
        case 3:
            plot_heart(base, 610, 50);
            plot_heart(base, 600, 50);
            plot_heart(base, 580, 50);
            break;
        case 2:
            plot_heart(base, 610, 50);
            plot_heart(base, 600, 50);
            clear_16_bitmap(base, 580,50); 
            break;
        case 1:
            plot_heart(base, 610, 50);
            clear_16_bitmap(base, 600,50); 
            clear_16_bitmap(base, 580,50); 
            break;
        case 0:
            clear_16_bitmap(base, 610,50); 
            clear_16_bitmap(base, 600,50); 
            clear_16_bitmap(base, 580,50); 
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
void render_score(UINT32 *base, const Model *model)
{
    int hundreds = (model->score / 100) %10;
    int tens = (model->score / 10) % 10;
    int ones = model->score % 10;

    clear_32_bitmap(base, FIRST_DIGIT, SCORE_ROW);
    clear_32_bitmap(base, SECOND_DIGIT,SCORE_ROW);
    clear_32_bitmap(base, THIRD_DIGIT, SCORE_ROW);

    plot_number(base, FIRST_DIGIT, SCORE_ROW, hundreds);
    plot_number(base, SECOND_DIGIT, SCORE_ROW, tens);
    plot_number(base, THIRD_DIGIT, SCORE_ROW, ones);
}
