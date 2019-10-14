
INC			=	$(shell sdl2-config --cflags)
INC			+=	-I../../../RT/lib/libft/includes

LIB_LINK	=	$(shell sdl2-config --libs)
LIB_DEP		=	../../../RT/lib/libft/libft.a


all:
	gcc main.c $(INC) $(LIB_LINK) $(LIB_DEP)
	./a.out