#Colours
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
WHITE=\033[1;37m
END=\033[0m


#Folder and Names

NAME = libft.a
SRCDIR = src
OBJDIR = obj
INCLUDES = inc

SRCS = ft_split.c \
	   ft_strjoin.c \
	   ft_strlen.c \
	   ft_strncmp.c \
	   ft_freesplit.c \
	   ft_atoi.c

#Compiler Options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(RED)Linking $@"
	@ar rc $(NAME) $(OBJS)
	@echo "$(GREEN)Done!$(END)"

#Define a pattern rule that compiles every .c file into a .o file 

$(OBJS): $(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	@echo "$(GREEN)Compiling $<$(END)"
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@
	@echo "$(WHITE)Created $@$(END)"
clean:
	@echo "$(WHITE)Clean objects$(END)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(WHITE)Clean binary$(END)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
