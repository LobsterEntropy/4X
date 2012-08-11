/*
Various functions (mostly graphics-related) for the 4X project
(real specific I know)
*/
#ifndef _4X_FUNC_H
#define _4X_FUNC_H

#include <stdio.h>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "4X_constants.h"

extern sf::RenderWindow screen;

void displayFPS();
void glInit();
void handleEvents();
#endif
