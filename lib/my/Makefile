##
## Makefile for Makefile in /home/XIII/delivery/CPool_Day10
## 
## Made by Corentin LEROY
## Login   <XIII@epitech.net>
## 
## Started on  Fri Oct 14 09:43:58 2016 Corentin LEROY
## Last update Wed Apr 12 23:22:22 2017 Corentin LEROY
##

RM	=	rm -f

NAME	=	libmy.a

H_NAME	=	my.h

SRCS	=	get_next_line.c		\
		my_filelenght.c		\
		my_disptab.c		\
		my_tabcpy.c		\
		my_find_prime_sup.c	\
		my_free_tab.c 		\
		my_getnbr.c 		\
		my_is_prime.c		\
		my_memset.c		\
		my_power_rec.c		\
		my_putnbr.c		\
		my_putchar.c		\
		my_putstr.c		\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c		\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_square_root.c	\
		my_strcmp.c		\
		my_strcpy.c		\
		my_strcmp.c		\
		my_strlen.c		\
		my_strlowcase.c		\
		my_strstr.c		\
		my_strupcase.c		\
		my_swap.c		\
		tab_str_wt.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-I . -W -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc ../$(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) ../$(NAME)

re:	fclean all
