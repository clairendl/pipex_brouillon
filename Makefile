# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnicolas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 16:09:50 by cnicolas          #+#    #+#              #
#    Updated: 2021/09/02 07:22:22 by cnicolas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a

SRC = 

OBJ = $(SRC:.c=.o)

bonus = 

bonus_OBJ = $(bonus:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(bonus_OBJ)
	ar rcs $(NAME) $(bonus_OBJ)

clean:
	$(RM) $(OBJ) $(bonus_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:all clean fclean re bonus
