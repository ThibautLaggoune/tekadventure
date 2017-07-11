/*
** formats.c for my formats in /home/leroyc/Delivery/PSU/
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Sat Nov 19 13:49:47 2016 Corentin LEROY
** Last update Sun Apr  2 12:59:12 2017 Corentin LEROY
*/

#include <stdlib.h>
#include "print.h"

char	*print_putsprecision(char *str, int precision)
{
  int	i;
  int	strsize;
  char	*ret;

  strsize = print_strlen(str);
  if (precision == -1)
    precision = 0;
  if (strsize <= precision)
    return (str);
  if ((ret = malloc(sizeof(char) * (precision + 1))) == NULL)
    return (0);
  print_memset(ret, '0', precision + 1);
  i = -1;
  while (ret[++i])
    ret[i] = str[i];
  free(str);
  return (ret);
}
