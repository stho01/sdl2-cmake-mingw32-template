#pragma once
#include "LessonBase.h"

/**
 * LazyFoo lesson 06
 * https://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/index.php
 */

class Lesson06 : public LessonBase
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

