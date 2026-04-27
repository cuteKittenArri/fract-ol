NAME := fractol
CC := cc
CFLAGS := -Wall -Werror -Wextra -MMD -MP -O3 -march=native
MINI_LIB := -L./minilibx-linux -lmlx -lXext -lX11 -lm
SRCS := main.c hooks.c meth.c render.c lib_utils.c
OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)
HEAD := fractol.h

all: fractol
	
fractol: $(OBJS)
	$(CC) $(CFLAGS) $(MINI_LIB) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS) $(DEPS)
	
fclean: clean
	rm -rf $(NAME)
	
re: clean all

.PHONY: all clean fclean re

-include $(DEPS)
