#pragma once
#include <SDL.h>
#include <string>
#include "LessonBase.h"

class LessonBase2 : public LessonBase
{
public:

    ~LessonBase2() override;

    int run() override;

protected:

    explicit LessonBase2(const std::string title)
            : _title(title) { }

    virtual bool loadMedias() = 0;
    virtual void handleEvent(const SDL_Event* e) = 0;
    virtual void loop() = 0;

    bool initSdl();
    SDL_Surface* loadSurface(const std::string path) const;

    void drawToScreen(SDL_Surface* surface) const;
    void drawToScreen(SDL_Surface* surface, SDL_Rect* rect) const;

private:

    void pollEvents(SDL_Event* e);
    static bool initImg();
    bool createWindow();

    std::string _title = nullptr;
    SDL_Window* _window = nullptr;
    SDL_Surface* _windowSurface = nullptr;
    bool _quit = false;
};