/*
** my_find_prime_sup.c for my_find_prime_sup in /home/XIII/delivery/CPool_Day05
** 
** Made by Corentin LEROY
** Login   <XIII@epitech.net>
** 
** Started on  Fri Oct  7 15:10:58 2016 Corentin LEROY
** Last update Thu Nov 17 23:03:06 2016 Corentin LEROY
*/

#include "my.h"

int	my_find_prime_sup(int nb)
{
  int	my_test;

  my_test = 0;
  if (nb <= 3)
    return (3);
  else if (nb > 2147483424)
    return (2147483647);
  else if (nb <= 5)
    return (5);
  else if (nb <= 7)
    return (7);
  else
    {
      while (my_test == 0)
	{
	  my_test = my_is_prime(nb);
	  if (my_test == 0)
	    nb = nb + 1;
	}
    }
  return (nb);
}
