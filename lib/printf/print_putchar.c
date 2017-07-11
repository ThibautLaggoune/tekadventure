/*
** putchar.c for putchar in /home/XIII/delivery/CPool_Day07
** 
** Made by Corentin LEROY
** Login   <XIII@epitech.net>
** 
** Started on  Tue Oct 11 10:33:31 2016 Corentin LEROY
** Last update Fri Mar 24 13:51:27 2017 Corentin LEROY
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

char	*print_putchar_str(va_list arg, char *pars)
{
  char	*ret;
  char	c;

  c = va_arg(arg, int);
  if ((ret = malloc(2)) == NULL)
    return (NULL);
  ret[0] = c;
  ret[1] = '\0';
  if (pars == 0)
    return (ret);
  return (ret);
}

char	*print_putchar_mod(va_list arg, char *pars)
{
  char	*ret;

  if ((ret = malloc(2)) == NULL)
    return (NULL);
  ret[0] = '%';
  ret[1] = '\0';
  if (pars == 0 || arg == NULL)
    return (ret);
  return (ret);
}
