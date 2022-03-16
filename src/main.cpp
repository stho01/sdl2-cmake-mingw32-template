#include <iostream>
#include <SDL.h>
#include "Lesson06.h"

using namespace std;

int main(int argc, char* args[]) {
    auto lesson = new Lesson06();
    lesson->run();
    delete lesson;
    return 0;
}