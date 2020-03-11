# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 17:37:07 by blinnea           #+#    #+#              #
#    Updated: 2020/03/11 18:18:44 by blinnea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# library name
NAME = libft

# compiler
CC = gcc

# compilation flags
CF = -Wall -Wextra -Werror

# directories
SRCS = ./srcs
INCLUDES = ./includes
OBJS = ./objs

# header
LIBFT_HEADER = $(patsubst %, $(INCLUDES)/%.h, $(NAME))

# static library
LIBFT_SLIB = $(patsubst %, %.a, $(NAME))

# function names
LIBFT_FUNCS = ft_memset ft_memdel ft_strnew ft_strdel ft_strclr ft_striter \
			  ft_striteri ft_memalloc ft_bzero ft_memcpy ft_memccpy ft_memmove \
			  ft_memchr ft_strlen  ft_strdup ft_strcpy ft_strmap ft_strmapi \
			  ft_strequ ft_strnequ ft_strsub ft_strjoin ft_strtrim ft_strncpy \
			  ft_strcat ft_strncat ft_strlcat ft_strchr ft_strrchr ft_strstr \
			  ft_strnstr ft_strcmp ft_strncmp ft_atoi ft_isalpha ft_isdigit \
			  ft_isalnum ft_isascii ft_isprint ft_islower ft_isupper \
			  ft_toupper ft_tolower ft_itoa ft_strsplit ft_putchar ft_putstr \
			  ft_putendl ft_putnbr ft_abs ft_putchar_fd ft_putstr_fd \
			  ft_putendl_fd ft_putnbr_fd ft_lstnew ft_lstdelone ft_lstdel \
			  ft_memcmp ft_lstadd ft_lstiter ft_lstmap ft_isblank ft_iscntrl \
			  ft_isgraph ft_isspace ft_ispunct ft_isxdigit ft_labs ft_llabs \
			  ft_lstdelone_ic ft_lstdel_ic
# object files
LIBFT_O_FILES =  $(patsubst %, $(OBJS)/%.o, $(LIBFT_FUNCS))

.PHONY: clean fclean re all

all: $(LIBFT_SLIB)

$(LIBFT_SLIB): $(LIBFT_O_FILES)
	@ar rc $(LIBFT_SLIB) $(LIBFT_O_FILES)
	@ranlib $(LIBFT_SLIB)

$(OBJS)/%.o: $(SRCS)/%.c $(LIBFT_HEADER)
	@mkdir -p $(OBJS)
	@$(CC) $(CF) -c $< -o $@ -I $(INCLUDES)

clean:
	@rm -f $(LIBFT_O_FILES)

fclean: clean
	@rm -d $(OBJS)
	@rm -f $(LIBFT_SLIB)

re: clean all
