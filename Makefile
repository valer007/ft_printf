NAME = libftprintf.a
CC = cc
CFlAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRC = ft_strlen.c hex.c ft_printf.c usd.c ft_putnbr.c

OBJ = $(SRC:.c=.o)
	
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
