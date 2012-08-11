/*4X_vertex.cpp
Functions related to loading and drawing vertex data
*/
#include "4X_vertex.h"

using namespace std;
using namespace sf;

vertex* loadVertexData(vertex *vertArray){
    ifstream filestr; //open vertex test
    filestr.open("vertex.txt");

    int numVertices; //determine number of verts
    string in;
    getline(filestr, in);
    numVertices = atoi(in.c_str());

    vertArray = new vertex[numVertices];
    vertArray[0].vertices = numVertices;
    for (int i = 0; i < numVertices; i++){ //load xyz values into array
        getline(filestr, in, ' ');
        vertArray[i].x = atof(in.c_str());
        getline(filestr, in, ' ');
        vertArray[i].y = atof(in.c_str());
        getline(filestr, in, ' ');
        vertArray[i].z = atof(in.c_str());
    }
    for (int i = 0; i < numVertices; i++){ //load rgb values
        getline(filestr, in, ' ');
        vertArray[i].r = atof(in.c_str());
        getline(filestr, in, ' ');
        vertArray[i].g = atof(in.c_str());
        getline(filestr, in, ' ');
        vertArray[i].b = atof(in.c_str());
       }
    return vertArray;
}

void drawVertexArray(vertex *v){
    glEnableClientState(GL_VERTEX_ARRAY); //tell openGL to use these when drawing arrays
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, sizeof(vertex), &v[0].x); //tell GL which arrays to use (ie give it a pointer)
    glColorPointer(3, GL_FLOAT, sizeof(vertex), &v[0].r);
    //static GLubyte indices[] = {0,1,2}; //tell GL which bits of the array to use
    //glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, indices); //go for it
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void moveVertexData(vertex *v, float x, float y, float z){
    for (int i = 0; i < v[0].vertices; i++){
        v[i].x += x;
        v[i].y += y;
        v[i].z += z;
    }
}
