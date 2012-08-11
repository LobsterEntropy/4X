/*4X_vertex.h
Functions related to vertex data
*/
#include <iostream>
#include <fstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#ifndef _4X_VERT_H
#define _4X_VERT_H


struct vertex{
        GLint vertices;
        GLfloat x,y,z;
        GLfloat r,g,b;
};

void drawVertexArray(vertex *v);

vertex* loadVertexData(vertex *vertArray);

void moveVertexData(vertex *v,float x, float y, float z);

#endif
