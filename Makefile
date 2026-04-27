NAME := fractol
CC := cc
CFLAGS := -Wall -Werror -Wextra
SRC := main.c hooks.c meth.c render.c lib_utils.c
OBJ := $(SRC:.c=.o)
HEAD := fractol.h

all: fractol
	
fractol: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)
	
re: clean all

.PHONY: all clean fclean re
