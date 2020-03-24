# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/12 01:02:33 by blinnea           #+#    #+#              #
#    Updated: 2020/03/19 16:25:38 by blinnea          ###   ########.fr        #
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
CF =		-Wall -Wextra -Werror -g

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
PSFILES =	ps_del ps_lstnew ps_chcklst ps_atoi ps_crtlst ps_procui ps_print \
			ps_debuginfo ps_lstsorted ps_giveindex ps_dact ps_showstcks
TAFILES =	ps_sa ps_sb ps_ss ps_pa ps_pb ps_ra ps_rb ps_rr ps_rra ps_rrb \
			ps_rrr ps_showact
PSOFILES =	$(patsubst %, obj/$(LPS)/%.o, $(PSFILES))
TAOFILES =	$(patsubst %, obj/$(TA)/%.o, $(TAFILES))
GNL_C =		$(GNL)/$(GNL).c
GNL_O =		$(GNL)/$(GNL).o

.PHONY:	fclean_$(LFT) $(LFT) clean fclean re all

all: checker push_swap

obj:
	@mkdir -p obj
	@mkdir -p obj/$(LPS)
	@mkdir -p obj/$(TA)

checker: src/checker.c $(LFT_H) $(LPS_H) $(LFT) $(PSOFILES) $(TAOFILES)
	@gcc -g $< $(GNL_C) $(PSOFILES) $(TAOFILES) -L$(LFT) -lft -o $@ -I $(GNL) -I $(LFT)/include -I include
	@echo "\n> $(GREEN)$@ created$(DEFAULT)"

push_swap: src/push_swap.c $(LFT_H) $(LPS_H) $(LFT) $(PSOFILES) $(TAOFILES)
	@gcc -g $< $(GNL_C) $(PSOFILES) $(TAOFILES) -L$(LFT) -lft -o $@ -I $(GNL) -I $(LFT)/include -I include
	@echo "\n> $(GREEN)$@ created$(DEFAULT)"

$(LFT):
	@make all -C $(LFT)

fclean_$(LFT):
	@make fclean -C $(LFT)

# create $(PSOFILES)
obj/$(LPS)/%.o: src/$(LPS)/%.c obj $(LPS_H) $(LFT_H) $(LFT) $(GNL_H) $(GNL_C)
	@$(CC) $(CF) -c $< -o $@ -I $(LFT)/include -I include -I $(GNL)
	@echo "$(GREENB) $(DEFAULT)\c"

# create $(TAOFILES)
obj/$(TA)/%.o: src/$(TA)/%.c obj $(LPS_H) $(LFT_H) $(LFT) $(GNL_H) $(GNL_C)
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
