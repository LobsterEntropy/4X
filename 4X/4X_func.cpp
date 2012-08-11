#include "4X_func.h"

using namespace std;
using namespace sf;

void displayFPS(){ //display an FPS counter
    String framerate; //set up FPS counter
    framerate.SetFont(Font::GetDefaultFont());
    framerate.Move(10.f, 10.f);

    float fps = 1.f / screen.GetFrameTime(); //fps drawing code
    char fpsConvert[20];
    sprintf(fpsConvert, "%.2f", fps);
    framerate.SetText(fpsConvert);
    screen.Draw(framerate);
}

void glInit(){ //various OpenGL init things
    glClearColor(0.0, 0.0, 0.0, 0.0); //when clearing, use black
    glClearDepth(1.0); //set clear depth for later use
    glClear(GL_COLOR_BUFFER_BIT); //clear GL screen

    glColor3f(1.0, 1.0, 1.0); //when drawing, use white
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    /*set up a rendering persepctive (left, right, bottom, top, behind and forward)
    Imagine a 1x1x2 cube where the camera is showing the exact middle slice of that cube*/
}

void handleEvents(){ //deal with quitting, mainly
    Event event;
    while (screen.GetEvent(event)){
        if (event.Type == Event::Closed) //user clicked x in top right
            screen.Close();
        if ((event.Type == Event::KeyPressed) && (event.Key.Code == Key::Escape)) //user hit escape
            screen.Close();
        if (event.Type == Event::Resized) //resize GL viewport if needed
            glViewport(0, 0, event.Size.Width, event.Size.Height);
    }
}
