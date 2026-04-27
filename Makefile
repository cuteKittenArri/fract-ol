NAME := fractol
CC := cc
CFLAGS := -Wall -Werror -Wextra -O3 -march=native
MINI_LIB := -L./minilibx-linux -lmlx -lXext -lX11 -lm
SRC := main.c hooks.c meth.c render.c lib_utils.c
OBJ := $(SRC:.c=.o)
HEAD := fractol.h

all: fractol
	
fractol: $(OBJ)
	$(CC) $(CFLAGS) $(MINI_LIB) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)
	
re: clean all

.PHONY: all clean fclean re
