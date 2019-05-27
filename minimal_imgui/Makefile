# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 18:10:56 by nihuynh           #+#    #+#              #
#    Updated: 2019/05/26 20:32:49 by nihuynh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= mini_imgui
RUNMODE	?=	release
SRC		:=	engine_loop.c engine_render.c engine.c engine_free.c\
			tools.c main.c cimgui.c
SRC		+=	fractol.c
LIB_DEP		=	../RT/lib/imgui_impl/libimgui_impl.a
# **************************************************************************** #
include basic.mk
include basic_lib.mk

# Additionnal linkers :
ifeq ($(shell uname -s), Linux)
	CIMGUI_NAME = cimgui.so
endif
ifeq ($(shell uname -s), Darwin)
	CIMGUI_NAME = cimgui.dylib
endif
CIMGUI_TARGET :=	../RT/lib/cimgui/$(CIMGUI_NAME)

# directories :
VPATH       :=	./srcs
# **************************************************************************** #
# Additionnal linkers :
# SDL
INC			+=	$(shell sdl2-config --cflags)
LIB_LINK	+=	$(shell sdl2-config --libs)
INC			+=	-I $(dir $(CIMGUI_TARGET))
LIB_LINK	+=	$(CIMGUI_NAME) -lstdc++ -framework OpenGl
# **************************************************************************** #
# Target rules :
.DEFAULT_GOAL := all
all: $(NAME)  ## Built the project.
.PHONY: all

$(NAME): $(CIMGUI_NAME) $(OBJ) $(LIB_DEP)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(INC) $(LIB_LINK)
	@printf "\033[1;34m$(NAME)\033[25G\033[32mBuilt $@ $(OKLOGO)\n"
-include $(DEP)

$(CIMGUI_NAME):
	$(MAKE) -sC $(dir $(CIMGUI_TARGET))
	cp $(CIMGUI_TARGET) .
fclean : clean  $(LIB_DEP_CLEAN) ## Clean the project.
	rm -f $(NAME)
