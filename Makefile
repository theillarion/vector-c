NAME		=	vector
CC			=	gcc
CC_FLAGS	=	-Wall -Werror -Wextra
CC_DFLAGS	=	-g
SRCS		=	${wildcard srcs/*c}
OBJS		=	${SRCS:.c=.o}
INCLUDES	=	-Iincludes
RM			=	rm -rf


.c.o		:	
				${CC} ${CC_FLAGS} ${INCLUDES} -c $< -o ${$<:.c=.o}

all			:	${NAME}

${NAME}		:	${OBJS}
				${CC} ${CC_FLAGS} ${INCLUDES} ${OBJS} -o ${NAME}

clean		:
				${RM} ${NAME}

fclean		:	clean
				${RM} ${OBJS}

re			:	fclean all

.PHONY		: all clean fclean re