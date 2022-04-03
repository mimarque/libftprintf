# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/28 18:26:42 by mimarque          #+#    #+#              #
#    Updated: 2022/04/04 00:16:13 by mimarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES=	ft_atoi.c		\
			ft_bzero.c		\
			ft_calloc.c		\
			ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_itoa.c		\
			ft_memccpy.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_memcpy.c		\
			ft_memmove.c	\
			ft_memset.c		\
			ft_putchar_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_putstr_fd.c	\
			ft_split.c		\
			ft_strchr.c		\
			ft_strdup.c		\
			ft_striteri.c	\
			ft_strjoin.c	\
			ft_strlcat.c	\
			ft_strlcpy.c	\
			ft_strlen.c		\
			ft_strmapi.c	\
			ft_strncmp.c	\
			ft_strnstr.c	\
			ft_strpbrk.c	\
			ft_strrchr.c	\
			ft_strtrim.c	\
			ft_substr.c		\
			ft_substrpbrk.c	\
			ft_tolower.c	\
			ft_toupper.c	

BONUS_FILES=ft_lstadd_back.c	\
			ft_lstadd_front.c	\
			ft_lstclear.c		\
			ft_lstdelone.c		\
			ft_lstiter.c		\
			ft_lstlast.c		\
			ft_lstmap.c			\
			ft_lstnew.c			\
			ft_lstsize.c		

NAME=libft.a

LIBSO=libft.so

CC=gcc

CFLAGS=-Wall -Wextra -Werror

BONUS_DIR=bonus/

OBJ_DIR=obj/

HDR_NAME=libft.h

BONUS_HDR=_bonus.h

SRC_PATH=$(addprefix $(SRC_DIR), $(SRC_FILES))

BONUS_PATH=$(addprefix $(BONUS_DIR), $(BONUS_FILES))

SRC_NAMES=${SRC_FILES:.c=.o}

BONUS_NAMES=${BONUS_FILES:.c=.o}

SRC_NAMES_O=$(addprefix $(OBJ_DIR), $(SRC_NAMES))

BONUS_NAMES_O=$(addprefix $(OBJ_DIR), $(BONUS_NAMES))

HDR= $(addprefix $(HDR_DIR),$(HDR_NAME))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(SRC_NAMES) $(BONUS_NAMES)
	ar -rc $@ $(SRC_NAMES_O)
	ranlib $@

$(OBJ_DIR):
	mkdir $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)$@ 

bonus: $(OBJ_DIR) $(SRC_NAMES) $(BONUS_NAMES)
	ar -rc $(NAME) $(BONUS_NAMES_O)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ_DIR)

sclean: clean
	rm -rf $(NAME) $(LIBSO)

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC_FILES) $(BONUS_FILES)
	gcc -nostartfiles -shared -o libft.so $(SRC_FILES) $(BONUS_FILES)

.PHONY: all bonus clean sclean fclean re so
