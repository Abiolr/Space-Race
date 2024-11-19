#include <stdio.h>
#include "RENDER.H"
#include "MODEL.H"

int main(){

    Model model;
    init_model(&model);
    render(&model);

    return 0;
}