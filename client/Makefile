##
## EPITECH PROJECT, 2024
## bagar
## File description:
## Makefile
##

OS	:=	$(shell uname -s)

SRC	=	main.cpp \
        Game.cpp \
        connection/client.cpp \
        scene/AScene.cpp \
        scene/SceneManager.cpp \
        data/GlobalData.cpp \
        scene/type/Menu.cpp \
        scene/type/MapTest.cpp \
        objects/Audio.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=   client

ifeq ($(OS), Linux)
    CC	=	g++
    CFLAGS	=   -std=c++20 -Iinclude -g
    LDFLAGS	=	-lraylib
    OUT	=	$(NAME)
endif

ifeq ($(OS), Windows_NT)
    CC	=	x86_64-w64-mingw32-g++
    CFLAGS	=   -std=c++20 -Iinclude -g
    LDFLAGS	=	-lraylib -lopengl32 -lgdi32 -lwinmm
    OUT	=	$(NAME).exe
endif

all:	$(OUT)

$(OUT):	$(OBJ)
	$(CC) -o $(OUT) $(OBJ) $(LDFLAGS)

%.o:	%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(OUT)

re:	fclean all

.PHONY:	all clean fclean re
