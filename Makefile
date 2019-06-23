# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/04 10:52:30 by dlabadie          #+#    #+#              #
#    Updated: 2019/05/09 12:26:01 by dlabadie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dlabadie.filler

CC = gcc
FLAGS = -Wall -Wextra -Werror

OBJS	:= create.o delete.o loop.o pre_read.o default.o filler.o compute.o solve.o init_solve_map.o

FT		:= ./libft/
FT_LIB	:= $(addprefix $(FT), libft.a)
FT_INC	:= -I $(FT)/includes/
FT_LNK	:= -L $(FT) -lft

ODIR	:= ./obj/
IDIR	:= ./includes/

SDIR	:= ./src/main/
IPDIR	:= ./src/input/
SOLDIR	:= ./src/solve/

$(ODIR)%.o:$(SDIR)%.c
	gcc $(FLAGS) $(FT_INC) -I $(IDIR) -o $@ -c $<

$(ODIR)%.o:$(IPDIR)%.c
	gcc $(FLAGS) $(FT_INC) -I $(IDIR) -o $@ -c $<

$(ODIR)%.o:$(SOLDIR)%.c
	gcc $(FLAGS) $(FT_INC) -I $(IDIR) -o $@ -c $<

OFILES	:= $(addprefix $(ODIR),$(OBJS))


all: $(NAME)

$(FT_LIB):
	make -C $(FT)

obj:
	mkdir obj

$(NAME): obj $(FT_LIB) $(OFILES)
	gcc -o $(NAME) $(OFILES) -I./includes/ $(FT_INC) $(FT_LNK)


clean:
	rm -fr $(ODIR)*.o
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all

.PHONY : all clean fclean re

