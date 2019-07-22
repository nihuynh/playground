# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 11:26:19 by nihuynh           #+#    #+#              #
#    Updated: 2019/07/22 11:34:55 by nihuynh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	ft_ls
RUNMODE		?=	release
# RUNMODE		?=	dev
# VERBOSE	:= TRUE
SRC			:=	 main.c
# directories :
VPATH		:=	./srcs

LIB_DEP		=	../../../RT/lib/libft/libft.a

RESDIR		=	./resources
# **************************************************************************** #
# Makefile dependency :
include ../../../RT/lib/libft/mk_c_project.mk
include ../../../RT/lib/libft/mk_lib_dep.mk
# **************************************************************************** #
# Target rules :
.DEFAULT_GOAL := all
all: $(LIB_BUILT) $(NAME) ## Built the project.
.PHONY: all

$(NAME): $(LIB_DEP) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(INC) $(LIB_LINK)
	@printf "\033[1;34m$(NAME)\033[25G\033[32mBuilt $@ $(OKLOGO)\n"
-include $(DEP)

fclean: $(LIB_DEP_CLEAN) clean ## Full clean of the project & the libs.
	$(RM) $(NAME)
	@printf "\033[1;34m$(NAME)\033[25G\033[31mCleaning $(NAME) $(OKLOGO)"
.PHONY: fclean

norme: ## Check the norme of the project and the libraries.
	norminette srcs includes | $(GREP_ERR)
	@printf "\033[1;34m$(NAME)\033[25G\033[31mNorminette $(OKLOGO)"
.PHONY: norme