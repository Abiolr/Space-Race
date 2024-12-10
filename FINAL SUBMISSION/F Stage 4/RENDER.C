/*
 * COMP 2659 Render File
 * 
 * Purpose: To manage rendering tasks in the game, including drawing objects such as the spaceship, 
 *          asteroids, hearts, score, and the splash screen. Each object is rendered to the display 
 *          buffer using specific plotting functions.
 * 
 * Authors: Patrick Dang, Abiola Raji
 * Date: December 9, 2024
 */

#include "RENDER.H"
#include "raster.h"
#include "EVENTS.H"
#include "types.h"
#include "BITMAP.H"

/*
 * Function: render
 * -----------------
 * Clears the screen and renders the game model, including the spaceship, asteroids,
 * score, and hearts.
 *
 * Parameters:
 *   model: A pointer to the Model structure that contains the game state to be rendered.
 *   base: A pointer to the display buffer
 */

void render(UINT32 *buffer, Model *model) {
    render_spaceship((UINT32 *)buffer, &model->spaceship);
    render_asteroids((UINT8 *)buffer, model);
    render_hearts((UINT16 *)buffer, model);
    render_score((UINT32 *)buffer, model); 
}

/*
 * Function: render_asteroids
 * ----------------------------
 * Renders all asteroids in the game model.
 *
 * Parameters:
 *   model: A pointer to the Model structure containing the asteroid data.
 *   base: A pointer to the display buffer
 */
void render_asteroids(UINT8 *base, Model *model)
{
    int i;
    for (i = 0; i < MAX_ASTEROIDS; i += 1) {
        /*to fix trailing issue due to double buffer*/
        if (model->asteroid[i].delta_x == 2){
            plot_bitmap_8(base,model->asteroid[i].prev_x - (model->asteroid[i].delta_x * 2), model->asteroid[i].cur_y, black_8, ASTEROID_HEIGHT);
        }
        plot_bitmap_8(base, model->asteroid[i].prev_x, model->asteroid[i].cur_y, black_8, ASTEROID_HEIGHT);
        plot_bitmap_8(base, model->asteroid[i].cur_x, model->asteroid[i].cur_y, asteroid_bitmap, ASTEROID_HEIGHT); 
    }
}

/*
 * Function: render_spaceship
 * ----------------------------
 * Renders the spaceship in the specified position.
 * Clears the space for the spaceship as it moves
 *
 * Parameters:
 *   spaceship: A pointer to the Spaceship structure containing its position.
 *   base: A pointer to the display buffer
 */
void render_spaceship(UINT32 *base, const Spaceship *spaceship)
{
    plot_bitmap_32(base, spaceship->cur_x, spaceship->prev_y, black_32, SPACESHIP_HEIGHT);
    plot_bitmap_32(base, spaceship->cur_x, spaceship->prev_y + 10, black_32, SPACESHIP_HEIGHT);
    plot_bitmap_32(base, spaceship->cur_x, spaceship->prev_y - 10, black_32, SPACESHIP_HEIGHT);
    plot_bitmap_32(base, spaceship->cur_x, spaceship->cur_y, spaceship_bitmap, SPACESHIP_HEIGHT);
}

/*
 * Function: render_hearts
 * -------------------------
 * Renders the player's remaining lives as hearts on the screen.
 *
 * Parameters:
 *   model: A pointer to the Model structure containing the player's lives.
 *   base: A pointer to the display buffer
 */

void render_hearts(UINT16 *base, const Model *model)
{
    switch (model->lives) {
        case 3:
            plot_bitmap_16(base, HEART_ONE_X, HEART_ROW, heart_bitmap, HEART_HEIGHT);
            plot_bitmap_16(base, HEART_TWO_X, HEART_ROW, heart_bitmap, HEART_HEIGHT);
            plot_bitmap_16(base, HEART_THREE_X, HEART_ROW, heart_bitmap, HEART_HEIGHT);
            break;
        case 2:
            plot_bitmap_16(base, HEART_ONE_X, HEART_ROW, heart_bitmap, HEART_HEIGHT);
            plot_bitmap_16(base, HEART_TWO_X, HEART_ROW, heart_bitmap, HEART_HEIGHT);
            plot_bitmap_16(base, HEART_THREE_X, HEART_ROW, black_16, HEART_HEIGHT);
            break;
        case 1:
            plot_bitmap_16(base, HEART_ONE_X, HEART_ROW, heart_bitmap, HEART_HEIGHT);
            plot_bitmap_16(base, HEART_TWO_X, HEART_ROW, black_16, HEART_HEIGHT);
            plot_bitmap_16(base, HEART_THREE_X, HEART_ROW, black_16, HEART_HEIGHT);
            break;
        case 0:
            plot_bitmap_16(base, HEART_ONE_X, HEART_ROW, black_16, HEART_HEIGHT);
            plot_bitmap_16(base, HEART_TWO_X, HEART_ROW, black_16, HEART_HEIGHT);
            plot_bitmap_16(base, HEART_THREE_X, HEART_ROW, black_16, HEART_HEIGHT);
    }
}

/*
 * Function: render_score
 * ------------------------
 * Renders the player's score by displaying each digit separately.
 *
 * Parameters:
 *   model: A pointer to the Model structure containing the score data.
 *   base: A pointer to the display buffer
 */
void render_score(UINT32 *base, const Model *model)
{
    int hundreds = (model->score / 100) %10;
    int tens = (model->score / 10) % 10;
    int ones = model->score % 10;

    plot_bitmap_32(base, FIRST_DIGIT, SCORE_ROW, black_32, NUMBER_HEIGHT);
    plot_bitmap_32(base, SECOND_DIGIT, SCORE_ROW, black_32, NUMBER_HEIGHT);
    plot_bitmap_32(base, THIRD_DIGIT, SCORE_ROW, black_32, NUMBER_HEIGHT);

    plot_number(base, FIRST_DIGIT, SCORE_ROW, hundreds);
    plot_number(base, SECOND_DIGIT, SCORE_ROW, tens);
    plot_number(base, THIRD_DIGIT, SCORE_ROW, ones);
}


/*
 * Function: plot_number
 * Purpose: Plots a specific number bitmap at the specified screen coordinates.
 * Parameters:
 *      x, y - Coordinates where the number should be plotted.
 *      n - Integer representing the number (0-9) to be plotted.
 *      base: A pointer to the display buffer
 */
void plot_number(UINT32 *base, int x, int y, int n)
{
    switch (n) {
        case 0: plot_bitmap_32(base, x, y, number_zero, NUMBER_HEIGHT); break;
        case 1: plot_bitmap_32(base, x, y, number_one, NUMBER_HEIGHT); break;
        case 2: plot_bitmap_32(base, x, y, number_two, NUMBER_HEIGHT); break;
        case 3: plot_bitmap_32(base, x, y, number_three, NUMBER_HEIGHT); break;
        case 4: plot_bitmap_32(base, x, y, number_four, NUMBER_HEIGHT); break;
        case 5: plot_bitmap_32(base, x, y, number_five, NUMBER_HEIGHT); break;
        case 6: plot_bitmap_32(base, x, y, number_six, NUMBER_HEIGHT); break;
        case 7: plot_bitmap_32(base, x, y, number_seven, NUMBER_HEIGHT); break;
        case 8: plot_bitmap_32(base, x, y, number_eight, NUMBER_HEIGHT); break;
        case 9: plot_bitmap_32(base, x, y, number_nine, NUMBER_HEIGHT); break;
    }
}
