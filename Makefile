#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skunne <skunne@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 14:44:40 by skunne            #+#    #+#              #
#    Updated: 2014/02/11 16:22:36 by avannest         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libmlt.a

CC = gcc

SRC = mlt_util.c mlt_signal.c mlt_loop.c mlt_put.c mlt_init.c \
	  mlt_image.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -c -Wall -Wextra -Werror $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

