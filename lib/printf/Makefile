##
## Makefile for Makefile in /home/XIII/delivery/CPool_Day10
## 
## Made by Corentin LEROY
## Login   <XIII@epitech.net>
## 
## Started on  Fri Oct 14 09:43:58 2016 Corentin LEROY
## Last update Thu Apr  6 17:52:14 2017 Corentin LEROY
##

RM	=	rm -f

NAME	=	libprintf.a

H_NAME	=	print.h

SRCS	=	print_free_tab.c 	\
		print_getnbr.c 		\
		print_memset.c		\
		print_putchar.c		\
		print_put_nbr.c		\
		print_putstr.c		\
		print_strlen.c		\
		print_get_arg.c		\
		print_get_args.c	\
		print_format.c		\
		print_formats.c		\
		print_main.c		\
		print_ptrtable.c	\
		print_putbase.c		\
		print_putlong.c		\
		print_sprintf.c		\
		print_t_args.c		\
		print_towordtab.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+= -W -Wall -Wextra -Werror

$(NAME):	$(OBJS)
	ar rc ../$(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
