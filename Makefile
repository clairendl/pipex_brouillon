# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 16:09:50 by cnicolas          #+#    #+#              #
#    Updated: 2021/09/15 16:04:13 by cnicolas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a

SRC = 

OBJ = $(SRC:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
    ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) ${CFLAGS} $(OBJ) -o $(NAME) 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:all clean fclean re
