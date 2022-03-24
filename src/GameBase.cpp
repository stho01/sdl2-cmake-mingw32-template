#include "GameBase.h"
#include <SDL2/SDL_image.h>

GameBase::~GameBase()
{
    while (!_textures.empty()) {
        auto it = _textures.begin();
        _textures.erase(it);
        SDL_DestroyTexture(*it);
    }

    SDL_DestroyWindow(_window);
    _window = nullptr;

    IMG_Quit();
    SDL_Quit();
    printf("SDL Quit");
}

int GameBase::run()
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
        update();
        SDL_RenderClear(_renderer);
        draw(_renderer);
        SDL_RenderPresent(_renderer);
    }

    return 0;
}

bool GameBase::initSdl()
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

void GameBase::pollEvents(SDL_Event* e)
{
    while (SDL_PollEvent(e) != 0)
    {
        _quit = e->type == SDL_QUIT;
        if (!_quit)
            handleEvent(e);
    }
}

bool GameBase::initImg()
{
    const int imgFlags = IMG_INIT_PNG;

    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        printf("SDL_Image could not initialize! SDL_Image error: %s\n", IMG_GetError());
        return false;
    }

    return true;
}

bool GameBase::createWindow()
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

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

    return true;
}

SDL_Texture* GameBase::loadTexture(const std::string& path) {
    auto texture = IMG_LoadTexture(_renderer, path.c_str());

    if (texture != nullptr) {
        _textures.push_back(texture);
        return texture;
    }

    printf("Failed to load texture: %s", path.c_str());
    return nullptr;
}
