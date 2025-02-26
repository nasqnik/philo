CC			= cc
CFLAGS		= -Wall -Werror -Wextra
RM 			= rm -rf

NAME		= philo
HEADER		= philo.h

SRC			= main.c utils.c init.c

OBJ			= $(SRC:%.c=%.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:		%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all	clean fclean re



