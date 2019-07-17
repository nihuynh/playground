# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 02:25:13 by nihuynh           #+#    #+#              #
#    Updated: 2019/07/17 13:48:22 by nihuynh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all
include mk_progress.mk

NAME	:=	malloc_buster.out
SRC		:=	doublefree.c
# **************************************************************************** #
CC		:=	clang
CFLAGS	:=	-Werror -Wall -Wextra
OBJ		:=	$(SRC:.c=.o)
# **************************************************************************** #
all : $(NAME)
.PHONY: all
$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $<
	@echo Linking $@ $(PROGRESS)
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo Compiling $@ $(PROGRESS)

clean :
	@rm -f $(OBJ)
.PHONY: clean
fclean : clean
	@rm -f $(NAME)
.PHONY: fclean
re : fclean all
.PHONY: re
run: all
	@./$(NAME)
.PHONY: run
