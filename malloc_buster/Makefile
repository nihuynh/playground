# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 02:25:13 by nihuynh           #+#    #+#              #
#    Updated: 2018/11/27 06:28:01 by nihuynh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifneq ($(words $(MAKECMDGOALS)),1)
.DEFAULT_GOAL = all
%:
	@$(MAKE) $@ --no-print-directory -rRf $(firstword $(MAKEFILE_LIST))
else
ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
      -nrRf $(firstword $(MAKEFILE_LIST)) \
      ECHO="COUNTTHIS" | grep -c "COUNTTHIS")
N := x
C = $(words $N)$(eval N := x $N)
ECHO = echo -ne "\r [`expr $C '*' 100 / $T`%]"
endif

NAME	:=	malloc_buster.out
SRC		:=	main.c
# **************************************************************************** #
CC		:=	clang
CFLAGS	:=	-Werror -Wall -Wextra
OBJ		:=	$(SRC:.c=.o)
# **************************************************************************** #
all : $(NAME)
	@$(ECHO) All done
.PHONY: all
$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $<
	@$(ECHO) Linking $@
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@$(ECHO) Compiling $@

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
endif
