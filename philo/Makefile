# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 16:58:11 by aribesni          #+#    #+#              #
#    Updated: 2022/01/05 16:58:13 by aribesni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		philo

SRC = 		actions.c init.c is_dead.c libft_utils.c \
			philo.c philo_utils.c threads.c

SRCS = 		$(addprefix ./srcs/, $(SRC))

CC = 		gcc

CFLAGS = 	-Wall -Wextra -Werror

INCLUDES = 	./includes/philo.h

OBJS = 		${SRCS:.c=.o}

${NAME} : 	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -I ${INCLUDES} -lpthread #-g -fsanitize=address

.c.o :
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all : 		${NAME}

clean :
			rm -rf ${OBJS}

fclean : 	clean
			rm -rf ${NAME}

re :		fclean all

PHONY: 		all clean fclean re