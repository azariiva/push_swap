# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/12 01:02:33 by blinnea           #+#    #+#              #
#    Updated: 2020/07/10 20:05:31 by blinnea          ###   ########.fr        #
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
LFT =		libft

# **************************************************************************** #
#                                 HEADERS                                      #
# **************************************************************************** #
LFT_H =		$(LFT)/include/$(LFT).h
LPS_H =		include/libps.h
PSW_H =		include/libps_push_swap.h
STK_H =		include/libps_stack.h

ALL_H = $(LFT_H) $(LPS_H) $(PSW_H) $(STK_H) $(GNL_H)

# **************************************************************************** #
#                                 FILENAMES                                    #
# **************************************************************************** #
PSFILES =	$(shell find src/libps -name '*.c')
PSOFILES =	$(addprefix obj/, $(PSFILES:src/libps/%.c=%.o))

.PHONY: $(LFT) clean fclean re all

all: checker push_swap
	@echo "\n> $(GREEN)push_swap was created$(DEFAULT)"

# create obj directory
obj:
	@mkdir -p obj

# create checker executable
checker: obj/checker.o $(PSOFILES) $(LFT)
	@$(CC) $< $(PSOFILES) -L$(LFT) -lft -o $@

# create push_swap executable
push_swap: obj/push_swap.o $(PSOFILES) $(LFT)
	@$(CC) $< $(PSOFILES) -L$(LFT) -lft -o $@

# create push_swap.o
obj/push_swap.o: src/push_swap.c obj $(ALL_H)
	@$(CC) $(CF) -c $< -o $@ -I $(LFT)/include -I $(GNL)/include -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create checker.o
obj/checker.o: src/checker.c obj $(ALL_H)
	@$(CC) $(CF) -c $< -o $@ -I $(LFT)/include -I $(GNL)/include -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# create $(PSOFILES)
obj/%.o: src/libps/%.c obj $(ALL_H)
	@$(CC) $(CF) -c $< -o $@ -I $(LFT)/include -I include -I $(GNL)/include
	@echo "$(GREENB) $(DEFAULT)\c"

# create libft.a
$(LFT):
	@make all -C $(LFT)

fclean: clean
	@rm -f checker push_swap
	@echo "> $(RED)push_swap fclean$(DEFAULT)"

clean:
	@make fclean -C $(LFT)
	@rm -f $(PSOFILES) obj/push_swap.o obj/checker.o
	@rm -fd obj
	@echo "> $(YELLOW)push_swap clean$(DEFAULT)"

re: fclean all
