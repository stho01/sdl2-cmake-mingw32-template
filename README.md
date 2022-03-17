# SDL2 With CMake and MinGW

A basic template for building apps/games using the SDL2 libraries with CMake and MinGW compiler on Windows.

Typical folder structure:
* /include - your header files. 
* /src - your source a.k.a. .cpp files. 
* /assets - your assets goes here. (images, sounds etc.) 
* /build/modules - Your custom CMake modules. 

Your compiled binaries ends up under `/bin/<CMAKE_BUILD_TYPE>`

## Install MinWG compiler

There is a list of compilers you can download here: \
[https://www.mingw-w64.org/downloads/](https://www.mingw-w64.org/downloads/) \

Here is the one that I use and I know works:

[MingW-W64-builds](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download)

Run the installer and leave all the options as-is if you want the 64bit compiler.  

## Install CMake

... TODO

## Install SDL2 and SDL2_image

### Download

Download libs for mingw compiler.

* [SDL2](https://www.libsdl.org/download-2.0.php)
* [SDL2_image](https://www.libsdl.org/projects/SDL_image/)

There should be some .gz files where the name is something like this:

* SDL2-devel-2.0.20-mingw.tar.gz
* SDL2_image-devel-2.0.5-mingw.tar.gz


### Install 

Make a folder where ever you like on your system. \
For this example we will keep it simple and installing the libs to `C:/SDL` 

Move the downloaded files to your newly created folder \
Use your preferred extracting tool (e.g 7z) and extract the gz files \
and then once again extract the .tar files.

You should now be able to inspect the folders in Windows Explorer. 

Okey..\
Now we want to copy the libs out the the root of the folder you just made. \
For 64bit version copy the content of the i686 folder and for the 32bit version copy the content of x86 \

Example 32bit: 
inside SDL2-x.x.x/x86_64-w64-mingw32/

copy: \
`bin/` \
`include/` \
`lib/` \
to: \
`C:/SDL`


### Configure the CMakeLists.txt 

> NOTE: This step applies only if you chose to install SDL to another folder than `C:/SDL`

Make sure that the SDL2 variables inside the CMakeLists.txt file points to the SDL2 directories
```
set(SDL2_LIB_DIR C:/SDL/lib)
set(SDL2_INCLUDE_DIR C:/SDL/include)
set(SDL2_LIBRARY C:/SDL/bin)
```

Replace the `C:/SDL` with the path the folder where you installed SDL.   

## Clion setup

... TODO

## Cmake CLI

... todo