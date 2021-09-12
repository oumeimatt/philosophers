# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 11:35:34 by oel-yous          #+#    #+#              #
#    Updated: 2021/09/12 15:24:32 by oel-yous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = philo

SRCS =	main.c\
		tools.c\
		routine.c\
		

FLAGS = -g -Wall -Werror -Wextra -pthread 

all:		$(NAME)

$(NAME):	$(SRCS)
		@echo "Compiling..."
		@$(CC) $(FLAGS) -o $(NAME) $(SRCS)
		@echo "Done."

clean:
			@rm -rf *.o
			
fclean: clean
			@rm -rf $(NAME)

re:		fclean all

.PHONY : all clean fclean re