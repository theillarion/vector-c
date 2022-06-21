NAME		=	libvector.a
NAME_D		=	libvector_debug.a

CC			=	cc
CC_FLAGS	=	-Wall -Werror -Wextra
CC_FLAGS_D	=	-g
AR			=	ar
AR_FLAGS	=	rcs
AR_FLAGS_D	=	rc

SRCS		=	$(addprefix srcs/,\
				empty.c erase.c get.c push.c init.c reserve.c utilities.c resize.c)
HEADER		=	$(addprefix includes/,\
				vector.h utilities.h)
OBJS		=	$(SRCS:.c=.o)
OBJS_DEBUG	=	$(SRCS:.c=_debug.o)
INCLUDES	=	-Iincludes
RM			=	rm -rf

OS				=	$(shell uname -s)

NOCOLOR			=	\033[0m
COLOR_LGREEN	=	\033[92m
COLOR_LYELLOW	=	\033[93m
COLOR_LCYAN		=	\033[96m
NEWLINE			=	\n

.PHONY		:	all clean fclean re debug

%.o			:	%.c $(HEADER)
				@$(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@
				@printf "$(COLOR_LCYAN)build object$(NOCOLOR) [$(COLOR_LGREEN)info$(NOCOLOR)]: "
				@printf "ready $(COLOR_LYELLOW)$@$(NOCOLOR)$(NEWLINE)"

%_debug.o	:	%.c $(HEADER)
				@$(CC) $(CC_DFLAGS) $(CC_FLAGS) $(INCLUDES) -c $< -o $@
				@printf "$(COLOR_LCYAN)build object$(NOCOLOR) [$(COLOR_LGREEN)info$(NOCOLOR)]: "
				@printf "ready $(COLOR_LYELLOW)$@$(NOCOLOR)$(NEWLINE)"

all			:	$(NAME)
debug		:	$(NAME_D)

$(NAME)		:	$(OBJS)
				@$(AR) $(AR_FLAGS) $(NAME) $?
				@printf "$(COLOR_LCYAN)ar$(NOCOLOR) [$(COLOR_LGREEN)info$(NOCOLOR)]: "
				@printf "ready $(COLOR_LYELLOW)$(NAME)$(NOCOLOR) for $(COLOR_LYELLOW)$(OS)$(NOCOLOR)$(NEWLINE)"

$(NAME_D)	:	$(OBJS_D)
				@$(AR) $(AR_FLAGS) $(NAME_D) $?
				@printf "$(COLOR_LCYAN)ar debug$(NOCOLOR) [$(COLOR_LGREEN)info$(NOCOLOR)]: "
				@printf "ready $(COLOR_LYELLOW)$(NAME_D)$(NOCOLOR) for $(COLOR_LYELLOW)$(OS)$(NOCOLOR)$(NEWLINE)"

clean		:
				@$(RM) $(OBJS) $(OBJS_D)
				@printf "$(COLOR_LCYAN)$@$(NOCOLOR) [$(COLOR_LGREEN)info$(NOCOLOR)]: "
				@printf "ready $(COLOR_LYELLOW)$(NAME)$(NOCOLOR) for $(COLOR_LYELLOW)$(OS)$(NOCOLOR)$(NEWLINE)"

fclean		:	clean
				@$(RM) $(NAME) $(NAME_D)
				@printf "$(COLOR_LCYAN)$@$(NOCOLOR) [$(COLOR_LGREEN)info$(NOCOLOR)]: "
				@printf "ready $(COLOR_LYELLOW)$(NAME)$(NOCOLOR) for $(COLOR_LYELLOW)$(OS)$(NOCOLOR)$(NEWLINE)"

re			:	fclean all
				@printf "$(COLOR_LCYAN)$@$(NOCOLOR) [$(COLOR_LGREEN)info$(NOCOLOR)]: "
				@printf "ready $(COLOR_LYELLOW)$(NAME)$(NOCOLOR) for $(COLOR_LYELLOW)$(OS)$(NOCOLOR)$(NEWLINE)"
