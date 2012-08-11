#include <iostream>
#include <fstream>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "4X_vertex.h"
#include "4X_func.h"
#include "4X_constants.h"

using namespace std;
using namespace sf;

RenderWindow screen(VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,32), "Hello OpenGL!"); //set up screen
 //I'm allowing myself one global variable

int main(){
    screen.SetFramerateLimit(60);
    glInit();

    vertex *vertArray = NULL;
    vertArray = loadVertexData(vertArray);

    while (screen.IsOpened()){
        screen.Clear();
        handleEvents();

        const Input& input = screen.GetInput(); //move the triangle around a bit
        float x = 0, y = 0, z = 0;
        if (input.IsKeyDown(Key::Left)) x -= speed;
        if (input.IsKeyDown(Key::Right)) x += speed;
        if (input.IsKeyDown(Key::Down)) y -= speed;
        if (input.IsKeyDown(Key::Up)) y += speed;
        moveVertexData(vertArray, x, y, z);

        screen.SetActive();//necessary if there's ever multiple windows
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear everything out
        drawVertexArray(vertArray); //draw the goddamn triangle
        glFlush();//send 'er over to SFML for drawing
        screen.PreserveOpenGLStates(true);//don't blot out the openGL stuff

        displayFPS();
        screen.Display();//draw everything to the screen
    }
    return 0;
}
