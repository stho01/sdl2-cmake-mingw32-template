#include "Game.h"

Game::Game() : GameBase("<insert_game_name_here>") {}
Game::~Game() {}

// ===========================================================

bool Game::loadMedias()
{
    // load medias here.

    _pngImage = loadTexture("assets/sprites/circle-black-32x32.png");

    return _pngImage != nullptr;
}

// ===========================================================

void Game::handleEvent(const SDL_Event* e)
{
    // event handling goes here.
}

// ===========================================================

void Game::update()
{
    // update logic goes here.
}

// ===========================================================

void Game::draw(SDL_Renderer* renderer)
{
    // draw logic goes here.
    SDL_Rect src = {0,0,32,32};
    SDL_Rect dst = {0,0,32,32};

    SDL_RenderCopy(
        renderer,
        _pngImage,
        &src,
        &dst);
}
