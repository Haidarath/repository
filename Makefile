##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME = 106bombyx
CC = gcc -lm
SRC = 	srcs/106.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(SRC)

clean :
	rm -rf ./srcs/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all clean
