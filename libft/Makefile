# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 17:37:07 by blinnea           #+#    #+#              #
#    Updated: 2020/03/12 01:00:16 by blinnea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
CC = gcc
CF = -Wall -Wextra -Werror
HEADER = include/$(NAME).h
FILES = ft_memset ft_memdel ft_strnew ft_strdel ft_strclr ft_striter \
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
			  ft_lstdelone_ic ft_lstdel_ic ft_lstswptop ft_lstpoptop \
			  ft_lsttrans ft_lstshftup ft_lstpopbot ft_lstshftdown
OFILES =  $(patsubst %, obj/%.o, $(FILES))

.PHONY: clean fclean re all

all: $(NAME).a

$(NAME).a: $(OFILES)
	ar rc $@ $^
	ranlib $@

obj/%.o: src/%.c $(HEADER)
	mkdir -p obj
	$(CC) $(CF) -c $< -o $@ -I include

clean:
	rm -f $(OFILES)

fclean: clean
	rm -d obj
	rm -f $(NAME).a

re: clean all
