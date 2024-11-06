CC = cc
FLAGS = -Wall -Wextra -Werror -c
SRC = ${wildcard *.c}
OBJ = $(SRC:%.c=%.o)

.PHONY: all

all: libft.a

libft.a: $(OBJ)
	@ar rsc $@ $?

%.o: %.c
	@${CC} ${FLAGS} $^ -o $@

clean:
	rm *.o

fclean: clean
	rm libft.a

re: fclean libft.a


