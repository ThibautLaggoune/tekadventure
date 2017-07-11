/*
** put_nbr.c for put_nbr in /home/XIII/delivery/CPool_Day03
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu>
** 
** Started on  Wed Oct  5 22:32:22 2016 Corentin LEROY
** Last update Fri Mar 24 14:00:44 2017 Corentin LEROY
*/

#include <stdarg.h>
#include <stdlib.h>
#include "print.h"

void			print_putnbr_str(int nb, char *dup, int i)
{
  if (nb < 0)
    {
      dup[0] = '-';
      if (nb == -2147483648)
	{
	  dup[1] = '2';
	  nb += 2000000000;
	}
      nb *= -1;
    }
  if (nb >= 10)
    {
      print_putnbr_str(nb / 10, dup, i - 1);
      dup[i] = '0' + nb % 10;
    }
  else
    dup[i] = nb + '0';
}

char		*print_putnb_str(va_list arg, char *pars)
{
  int		cpy;
  int		size;
  char		*dup;
  long long	nb;

  nb = va_arg(arg, long long);
  if (nb < -2147483648 || nb > 2147483647)
    print_putlnb_str(nb);
  nb = (int) nb;
  size = ((nb < 0) ? (2) : (1));
  cpy = ((nb < 0) ? (-nb) : (nb));
  cpy = ((nb == -2147483648) ? (2147483647) : (cpy));
  while (cpy >= 10)
    {
      cpy /= 10;
      size++;
    }
  if ((dup = malloc(sizeof(char) * (size + 1))) == NULL)
    return (0);
  print_memset(dup, '0', size + 1);
  print_putnbr_str(nb, dup, size - 1);
  if (pars == 0)
    return (dup);
  return (dup);
}

void	print_putdec_str(unsigned long long nb, char *dup, int i)
{
  if (nb >= 10)
    {
      print_putnbr_str(nb / 10, dup, i - 1);
      dup[i] = '0' + nb % 10;
    }
  else
    dup[i] = nb + '0';
}

char			*print_putnbr_dec(va_list arg, char *pars)
{
  unsigned long long	cpy;
  unsigned long long	nb;
  int			size;
  char			*dup;

  nb = va_arg(arg, unsigned long long);
  size = 1;
  cpy = nb;
  while (cpy >= 10)
    {
      cpy /= 10;
      size++;
    }
  if ((dup = malloc(sizeof(char) * (size + 1))) == NULL)
    return (0);
  print_memset(dup, '0', size + 1);
  print_putdec_str(nb, dup, size - 1);
  if (pars == 0)
    return (dup);
  return (dup);
}
