#pragma once
#include "LessonBase2.h"

class Lesson06 :
        public LessonBase2
{
public:
    Lesson06();
    ~Lesson06();

protected:
    bool loadMedias() override;
    void handleEvent(const SDL_Event* e) override;
    void loop() override;

private:

    SDL_Surface* _pngImage = nullptr;
};

