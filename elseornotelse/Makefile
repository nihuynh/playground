# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 18:10:56 by nihuynh           #+#    #+#              #
#    Updated: 2018/12/12 17:55:01 by nihuynh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	elseornotelse.log
SRC		:=	else.c notelse.c
# **************************************************************************** #
CC		:=	clang
CFLAGS	:=	-Werror -Wall -Wextra -S
OBJ		:=	$(SRC:.c=.s)
LOGFILE	:=	$(SRC:.c=.log)
# **************************************************************************** #
all : $(NAME)
.PHONY: all
$(NAME) : $(OBJ)
yoyoy

%.s: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean :
	rm -f $(OBJ)
	rm -f $(LOGFILE)
.PHONY: clean
fclean : clean
	rm -f $(NAME)
.PHONY: fclean
re : fclean all
.PHONY: re
