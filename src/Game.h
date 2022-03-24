#pragma once
#include "GameBase.h"

class Game : public GameBase
{
public:
    Game();
    ~Game();

protected:
    bool loadMedias() override;
    void handleEvent(const SDL_Event* e) override;
    void update() override;
    void draw(SDL_Renderer* renderer) override;

private:

    SDL_Texture* _pngImage = nullptr;
};

