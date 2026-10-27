NAME = libftprintf.a 
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_utils_printf.c
OBJ  = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	cc $(FLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re: clean fclean all

.PHONY: all re clean fclean 
