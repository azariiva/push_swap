# compiler
CC = gcc

# compilation flags
CF = -Wall -Wextra -Werror

# directories
SRCS = ./srcs
INCLUDES = ./includes
OBJS = ./objs

LIBFT_PATH = ./libft

.PHONY: libft clean fclean re all

libft:
	@make -C $(LIBFT_PATH)
	@cp $(LIBFT_PATH)/libft.a ./libft.a

all: libft

clean:
	@make $@ -C $(LIBFT_PATH)
	@rm -f ./libft.a

fclean: clean
	@make $@ -C $(LIBFT_PATH)

re: clean all