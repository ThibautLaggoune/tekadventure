/*
** putbase.c for putbase in /home/leroyc/Delivery/PSU/
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Thu Nov 17 14:50:32 2016 Corentin LEROY
** Last update Sun Nov 20 14:02:24 2016 Corentin LEROY
*/

#include <stdarg.h>
#include <stdlib.h>
#include "print.h"

char			*print_putnbr_HEX(va_list arg, char *pars)
{
  unsigned long	long	cpy;
  unsigned long	long	nb;
  int			size;
  char			*dup;

  UNUSED(pars);
  nb = va_arg(arg, unsigned long long);
  size = 1;
  cpy = nb;
  while (cpy >= 16)
    {
      cpy /= 16;
      size++;
    }
  if ((dup = malloc(sizeof(char) * (size + 1))) == NULL)
    return (0);
  print_memset(dup, '0', size + 1);
  print_putstr_base(nb, "0123456789ABCDEF", dup, size - 1);
  return (dup);
}

char			*print_putnbr_hex(va_list arg, char *pars)
{
  unsigned long	long	cpy;
  unsigned long	long	nb;
  int			size;
  char			*dup;

  nb = va_arg(arg, unsigned long long);
  UNUSED(pars);
  size = 1;
  cpy = nb;
  while (cpy >= 16)
    {
      cpy /= 16;
      size++;
    }
  if ((dup = malloc(sizeof(char) * (size + 1))) == NULL)
    return (0);
  print_memset(dup, '0', size + 1);
  print_putstr_base(nb, "0123456789abcdef", dup, size - 1);
  return (dup);
}

char			*print_putstr_ptr(va_list arg, char *pars)
{
  unsigned long	long	cpy;
  unsigned long	long	nb;
  int			size;
  char			*dup;

  nb = va_arg(arg, unsigned long long);
  UNUSED(pars);
  size = 3;
  cpy = nb;
  while (cpy >= 16)
    {
      cpy /= 16;
      size++;
    }
  if ((dup = malloc(sizeof(char) * (size + 1))) == NULL)
    return (0);
  print_memset(dup, '0', size + 1);
  dup[1] = 'x';
 print_putstr_base(nb, "0123456789abcdef", dup, size - 1);
  return (dup);
}

char			*print_putnbr_bin(va_list arg, char *pars)
{
  unsigned long	long	cpy;
  unsigned long	long	nb;
  int			size;
  char			*dup;

  nb = va_arg(arg, unsigned long long);
  UNUSED(pars);
  size = 1;
  cpy = nb;
  while (cpy >= 2)
    {
      cpy /= 2;
      size++;
    }
  if ((dup = malloc(sizeof(char) * (size + 1))) == NULL)
    return (0);
  print_memset(dup, '0', size + 1);
  print_putstr_base(nb, "01", dup, size - 1);
  return (dup);
}

char			*print_putnbr_oct(va_list arg, char *pars)
{
  unsigned long	long	cpy;
  unsigned long	long	nb;
  int			size;
  char			*dup;

  nb = va_arg(arg, unsigned long long);
  UNUSED(pars);
  size = 1;
  cpy = nb;
  while (cpy >= 8)
    {
      cpy /= 8;
      size++;
    }
  if ((dup = malloc(sizeof(char) * (size + 1))) == NULL)
    return (0);
  print_memset(dup, '0', size + 1);
  print_putstr_base(nb, "01234567", dup, size - 1);
  return (dup);
}
