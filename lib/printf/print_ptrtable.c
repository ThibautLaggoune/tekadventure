/*
** ptrtable.c for ptrtable in /home/leroyc/Delivery/PSU/
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Thu Nov 17 17:28:13 2016 Corentin LEROY
** Last update Fri Mar 24 13:50:27 2017 Corentin LEROY
*/

#include <stdarg.h>
#include <stdlib.h>
#include "print.h"

void    print_putstr_base(unsigned long long nb, char *base, char *dup,
			  int i)
{
  int	basesize;

  basesize = print_strlen(base);
  if (nb >= (basesize >= 0 ? (unsigned int)basesize : 0))
    {
      print_putstr_base(nb / basesize, base, dup, i - 1);
      dup[i] = base[nb % basesize];
    }
  else
    dup[i] = base[nb];
}

char	*print_putoct_str(char *str, char *dup)
{
  int	i;
  int	j;
  int	k;
  char	nb[5];

  print_memset(nb, '0', 5);
  nb[0] = '\\';
  i = 0;
  j = 0;
  while (str[i])
    {
      if (' ' <= str[i] && str[i] <= '~')
	dup[j++] = str[i++];
      else
	{
	  print_putstr_base(str[i++], "01234567", nb, 3);
	  k = 0;
	  while (nb[k])
	    dup[j++] = nb[k++];
	}
    }
  return (dup);
}

char	*print_putstr_oct(va_list arg, char *pars)
{
  int	nbnonprin;
  int	size;
  int	i;
  char	*dup;
  char	*str;

  str = va_arg(arg, char *);
  if (str == NULL)
    return ("(null)");
  nbnonprin = 0;
  UNUSED(pars);
  i = 1;
  size = print_strlen(str);
  while (str[++i])
    nbnonprin += ((str[i] < 32 || 126 < str[i]) ? (1) : (0));
  size += (nbnonprin * 3);
  if ((dup = malloc(sizeof(char) * (size + 1))) == NULL)
    return (0);
  print_memset(dup, '0', size + 1);
  return (print_putoct_str(str, dup));
}

void	get_ftab(char *(*ftab[13])(va_list, char *))
{
  ftab[0] = &print_putnb_str;
  ftab[1] = &print_putnb_str;
  ftab[2] = &print_putchar_str;
  ftab[3] = &print_putstr_prf;
  ftab[4] = &print_putstr_oct;
  ftab[5] = &print_putnbr_oct;
  ftab[6] = &print_putnbr_dec;
  ftab[7] = &print_putnbr_hex;
  ftab[8] = &print_putnbr_HEX;
  ftab[9] = &print_putchar_mod;
  ftab[10] = &print_putstr_ptr;
  ftab[11] = &print_putnbr_bin;
  ftab[12] = &print_puterr;
}
