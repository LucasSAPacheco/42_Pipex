SRCS    = ft_printf.c srcs/picked_char.c srcs/picked_str.c srcs/picked_ito_up_hex.c \
		srcs/picked_ito_low_hex.c srcs/picked_i_or_d.c srcs/picked_u.c \
		srcs/picked_pointer.c


OBJS    = $(SRCS:.c=.o)

NAME    = libftprintf.a

CC 		= cc

CFLAGS    +=    -Wall -Werror -Wextra

all: ${NAME}
    
${NAME}: ${OBJS}
		make -C ./libft
		mv ./libft/libft.a ./${NAME}
		ar rcs $@ ${OBJS}

clean:
		rm -f ${OBJS}
		make clean -C ./libft/
		rm -f .srcs/${OBJS}

fclean:    clean
		rm -f ${NAME}

re:		fclean all



.PHONY:    all clean fclean re