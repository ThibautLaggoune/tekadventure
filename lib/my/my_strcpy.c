/*
** my_strcpy.c for my_strcpy in /home/XIII/delivery/CPool_Day06
** 
** Made by Corentin LEROY
** Login   <XIII@epitech.net>
** 
** Started on  Mon Oct 10 09:10:49 2016 Corentin LEROY
** Last update Thu Apr  6 11:39:29 2017 Corentin LEROY
*/

#include "my.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = -1;
  if (src == NULL)
    return (NULL);
  while (src[++i])
      dest[i] = src[i];
  dest[i] = 0;
  return (dest);
}
