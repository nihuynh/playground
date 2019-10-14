# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 18:10:56 by nihuynh           #+#    #+#              #
#    Updated: 2019/06/02 20:14:47 by nihuynh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= mini_imgui
RUNMODE	?=	release
SRC		:=	engine_loop.c engine_render.c engine.c engine_free.c\
			tools.c main.c cimgui.c
SRC		+=	fractol.c
LIB_DEP		=	../../RT/lib/imgui_impl/libimgui_impl.a \
				../../RT/lib/cimgui/libcimgui.a
# **************************************************************************** #
include ../../RT/lib/libft/mk_c_project.mk
include ../../RT/lib/libft/mk_lib_dep.mk
# directories :
VPATH       :=	./srcs
# **************************************************************************** #
# Additionnal linkers :
# SDL
INC			+=	$(shell sdl2-config --cflags)
LIB_LINK	+=	$(shell sdl2-config --libs)
LIB_LINK	+=	-lstdc++
# **************************************************************************** #
# Target rules :
.DEFAULT_GOAL := all
all: $(NAME)  ## Built the project.
.PHONY: all

$(NAME): $(CIMGUI_NAME) $(OBJ) $(LIB_DEP)
	$(CC) $(CFLAGS) $(OBJ) -o $@ -static $(LIB_DEP)
	@printf "\033[1;34m$(NAME)\033[25G\033[32mBuilt $@ $(OKLOGO)\n"
-include $(DEP)

fclean : clean ## Clean the project.
	rm -f server
	rm -f client
	rm -f imgui.ini
	rm -f $(NAME)

server: srcs/server.c
	$(CC) $(CFLAGS) srcs/server.c -o $@ $(INC) $(LIB_LINK)
	@printf "\033[1;34m$(NAME)\033[25G\033[32mBuilt $@ $(OKLOGO)\n"
client: srcs/client.c
	$(CC) $(CFLAGS) srcs/client.c -o $@ $(INC) $(LIB_LINK)
	@printf "\033[1;34m$(NAME)\033[25G\033[32mBuilt $@ $(OKLOGO)\n"
