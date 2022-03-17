#include "Lesson06.h"

Lesson06::Lesson06() : LessonBase("Lesson 06 - Extension libs and loading other image formats")
{

}

Lesson06::~Lesson06()
{

}

bool Lesson06::loadMedias()
{
    _pngImage = loadSurface("assets/sprites/circle-black-32x32.png");
    return true;
}

void Lesson06::handleEvent(const SDL_Event* e)
{

}

void Lesson06::loop()
{
    drawToScreen(_pngImage);
}