#include "LessonBase2.h"
#include <SDL2/SDL_image.h>

LessonBase2::~LessonBase2()
{
    SDL_DestroyWindow(_window);

    _window = nullptr;

    IMG_Quit();
    SDL_Quit();
    printf("SDL Quit");
}

int LessonBase2::run()
{
    if (!initSdl())
    {
        printf("Failed to init SDL");
        return -1;
    }

    if (!loadMedias())
    {
        printf("Failed to load medias");
        return -1;
    }

    SDL_Event e;
    while(!_quit)
    {
        pollEvents(&e);
        loop();
        SDL_UpdateWindowSurface(_window);
    }

    return 0;
}

bool LessonBase2::initSdl()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Failed to init SDL! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    if (!createWindow())
        return false;

    if (!initImg())
        return false;

    return true;
}

SDL_Surface* LessonBase2::loadSurface(const std::string path) const
{
    auto* loaded = IMG_Load(path.c_str());
    if (loaded == nullptr)
    {
        printf("Failed load image %s! SDL Error: %s\n", path.c_str(), IMG_GetError());
        return nullptr;
    }

    auto* optimized = SDL_ConvertSurface(
            loaded,
            _windowSurface->format,
            0);

    SDL_FreeSurface(loaded);

    return optimized;
}

void LessonBase2::drawToScreen(SDL_Surface* surface) const
{
    SDL_BlitSurface(surface, nullptr, _windowSurface, nullptr);
}

void LessonBase2::drawToScreen(SDL_Surface* surface, SDL_Rect* rect) const
{
    SDL_BlitScaled(surface, nullptr, _windowSurface, rect);
}

void LessonBase2::pollEvents(SDL_Event* e)
{
    while (SDL_PollEvent(e) != 0)
    {
        _quit = e->type == SDL_QUIT;
        if (!_quit)
            handleEvent(e);
    }
}

bool LessonBase2::initImg()
{
    const int imgFlags = IMG_INIT_PNG;

    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        printf("SDL_Image could not initialize! SDL_Image error: %s\n", IMG_GetError());
        return false;
    }

    return true;
}

bool LessonBase2::createWindow()
{
    _window = SDL_CreateWindow(
            _title.empty() ? "SDL Lesson" : _title.c_str(),
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);

    if (_window == nullptr)
    {
        printf("Unable to create window! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    _windowSurface = SDL_GetWindowSurface(_window);

    return true;
}