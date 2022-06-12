NAME		=	libvector.a
NAME_D		=	libvector_debug.a

CC			=	cc
CC_FLAGS	=	-Wall -Werror -Wextra
CC_FLAGS_D	=	-g
AR			=	ar
AR_FLAGS	=	rcs
AR_FLAGS_D	=	rc

SRCS		=	${addprefix srcs/,\
				empty.c erase.c get.c print.c push.c}
HEADER		=	includes/vector.h
OBJS		=	${SRCS:.c=.o}
OBJS_DEBUG	=	${SRCS:.c=_debug.o}
INCLUDES	=	-Iincludes
RM			=	rm -rf

.PHONY		:	all clean fclean re debug

%.o			:	%.c $(HEADER)
				@$(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

%_debug.o	:	%.c $(HEADER)
				@$(CC) $(CC_DFLAGS) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

all			:	$(NAME)
debug		:	$(NAME_D)

$(NAME)		:	$(OBJS)
				@$(AR) $(AR_FLAGS) $(NAME) $?

$(NAME_D)	:	$(OBJS_D)
				@$(AR) $(AR_FLAGS) $(NAME_D) $?

clean		:
				@$(RM) $(OBJS) $(OBJS_D)

fclean		:	clean
				@$(RM) $(NAME) $(NAME_D)

re			:	fclean all