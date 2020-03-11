# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/12 01:02:33 by blinnea           #+#    #+#              #
#    Updated: 2020/03/12 01:07:06 by blinnea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CF = -Wall -Wextra -Werror

GNL = get_next_line
LFT = libft

LFT_HEADER = $(LFT)/include/$(LFT).h
LFT_SLIB = $(LFT)/$(LFT).a

# function names
FILES = checker

# object files
OFILES = $(patsubst %, obj/%.o, $(FILES))

.PHONY: clean $(LFT) fclean re all

all: $(OFILES) $(GNL)/$(GNL).o $(LFT)
	gcc $(OFILES) $(GNL)/$(GNL).o -L$(LFT) -lft -o checker

$(LFT):
	make -C $(LFT)

$(GNL)/$(GNL).o: $(GNL)/$(GNL).c $(GNL)/$(GNL).h $(LFT_HEADER) $(LFT)
	$(CC) $(CF) -c $< -o $@ -I $(GNL) -I $(LFT)/include \
	-L$(LFT) -lft

obj/%.o: src/%.c $(LFT_HEADER)
	mkdir -p obj
	$(CC) $(CF) -c $< -o $@ -I $(GNL) -I $(LFT)/include

clean:
	make fclean -C $(LFT)
	rm -f $(GNL)/$(GNL).o
	rm -f $(OFILES)

fclean: clean
	rm -f checker

re: clean all