
INC			=	$(shell sdl2-config --cflags)
INC			+=	-I../../../RT/lib/libft/includes

LIB_LINK	=	$(shell sdl2-config --libs)
LIB_DEP		=	-L ../../../RT/lib/libft -lft


all:
	gcc -c main.c -o main.o $(INC)
	gcc main.o $(INC) $(LIB_LINK) $(LIB_DEP)
	./a.out