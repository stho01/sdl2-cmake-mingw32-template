#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"

using namespace std;

int main(int argc, char* args[]) {
    cout << "Success!" << endl;
    Game lesson;
    lesson.run();
    return 0;
}