# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 18:10:56 by nihuynh           #+#    #+#              #
#    Updated: 2019/03/10 05:24:09 by nihuynh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	fibo.log
EXE		:=	mono.out thread.out pool.out
MONO	:=	fibo_mono.c
THREAD	:=	fibo_thread.c
POOL	:=	fibo_pool.c pool.c
SRC		:=	ft_fibonacci.c $(MONO) $(THREAD) $(POOL)
# **************************************************************************** #
CC		:=	clang
CFLAGS	:=	-Werror -Wall -Wextra
OBJ		:=	$(SRC:.c=.o)
# **************************************************************************** #
all : $(EXE)
	time ./mono.out > fibo.log
	time ./thread.out >> fibo.log
	time ./pool.out >> fibo.log
.PHONY: all

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
mono.out : $(OBJ)
	$(CC) $(CFLAGS) -o $@ ft_fibonacci.o fibo_mono.o
thread.out : $(OBJ)
	$(CC) $(CFLAGS) -o $@ ft_fibonacci.o fibo_thread.o
pool.out : $(OBJ)
	$(CC) $(CFLAGS) -o $@ ft_fibonacci.o fibo_pool.o pool.o

clean :
	rm -f $(OBJ)
	rm -f $(EXE)
.PHONY: clean

fclean : clean
	rm -f $(NAME)
.PHONY: fclean

re : fclean all
.PHONY: re
