##
## EPITECH PROJECT, 2024
## bagar
## File description:
## Makefile
##

OS	:=	$(shell uname -s)

SRC	=	main.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=   client

ifeq ($(OS), Linux)
    CC	=	g++
    CFLAGS	=	-Wall -std=c++11
    LDFLAGS	=	-lraylib -lGL -lm -lpthread -ldl -lrt -lX11
    OUT	=	$(NAME)
endif

ifeq ($(OS), Windows_NT)
    CC	=	x86_64-w64-mingw32-g++
    CFLAGS	=	-Wall -std=c++11
    LDFLAGS	=	-lraylib -lopengl32 -lgdi32 -lwinmm
    OUT	=	$(NAME).exe
endif

all:	$(OUT)

$(OUT):	$(OBJ)
	$(CC) -o $(OUT) $(OBJ) $(LDFLAGS)

%.o:	%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean:	clean
	rm -f $(OUT)

re:	fclean all

.PHONY:	all clean fclean re
