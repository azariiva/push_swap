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
	@cp -u $(LIBFT_PATH)/libft.a .

all: checker.out
	
checker.out: libft checker.c
	@$(CC) $(CF) checker.c -o checker.out -L. -lft

clean:
	@make $@ -C $(LIBFT_PATH)
	@rm -f ./libft.a

fclean: clean
	@make $@ -C $(LIBFT_PATH)
	@rm -f checker.out

re: clean all