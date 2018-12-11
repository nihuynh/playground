NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_swap.c ft_sqrt.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c \
		ft_strdup.c ft_strlen.c ft_strcmp.c ft_strncmp.c ft_strstr.c ft_strnstr.c ft_strcpy.c \
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_toupper.c \
		ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
		ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
		ft_isw.c ft_strtrim.c ft_nbwords.c ft_nbchar.c ft_strsplit.c ft_pow.c ft_itoa.c ft_putchar.c \
		ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c

OBJS =	$(SRCS:.c=.o)

INCLUDES = ./

NUM := 0
RET := 0
_IGREEN=$'\x1b[42m
_GREEN=$'\x1b[32m
_END=$'\x1b[0m

all: header $(NAME) end_comp

header:
	@echo ""
	@echo "           ~~~~~~~~~~~~~~~~~~~~~~~~          ~~~~~~~~~~~~~~~~~~~~~~"
	@echo ">#####/* ##########################\ \ \/ / /######################## */#####<"
	@echo " >####/*                                                              */####<"
	@echo "  >###/*    =*=+*=+*=+*=+*     #######    ######     *+=*+=*+=*+=*=   */###<"
	@echo "  >###/*                      ###        ##                           */###<"
	@echo "  >###/*       =*=+*=+*=+*     ######    ##  ####    *+=*+=*+=*=      */###<"
	@echo "  >###/*                           ###   ##    ##                     */###<"
	@echo "  >###/*    =*=+*=+*=+*=+*    #######     ######     *+=*+=*+=*+=*=   */###<"
	@echo " >####/*                              ____                            */####<"
	@echo ">#####/* ##########################/ / /\ \ \######################## */#####<"
	@echo ""
	@printf %45s "~ libft.a ~"
	@echo ""
	@echo ""
	@printf "       "

end_comp:
	@echo ""
	@echo "                           $(_GREEN)~ Compilation effectuee ~$(_END)"
	@echo ""

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS) && ranlib $(NAME)

%.o: %.c $(INCLUDES)libft.h
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(INCLUDES)
	@$(eval NUM=$(shell echo $$(($(NUM)+1))))
	@$(eval RET=$(shell echo $$(($(NUM)%5))))
ifeq ($(RET),0)
	@printf "$(_IGREEN) $(_END)"
else
	@echo $(RET)
endif

clean:
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re