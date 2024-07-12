# bagar
bagarfield

# Installation on Windows 10/11 :

GIT : https://git-scm.com/download/win

MinGW-w64 : ajouter le fichier "mingw64" au "C:",
taper -> window & chercher "Edit the environment variables" puis dans "PATH" ajouter une nouvelle variable -> "C:\mingw64\bin".
Ouvre un "CMD" et execute "gcc --version".

RAYLIB : ajouter le fichier "raylib-5.0_win32_mingw-w64" au "C:"

# Installation on Linux :

RAYLIB : Ask chatGPT

# Execute bagar :

linux : make
window : mingw32-make

## Protocol :

ppo #n X Y O\n        player’s position


-I"C:\raylib\include" -L"C:\raylib\lib" -lraylib -lopengl32 -lgdi32 -lwinmm