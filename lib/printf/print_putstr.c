/*
** putstr.c for putstr in /home/XIII/delivery/CPool_Day04
** 
** Made by Corentin LEROY
** Login   <XIII@epitech.net>
** 
** Started on  Thu Oct  6 16:09:09 2016 Corentin LEROY
** Last update Fri Mar 24 14:01:05 2017 Corentin LEROY
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "print.h"

char    *print_strdup(char *src)
{
  char  *ret;
  int	i;

  if (!(ret = malloc(print_strlen(src) + 1)))
    return (NULL);
  i = -1;
  while (src[++i])
    ret[i] = src[i];
  ret[i] = 0;
  return (ret);
}

char	*print_putstr_prf(va_list arg, char *pars)
{
  char	*str;

  str = va_arg(arg, char *);
  if (str == NULL)
    return (print_strdup("(null)"));
  else  if (pars == 0 || arg == NULL)
    return (print_strdup(str));
  else
    return (print_strdup(str));
}

char	*print_puterr(va_list arg, char *pars)
{
  UNUSED(arg);
  return (pars);
}

int	print_infd(int fd, char *str, int size)
{
  int	ret;

  ret = write(fd, str, size);
  return (ret);
}
