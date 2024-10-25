#include "RENDER.H"

void render(const Model *model)
{
    clear_screen();
    
    render_spaceship(model->spaceship, base);

    render_asteroids(model->asteroid, base);

    render_score(model->score, base);

    render_hearts(model->lives, base);
}

void render_asteroids(const Asteroid[] *asteroids)
{
    clear_asteroid();
    plot_asteroid();
}

void render_spaceship(const Spaceship *spaceship)
{
    clear_spaceship(spaceship->x, spaceship->y);
    plot_spaceship(spaceship->x, spaceship->y);
}

void render_hearts(int *lives)
{
    clear16(610,50);
    clear16(600,50);
    clear16(580,50);

    switch(lives){
        case 3:
            plot_heart(610,50);
            plot_heart(600,50);
            plot_heart(580,50);
            break;
        case 2:
            plot_heart(610,50);
            plot_heart(600,50);
=           break;
        case 1:
            plot_heart(610,50);
            break;
    }
}

void render_score(int *score)
{
    clear32();
    plot_number();
}