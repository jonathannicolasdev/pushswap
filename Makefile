### COMPILATION ###
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -g

### EXECUTABLE ###
NAME	= pushswap

### DIRECTORIES ###
INCLUDES		= inc
LIBFT			= libft
SRCDIR			= src
OBJDIR			= obj


### SOURCE FILES ###
SRCS = main.c utils.c push.c swap.c rotate.c reverse_rotate.c \
	   sortage.c ft_sort_more_than_three.c minmaxmid.c \
	   ft_sort_more_than_three_v2.c sort_two.c

### OBJECTS ###
SRC	= $(addprefix $(SRCDIR)/,$(SRCS))
OBJ	= $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

### COLORS ###
NOC		= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m

### RULES ###

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)libft..$(NOC)"
	@make -sC $(LIBFT)
	@$(CC) $(FLAGS) -L $(LIBFT) -o $@ $^ -lft
	@echo "$(GREEN)$@$(NOC)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDES)/$(NAME).h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I$(INCLUDES) -c -o $@ $<
	@echo "$(BLUE)gcc $(WHITE)$@$(NOC)"

clean:
	@echo "$(RED)clean$(NOC)"
	@make clean -sC $(LIBFT)
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)fclean$(NOC)"
	@make fclean -sC $(LIBFT)
	@rm -f $(NAME)

re: fclean all
.PHONY:	all clean fclean re
