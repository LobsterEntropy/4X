#include <iostream>
#include <fstream>
#include "4x_func.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

const int SCREEN_WIDTH = 800; //constant parameters
const int SCREEN_HEIGHT = 800;

const float speed = 10.f;
int x = 0, y = 0;

int main(){
    WindowSettings settings;

    settings.DepthBits = 24; // Request a 24 bits depth buffer
    settings.StencilBits = 8;  // Request a 8 bits stencil buffer
    settings.AntialiasingLevel = 2;  // Request 2 levels of antialiasing

    Window screen(VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,32), "Hello OpenGL!", Style::Close, settings); //set up screen

    screen.UseVerticalSync(false); //I hate vsync
    screen.SetFramerateLimit(60);

    glClearColor(0.0, 0.0, 0.0, 0.0); //when clearing, use black
    glClearDepth(1.0); //set clear depth for later use
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear GL screen

    glColor3f(1.0, 1.0, 1.0); //when drawing, use white
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0); //set up a rendering persepctive

    while (screen.IsOpened()){
        Event event;
        //const Input &input = screen.GetInput();
        while (screen.GetEvent(event)){
            if (event.Type == Event::Closed) //user clicked x in top right
                screen.Close();
            if ((event.Type == Event::KeyPressed) && (event.Key.Code == Key::Escape)) //user hit escape
                screen.Close();
            if (event.Type == Event::Resized) //resize GL viewport if needed
                glViewport(0, 0, event.Size.Width, event.Size.Height);
        }
        screen.SetActive();//necessary if there's ever multiple windows
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear everything out

        glBegin(GL_TRIANGLES); //draw a nice triangle
            glColor3f(1.0,0.0,0.0);//red
            glVertex2f(0.50, 0.75);
            glColor3f(0.0,1.0,0.0);//green
            glVertex2f(0.25, 0.25);
            glColor3f(0.0,0.0,1.0);//blue
            glVertex2f(0.75, 0.25);
        glEnd();
        glFlush();//send 'er over to SFML for drawing
        screen.Display();//draw everything to the screen
    }
    return 0;
}
