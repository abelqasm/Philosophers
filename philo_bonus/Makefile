SRCS = philo_bonus.c \
	./utils_bonus/ft_atoi.c \
	./utils_bonus/ft_fill_philo_bonus.c \
	./utils_bonus/ft_philo_utils_bonus.c \
	./utils_bonus/ft_philo_utils2_bonus.c

OBJS = $(SRCS:.c=.o)

CC = cc
# CFLAGS = -Werror -Wextra -Wall -fsanitize=address
BONUS = philo_bonus

all : $(BONUS)

$(BONUS) : $(OBJS)
	$(CC) $(OBJS) $(FTPRINTF) -o $(BONUS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(BONUS)

re : fclean all