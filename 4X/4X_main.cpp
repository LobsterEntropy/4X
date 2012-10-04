#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define GLEW_STATIC
#include <GL/glew.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "4X_vertex.h"
#include "4X_func.h"
#include "4X_constants.h"

using namespace std;
using namespace sf;

GLfloat* generateGrid(int w, int h, float spacing){
    GLfloat* vertexGrid = new GLfloat[w*h*3];
    float x = 0.0f; float y = 0.0f;
    for (int j = 0; j < h*w*3; j+=w*3){
        for (int i = 0; i < w*3; i += 3){
            vertexGrid[i+j] = x*spacing;
            vertexGrid[i+j+1] = y*spacing;
            vertexGrid[i+j+2] = 0;
            x+=1.0f;
            cout<<"X: "<<vertexGrid[i+j]<<" Y: "<<vertexGrid[i+j+1]<<" Z: "<<vertexGrid[i+j+2]<<endl;
        }
        x = 0;
        y+=1.0f;
    }
    return vertexGrid;
}

RenderWindow screen(VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,32), "Hello OpenGL!"); //set up screen
 //I'm allowing myself one global variable

int main(){
    screen.SetFramerateLimit(60);
    GLfloat* vertexGrid = generateGrid(10,10,0.1);

    glInit();
    glewInit(); //so we can use OpenGL functions from later than 1995
    /*GLfloat vertexData[] = {1.0, 0.0, 0.0,
                            -0.5f, -0.5f, 0.0f,
                            0.0, 1.0, 0.0,
                            -0.5f, 0.5f, 0.0f,
                            0.0, 0.0, 1.0,
                            0.5f, 0.5f, 0.0f};*/
    GLuint vertexBuffer = 0; //index variable for our array

    glGenBuffers(1, &vertexBuffer); //generate an ID for the VBO
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); //activate the VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexGrid), vertexGrid, GL_STATIC_DRAW); //put the array into the VBO

    while (screen.IsOpened()){ //main loop
        screen.Clear();
        handleEvents(); //check for non-game user inputs (quitting)
        //const Input& input = screen.GetInput();

        screen.SetActive();//necessary if there's ever multiple windows

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear everything out
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(0,0,5, //move the camera away from the origin
                  0,0,0, //look at the origin
                  0,1,0); //set the orientation, sort of
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); //enable the vertex buffer
        glInterleavedArrays(GL_V3F, 0, 0); //enable the color/vertex array for drawing
        glColor3f(1.0,1.0,1.0);
        glDrawArrays(GL_LINES, 0, 0);

        glFlush();//send 'er over to SFML for drawing
        screen.PreserveOpenGLStates(true);//don't blot out the openGL stuff

        displayFPS();
        screen.Display();//draw everything to the screen
    }
    return 0;
}
