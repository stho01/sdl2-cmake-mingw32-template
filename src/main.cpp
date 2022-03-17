#include <iostream>
#include <SDL2/SDL.h>
#include "Lesson06.h"

using namespace std;

int main(int argc, char* args[]) {

    cout << "Success!" << endl;
    auto lesson = new Lesson06();
    lesson->run();
    delete lesson;
    return 0;
}