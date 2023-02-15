NAME	=	pipex

# MY LIBRARIES - libft.a and libftprintf.a
PRINTF_PATH =	./libft/
LIBFT_PATH =	./libft/libft/

PRINTF =		${PRINTF_PATH}libftprintf.a
LIBFT =			${LIBFT_PATH}libft.a

# INPUTS
SRC		=	srcs/pipex.c \
			srcs/identifier_path.c \
			srcs/utils.c \
			srcs/files.c \
			srcs/ft_fstrtrim.c \
			srcs/forking.c
	

HSRC	=	pipex.h
OBJS	=	${SRC:.c=.o}

# compilation
CC		=	cc -Wall -Wextra -Werror
CFLAGS	=	-g3

# clean
RM		=	rm -f

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I.

${PRINTF}:
			make -C ${PRINTF_PATH}

${LIBFT}:
			make -C ${LIBFT_PATH}
			make bonus -C ${LIBFT_PATH}
			
${NAME}:	${OBJS} ${HSRC} ${PRINTF}
			ar -rcs pipex.a ${OBJS}
			${CC} ${CFLAGS} ${SRC} pipex.a ${PRINTF} -o pipex

clean:
	rm -f ${OBJS}
	rm -f ./srcs/${OBJS}
	rm -f ./srcs/pipex.a
	make clean -C ./libft/
	

fclean:    clean
		rm -f pipex.a
		rm -f ${LIBFT}
		rm -f ${PRINTF}
		rm -f ${NAME}

re:		fclean all



.PHONY:    all clean fclean re