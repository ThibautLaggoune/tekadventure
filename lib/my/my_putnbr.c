/*
** my_put_nbr.c for my_put_nbr in /home/XIII/delivery/CPool_Day03
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu>
** 
** Started on  Wed Oct  5 22:32:22 2016 Corentin LEROY
** Last update Thu Apr  6 10:50:10 2017 Corentin LEROY
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      if (nb == -2147483648)
	{
	  my_putchar('2');
	  nb += 2000000000;
	}
      nb *= -1;
    }
  if (nb >= 10)
    my_put_nbr(nb / 10);
  my_putchar('0' + nb % 10);
}
