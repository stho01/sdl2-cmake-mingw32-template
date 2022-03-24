#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <vector>

class GameBase
{
public:
    static const int SCREEN_WIDTH = 640;
    static const int SCREEN_HEIGHT = 480;

public:
    ~GameBase();

    int run();

protected:
    explicit GameBase(const std::string title) : _title(title) { }

    virtual bool loadMedias() = 0;
    virtual void handleEvent(const SDL_Event* e) = 0;
    virtual void update() = 0;
    virtual void draw(SDL_Renderer* renderer) = 0;

    SDL_Texture* loadTexture(const std::string& path);

    bool initSdl();

private:
    void pollEvents(SDL_Event* e);
    static bool initImg();
    bool createWindow();

private:
    std::vector<SDL_Texture*> _textures;
    std::string _title = nullptr;
    SDL_Window* _window = nullptr;
    SDL_Renderer* _renderer = nullptr;
    bool _quit = false;
};