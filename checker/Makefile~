NAME = checker

SRCS_NAME = main.c \
	    apply.c \
	    check_par.c \
	    ft_use.c \
	    cmd.c \
	    list.c \
	    error.c

SRCS_PATH = srcs/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

INC = include/checker.h

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS_PATH = objs/

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

CC = gcc

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS_PATH) $(OBJS) $(SRCS)
	$(CC) $(FLAG) -o $(NAME) $(OBJS)

$(OBJS_PATH) :
	mkdir $(OBJS_PATH)

$(OBJS) : $(SRCS) $(OBJS_PATH)
	$(CC) $(FLAG) -c $(SRCS)
	mv $(OBJS_NAME) $(OBJS_PATH)

clean :
	rm -rf $(OBJS) $(OBJS_PATH)
	rm -rf */*~
fclean : clean
	rm -rf $(NAME)

re : fclean all

