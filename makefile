CC = @cc
CFLAGS = -Wall -Wextra -Werror
SRC = ${wildcard *.c}
OBJ = $(SRC:%.c=%.o)
NAME = libft.a 

.PHONY: all

all: $(NAME)

$(NAME): $(OBJ)
	@ar rsc $@ $?

clean:
	@$(RM) *.o

fclean: clean
	@$(RM) libft.a

re: fclean $(NAME)
