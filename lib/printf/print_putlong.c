/*
** putlong.c for put long in /home/leroyc/Delivery/PSU/
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Fri Nov 18 16:49:30 2016 Corentin LEROY
** Last update Fri Mar 24 13:59:00 2017 Corentin LEROY
*/

#include <stdlib.h>
#include "print.h"

void	print_putlnbr_str(long long nb, char *dup, int i)
{
  if (nb < 0)
    {
      dup[0] = '-';
      nb *= -1;
    }
  if (nb >= 10)
    {
      print_putlnbr_str(nb / 10, dup, i - 1);
      dup[i] = '0' + nb % 10;
    }
  else
    dup[i] = nb + '0';
}

char		*print_putlnb_str(long long nb)
{
  long long	cpy;
  int		size;
  char		*dup;

  size = ((nb < 0) ? (2) : (1));
  cpy = ((nb < 0) ? (-nb) : (nb));
  while (cpy >= 10)
    {
      cpy /= 10;
      size++;
    }
  if ((dup = malloc(sizeof(char) * (size + 1))) == NULL)
    return (0);
  print_memset(dup, '0', size + 1);
  print_putlnbr_str(nb, dup, size - 1);
  return (dup);
}
