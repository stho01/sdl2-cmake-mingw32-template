#pragma once

class LessonBase
{
public:
    virtual ~LessonBase() = default;
    virtual int run() = 0;

    static const int SCREEN_WIDTH = 640;
    static const int SCREEN_HEIGHT = 480;
};
