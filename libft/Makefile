# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 21:32:56 by bsamzun           #+#    #+#              #
#    Updated: 2024/11/17 13:32:57 by bsamzun          ###   LAUSANNE.ch        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_atoi.c ft_striteri.c\
		ft_strlcpy.c ft_strlcat.c \
		ft_bzero.c ft_memcpy.c ft_memchr.c ft_memmove.c ft_memcmp.c ft_memset.c \
		ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c

BSRC =	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c \
		ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c


OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

CFLAGS += -Wall -Werror -Wextra

NAME = libft.a

all:$(NAME)

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus:$(OBJ) $(BOBJ)
	ar rcs $(NAME) $(OBJ) $(BOBJ)

clean:
		rm -f $(OBJ) $(BOBJ) $(TOBJ)

fclean:clean
		rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re bonus
