#include "RENDER.H"

void render(const Model *model)
{
    clear_screen();
    
    render_spaceship(&model->spaceship);

    render_asteroids(model);

    render_score(model);

    render_hearts(model);
}

void render_asteroids(const Model *model)
{
    int i = 0;
    for (i; i < 33; i+=1){
        /*clear_8(model->asteroid[i].x, model->asteroid[i].y);*/
        plot_asteroid(model->asteroid[i].x, model->asteroid[i].y);
    }
}

void render_spaceship(const Spaceship *spaceship)
{
    /*clear_32(spaceship->x, spaceship->y);*/
    plot_spaceship(spaceship->x, spaceship->y);
}

void render_hearts(const Model *model)
{
    /*clear_16(610,50);
    clear_16(600,50);
    clear_16(580,50);*/

    switch(model->lives){
        case 3:
            plot_heart(610,50);
            plot_heart(600,50);
            plot_heart(580,50);
            break;
        case 2:
            plot_heart(610,50);
            plot_heart(600,50);
            break;
        case 1:
            plot_heart(610,50);
            break;
    }
}

void render_score(const Model *model)
{
    int hundreds = model->score/100;
    int tens = model->score/10 % 10;
    int ones = model->score % 10;

    /*clear_32();*/
    plot_number(FIRST_DIGIT,SCORE_ROW,hundreds);
    plot_number(SECOND_DIGIT,SCORE_ROW,tens);
    plot_number(THIRD_DIGIT,SCORE_ROW,ones);
}