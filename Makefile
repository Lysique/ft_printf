NAME = libftprintf.a
FILES = ft_printf_x_X ft_printf_p ft_printf_c_s ft_printf_d_u_i ft_printf ft_printf_init ft_printf_utils
OBJS = $(SRCS:.c=.o)
SRCS_DIR = ./
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
all: $(NAME)
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
bonus: $(NAME)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re bonus
