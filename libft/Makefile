# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 17:37:07 by blinnea           #+#    #+#              #
#    Updated: 2020/03/19 16:25:57 by blinnea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL=/bin/zsh
# **************************************************************************** #
#                                 COLOURS                                      #
# **************************************************************************** #
DEFAULT = \033[0m
YELLOW = \033[1;33m
GREEN = \033[1;32m
RED = \033[1;31m
GREENB = \033[42m

# **************************************************************************** #
#                               COMPILER OPTIONS                               #
# **************************************************************************** #
CC = gcc
CF = -Wall -Wextra -Werror

NAME = libft

# **************************************************************************** #
#                                 HEADERS                                      #
# **************************************************************************** #
FT_H =		include/$(NAME).h
LST_H =		include/$(NAME)_list.h
STR_H =		include/$(NAME)_string.h
CTP_H =		include/$(NAME)_ctype.h
IO_H =		include/$(NAME)_io.h

# **************************************************************************** #
#                                 FILENAMES                                    #
# **************************************************************************** #
FILES =		ft_memset ft_memdel ft_memalloc ft_bzero ft_memcpy ft_memccpy \
			ft_memmove ft_memchr ft_atoi ft_itoa ft_abs ft_labs ft_llabs \
			ft_memcmp
LSTFILES =	ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap \
			ft_lstdelone_ic ft_lstdel_ic ft_lstswptop ft_lstpoptop ft_lsttrans \
			ft_lstshftup ft_lstpopbot ft_lstshftdown ft_lstnew_ic ft_lstsize
STRFILES =	ft_strnew ft_strdel ft_strclr ft_striter ft_striteri ft_strlen \
			ft_strdup ft_strcpy ft_strmap ft_strmapi ft_strequ ft_strnequ \
			ft_strsub ft_strjoin ft_strtrim ft_strncpy ft_strcat ft_strncat \
			ft_strlcat ft_strchr ft_strrchr ft_strstr ft_strnstr ft_strcmp \
			ft_strncmp ft_strsplit
CTPFILES =	ft_isalnum ft_isascii ft_isprint ft_islower ft_isupper ft_toupper \
			ft_tolower ft_isblank ft_iscntrl ft_isalpha ft_isgraph ft_isspace \
			ft_ispunct ft_isxdigit ft_isdigit
IOFILES =	ft_putchar ft_putstr ft_putendl ft_putnbr ft_putchar_fd \
			ft_putstr_fd ft_putendl_fd ft_putnbr_fd
OFILES =	$(patsubst %, obj/%.o, $(FILES))
LSTOFILES =	$(patsubst %, obj/lst/%.o, $(LSTFILES))
STROFILES =	$(patsubst %, obj/str/%.o, $(STRFILES))
CTPOFILES =	$(patsubst %, obj/ctp/%.o, $(CTPFILES))
IOOFILES =	$(patsubst %, obj/io/%.o, $(IOFILES))

.PHONY: clean fclean re all

all: obj $(NAME).a

$(NAME).a: $(LSTOFILES) $(STROFILES) $(OFILES) $(CTPOFILES) $(IOOFILES)
	@ar rc $@ $(LSTOFILES) $(STROFILES) $(OFILES) $(CTPOFILES) $(IOOFILES)
	@ranlib $@
	@echo "\n> $(GREEN)$(NAME) created$(DEFAULT)"

obj:
	@mkdir -p obj
	@mkdir -p obj/str
	@mkdir -p obj/lst
	@mkdir -p obj/ctp
	@mkdir -p obj/io

# create $(OFILES)
obj/%.o: src/%.c $(FT_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create $(LSTOFILES)
obj/lst/%.o: src/lst/%.c $(FT_H) $(LST_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create $(STROFILES)
obj/str/%.o: src/str/%.c $(STR_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create $(CTPOFILES)
obj/ctp/%.o: src/ctp/%.c $(CTP_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create $(IOOFILES)
obj/io/%.o: src/io/%.c $(IO_H)
	@$(CC) $(CF) -c $< -o $@ -I include
	@echo "$(GREENB) $(DEFAULT)\c"

clean:
	@rm -f $(OFILES) $(LSTOFILES) $(STROFILES) $(CTPOFILES) $(IOOFILES)
	@rm -fd obj/str obj/lst obj/ctp obj/io obj
	@echo "> $(YELLOW)$(NAME) clean$(DEFAULT)"

fclean: clean
	@rm -f $(NAME).a
	@echo "> $(RED)$(NAME) fclean$(DEFAULT)"

re: fclean all
