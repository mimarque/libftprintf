SRC_FILES:=$(wildcard *.c)

NAME=libftprintf.a

LIBFT=libft/libft.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

OBJ_DIR=obj/

HDR=ft_printf.h

SRC_NAMES=$(patsubst %.c,%.o,$(SRC_FILES))

SRC_NAMES_O=$(addprefix $(OBJ_DIR), $(SRC_NAMES))

all: $(NAME)

$(NAME): $(LIBFT) $(SRC_NAMES_O) | $(OBJ_DIR) 
	cp libft/libft.a $@
	ar -rcs $@ $(SRC_NAMES_O)

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(LIBFT):
	make -C libft

all: $(NAME)

bonus: all

clean:
	rm -rf obj/
	make -C libft $@

fclean: clean
	rm -f libftprintf.a
	make -C libft $@

re: fclean all

.PHONY: all clean fclean re so