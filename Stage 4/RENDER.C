#include "RENDER.H"

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
    clear_screen();
    
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
        plot_asteroid(model->asteroid[i].x, model->asteroid[i].y);
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
    plot_spaceship(spaceship->x, spaceship->y);
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
            break;
        case 1:
            plot_heart(610, 50);
            break;
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

    plot_number(FIRST_DIGIT, SCORE_ROW, hundreds);
    plot_number(SECOND_DIGIT, SCORE_ROW, tens);
    plot_number(THIRD_DIGIT, SCORE_ROW, ones);
}
