# COLORS #

# This is a minimal set of ANSI/VT100 color codes
_END		=	\x1b[0m
_BOLD		=	\x1b[1m
_UNDER		=	\x1b[4m
_REV		=	\x1b[7m

# Colors
_GREY		=	\x1b[30m
_RED		=	\x1b[31m
_GREEN		=	\x1b[32m
_YELLOW		=	\x1b[33m
_BLUE		=	\x1b[34m
_PURPLE		=	\x1b[35m
_CYAN		=	\x1b[36m
_WHITE		=	\x1b[37m

## VARIABLES ##

# COMPILATION #

NA_FLAGS	=	-f macho64

#CC_FLAGS	=	-Wall -Wextra -Werror

RM			=	rm -rf


# DIRECTORIES #

DIR_HEADERS =	./includes/

SRC_DIR		=	./srcs/


# FILES #

SRC_FILES	=	ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s ft_read.s ft_strdup.s

SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))

MAIN_SRC	=	main.c


# COMPILED_SOURCES #

NAME		=	libasm.a

OBJS		=	${SRCS:%.s=%.o}

MAIN_OBJ	=	${MAIN_SRC:%.c=%.o}

# EXECUTABLE #

EXEC		=	test

## RULES ##

%.o:			%.s ./includes/libasm.h
	nasm $(NA_FLAGS) -s $< -o $@ -I ${DIR_HEADERS}

%.o:			%.c ./includes/libasm.h
	gcc ${CC_FLAGS} -I ${DIR_HEADERS} -c $< -o $@

${NAME}:		${OBJS}
	@echo "$(_GREEN) All files compiled. $(_END)✅"
	ar rcs ${NAME} $?
	ranlib ${NAME}
	@echo "$(_GREEN) Library '$(NAME)' compiled. $(_END)✅"

${EXEC}:		${NAME} ${MAIN_OBJ}
	@touch empty_file
	@gcc $(CC_FLAGS) -I $(DIR_HEADERS) $(NAME) $(MAIN_OBJ) -o $(EXEC)
				@echo "$(_GREEN) Executable '$(EXEC)' created. $(_END)✅"

# OBLIGATORY PART #

all:			${NAME}

clean:			
	@$(RM) $(DIR_OBJS)
				@$(RM) $(MAIN_OBJ)
				@$(RM) $(OBJS)
				@$(RM) empty_file
				@echo "$(_RED)"$(OBJS)" and "$(MAIN_OBJ)" has been deleted. $(_END)"

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) $(EXEC)
				@echo "$(_RED)"$(NAME)" has been deleted. $(_END)🗑️"

re:				fclean all

# PHONY #

.PHONY:			all, clean, fclean, re, bonus
