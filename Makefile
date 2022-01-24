NAME		=	vector
NAME_DEBUG	=	vector_debug
CC			=	gcc
CC_FLAGS	=	-Wall -Werror -Wextra
CC_DFLAGS	=	-g
SRCS		=	${wildcard srcs/*.c}
OBJS		=	${SRCS:.c=.o}
OBJS_DEBUG	=	${SRCS:.c=_debug.o}
INCLUDES	=	-Iincludes
RM			=	rm -rf

%.o				:	%.c
					${CC} ${CC_FLAGS} ${INCLUDES} -c $< -o $@

%_debug.o		:	%.c
					${CC} ${CC_DFLAGS} ${CC_FLAGS} ${INCLUDES} -c $< -o $@

all				:	${NAME}

${NAME}			:	${OBJS}
					${CC} ${CC_FLAGS} ${INCLUDES} $^ -o ${NAME}

debug			:	${NAME_DEBUG}

${NAME_DEBUG}	:	${OBJS_DEBUG}
					${CC} ${CC_FLAGS} ${INCLUDES} $^ -o ${NAME_DEBUG}

clean		:
				${RM} ${NAME} ${NAME_DEBUG}

fclean		:	clean
				${RM} ${OBJS} ${OBJS_DEBUG}

re			:	fclean all

.PHONY		: all clean fclean re debug