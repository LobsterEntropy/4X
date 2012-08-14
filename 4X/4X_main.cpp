#include <iostream>
#include <fstream>
#include <string>
#define GLEW_STATIC
#include <GL/glew.h>
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
    glewInit();
    GLfloat vertexData[] = {1.0, 0.0, 0.0,
                            0.5f, 0.75f, 0.f,
                            0.0, 1.0, 0.0,
                            0.25f, 0.25f, 0.f,
                            0.0, 0.0, 1.0,
                            0.75f, 0.25f, 0.f};

    GLuint vertexBuffer = 0; //index variable for our array

    glGenBuffers(1, &vertexBuffer); //generate an ID for the VBO
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); //activate the VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW); //put the array into the VBO

    while (screen.IsOpened()){ //main loop
        screen.Clear();
        handleEvents(); //check for non-game user inputs (quitting)
        //const Input& input = screen.GetInput();

        screen.SetActive();//necessary if there's ever multiple windows
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear everything out
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); //enable the vertex buffer
        glInterleavedArrays(GL_C3F_V3F, 0, 0); //enable the color/vertex array for drawing
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
        glFlush();//send 'er over to SFML for drawing
        screen.PreserveOpenGLStates(true);//don't blot out the openGL stuff

        displayFPS();
        screen.Display();//draw everything to the screen
    }
    return 0;
}
