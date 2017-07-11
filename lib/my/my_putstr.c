/*
** my_putstr.c for my_putstr in /home/XIII/delivery/CPool_Day04
** 
** Made by Corentin LEROY
** Login   <XIII@epitech.net>
** 
** Started on  Thu Oct  6 16:09:09 2016 Corentin LEROY
** Last update Thu Apr  6 11:30:32 2017 Corentin LEROY
*/

#include <stdlib.h>
#include "my.h"

char    *my_strdup(char *src)
{
  char  *ret;
  int	i;

  if (src == NULL)
    return (NULL);
  if (!(ret = malloc(my_strlen(src) + 1)))
    return (NULL);
  i = -1;
  while (src[++i])
    ret[i] = src[i];
  ret[i] = 0;
  return (ret);
}

int	my_putstr(char *str)
{
  int	i;

  i = -1;
  if (str == NULL)
    return (-1);
  while (str[++i])
    my_putchar(str[i]);
  return (i);
}
