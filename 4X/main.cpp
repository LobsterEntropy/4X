#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <SDL/SDL.h>

using namespace std;



int main(int argc, char *argv[]){
    freopen( "CON", "w", stdout );//necessary to display console output
    freopen( "CON", "w", stderr );//causes weirdness at the end of execution
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Surface* hello = NULL;
    SDL_Surface* screen = NULL;

    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
    hello = SDL_LoadBMP("img\\hello world.bmp");

    if(!hello)
        cout<<"error";

    SDL_BlitSurface(hello, NULL, screen, NULL);
    SDL_Flip(screen);

    SDL_Delay(2000);

    SDL_FreeSurface(hello);
    SDL_Quit();

    return 0;
}
