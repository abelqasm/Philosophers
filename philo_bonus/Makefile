SRCS = philo_bonus.c \
	./utils_bonus/ft_atoi.c \
	./utils_bonus/ft_fill_philo_bonus.c \
	./utils_bonus/ft_philo_utils_bonus.c \
	./utils_bonus/ft_philo_utils2_bonus.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Werror -Wextra -Wall -fsanitize=address
NAME = philo_bonus

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FTPRINTF) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all