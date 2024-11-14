SRCS	= 	src/libftprintf.c

SRCS_B	=	$(SRCS) 

OBJS	= $(SRCS:.c=.o)

OBJS_B	= $(SRCS_B:.c=.o)

INCS	= inc

NAME	= libftprintf.a

LIBC	= ar rc

LIBR	= ranlib

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

%c:%o
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)
	$(LIBR) $(NAME)

bonus:	$(OBJS_B)
	$(LIBC) $(NAME) $(OBJS_B)
	$(LIBR) $(NAME)

all: bonus

clean:
	$(RM) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all