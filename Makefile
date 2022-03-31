SRC_FILES:=$(wildcard *.c)

NAME=libftprintf.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

OBJ_DIR=obj

HDR=ft_printf.h

SRC_NAMES=$(patsubst %.c,%.o,$(SRC_FILES))

SRC_NAMES_O=$(addprefix $(OBJ_DIR)/, $(SRC_NAMES))

$(OBJ_DIR):
	mkdir $@

%.o: %.c $(HDR) $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@ 

$(NAME): $(OBJ_DIR) $(SRC_NAMES)
	ar -rc $@ $(SRC_NAMES_O)
	ranlib $@

all: $(NAME)

bonus: all

clean:
	rm -rf obj/

sclean: clean

fclean: clean

re: sclean all

.PHONY: all clean fclean re so
