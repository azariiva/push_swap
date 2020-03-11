# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/12 01:02:33 by blinnea           #+#    #+#              #
#    Updated: 2020/03/12 01:18:17 by blinnea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CF = -Wall -Wextra -Werror

GNL = get_next_line
LFT = libft

LFT_HEADER = $(LFT)/include/$(LFT).h
LFT_SLIB = $(LFT)/$(LFT).a

# function names
CHFILES = checker

# object files
CHOFILES = $(patsubst %, obj/checker/%.o, $(CHFILES))
PSOFILES = $(patsubst %, obj/push_swap/%.o, $(PSFILES))

.PHONY: clean $(LFT) fclean re all

all: checker push_swap

checker: $(CHOFILES) $(GNL)/$(GNL).o $(LFT)
	gcc $(CHOFILES) $(GNL)/$(GNL).o -L$(LFT) -lft -o checker

push_swap: $(PSOFILES) $(LFT)

$(LFT):
	make -C $(LFT)

$(GNL)/$(GNL).o: $(GNL)/$(GNL).c $(GNL)/$(GNL).h $(LFT_HEADER)
	$(CC) $(CF) -c $< -o $@ -I $(GNL) -I $(LFT)/include

obj/checker/%.o: src/%.c $(LFT_HEADER)
	mkdir -p obj/checker
	$(CC) $(CF) -c $< -o $@ -I $(GNL) -I $(LFT)/include

obj/push_swap/%.o: src/%.c $(LFT_HEADER)
	$(CC) $(CF) -c $< -o $@ -I $(LFT)/include

clean:
	make fclean -C $(LFT)
	rm -f $(GNL)/$(GNL).o
	rm -f $(CHOFILES) $(PSOFILES)

fclean: clean
	rm -f checker push_swap

re: clean all