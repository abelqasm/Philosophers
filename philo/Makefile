SRCS = philo.c \
	./utils/ft_atoi.c \
	./utils/ft_fill_philo.c \
	./utils/ft_philo_utils.c \
	./utils/ft_philo_utils2.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Werror -Wextra -Wall -fsanitize=address
NAME = philo

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FTPRINTF) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all