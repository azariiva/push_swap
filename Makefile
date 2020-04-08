# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/12 01:02:33 by blinnea           #+#    #+#              #
#    Updated: 2020/04/08 15:51:28 by blinnea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL=/bin/zsh
# **************************************************************************** #
#                                 COLOURS                                      #
# **************************************************************************** #
DEFAULT =	\033[0m
YELLOW =	\033[1;33m
GREEN =		\033[1;32m
RED =		\033[1;31m
GREENB =	\033[42m

# **************************************************************************** #
#                               COMPILER OPTIONS                               #
# **************************************************************************** #
CC =		gcc
CF =		-Wall -Wextra -Werror

# **************************************************************************** #
#                               ABBREVIATIONS                                  #
# **************************************************************************** #
GNL =		get_next_line
LFT =		libft
LPS =		libps
TA =		tskact

# **************************************************************************** #
#                                 HEADERS                                      #
# **************************************************************************** #
GNL_H =		$(GNL)/$(GNL).h
LFT_H =		$(LFT)/include/$(LFT).h
LPS_H =		include/$(LPS).h

# **************************************************************************** #
#                                 FILENAMES                                    #
# **************************************************************************** #
PSFILES =	t_stack t_push_swap
PSOFILES =	$(patsubst %, obj/$(LPS)/%.o, $(PSFILES))
GNL_C =		$(GNL)/$(GNL).c
GNL_O =		$(GNL)/$(GNL).o

.PHONY:	fclean_$(LFT) $(LFT) clean fclean re all

all: checker push_swap

obj:
	@mkdir -p obj
	@mkdir -p obj/$(LPS)

checker: src/checker.c $(LFT_H) $(LPS_H) $(LFT) $(PSOFILES)
	@gcc $< $(GNL_C) $(PSOFILES) -L$(LFT) -lft -o $@ -I $(GNL) -I $(LFT)/include -I include
	@echo "\n> $(GREEN)$@ created$(DEFAULT)"

push_swap: src/push_swap.c $(LFT_H) $(LPS_H) $(LFT) $(PSOFILES)
	@gcc $< $(GNL_C) $(PSOFILES) -L$(LFT) -lft -o $@ -I $(GNL) -I $(LFT)/include -I include
	@echo "\n> $(GREEN)$@ created$(DEFAULT)"

$(LFT):
	@make all -C $(LFT)

fclean_$(LFT):
	@make fclean -C $(LFT)

# create $(PSOFILES)
obj/$(LPS)/%.o: src/$(LPS)/%.c obj $(LPS_H) $(LFT_H) $(LFT) $(GNL_H) $(GNL_C)
	@$(CC) $(CF) -c $< -o $@ -I $(LFT)/include -I include -I $(GNL)
	@echo "$(GREENB) $(DEFAULT)\c"

fclean: clean
	@rm -f checker push_swap
	@echo "> $(RED)push_swap fclean$(DEFAULT)"

clean: fclean_$(LFT)
	@rm -f $(PSOFILES) $(TAOFILES) obj/push_swap.o obj/checker.o $(GNL_O)
	@rm -fd obj/$(LPS) obj/$(TA) obj
	@echo "> $(YELLOW)push_swap clean$(DEFAULT)"

re: fclean all
