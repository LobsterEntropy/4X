#include <iostream>
#include <fstream>
#include "4X_func.h"
#include "SDL_image.h"
#include <stdlib.h>
#include <SDL/SDL.h>

using namespace std;
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

int main(int argc, char *argv[]){ //don't delete the stuff in the brackets, SDL needs it
    freopen( "CON", "w", stdout );//necessary to display console output
    freopen( "CON", "w", stderr );//causes weirdness at the end of execution
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Surface* hello = NULL;
    SDL_Surface* screen = NULL;

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE);
    hello = IMG_Load("img\\hello world.png");

    if(!hello) //check that the load worked
        cout<<"error";

    SDL_BlitSurface(hello, NULL, screen, NULL); //draw image
    SDL_Flip(screen);

    SDL_Delay(2000);

    SDL_FreeSurface(hello); //closing down
    SDL_Quit();

    return 0;
}
