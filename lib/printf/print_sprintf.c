/*
** sprintf.c for my sprintf in /home/leroyc/Delivery/PSU/
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Fri Nov 25 01:39:11 2016 Corentin LEROY
** Last update Fri Mar 24 14:01:22 2017 Corentin LEROY
*/

#include <stdlib.h>
#include <stdarg.h>
#include "print.h"

char		*my_sprintf(char *str, ...)
{
  va_list	args;
  char		*buff;
  char		**parsone;
  int		size;

  parsone = printf_towordtab(str);
  va_start(args, str);
  size = pre_buff(args, str, parsone);
  va_end(args);
  buff = print_buffered(str, parsone, size);
  return (buff);
}

int		my_eprintf(char *str, ...)
{
  va_list	args;
  char		*buff;
  char		**parsone;
  int		size;

  parsone = printf_towordtab(str);
  va_start(args, str);
  size = pre_buff(args, str, parsone);
  va_end(args);
  buff = print_buffered(str, parsone, size);
  print_infd(2, buff, size);
  free(buff);
  return (size);
}

int		my_dprintf(int fd, char *str, ...)
{
  va_list	args;
  char		*buff;
  char		**parsone;
  int		size;

  parsone = printf_towordtab(str);
  va_start(args, str);
  size = pre_buff(args, str, parsone);
  va_end(args);
  buff = print_buffered(str, parsone, size);
  if (print_infd(fd, buff, size) == -1)
    size = -1;
  free(buff);
  return (size);
}
