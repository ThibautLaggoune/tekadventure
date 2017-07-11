/*
** my_strupcase.c for my_strupcase in /home/XIII/delivery/CPool_Day06
** 
** Made by Corentin LEROY
** Login   <XIII@epitech.net>
** 
** Started on  Mon Oct 10 21:32:46 2016 Corentin LEROY
** Last update Thu Apr  6 11:46:47 2017 Corentin LEROY
*/

#include "my.h"

char	*my_strupcase(char *str)
{
  int	i;

  i = -1;
  if (!str)
    return (NULL);
  while (str[++i])
    if ('a' <= str[i] && str[i] <= 'z')
      str[i] -= 32;
  return (str);
}
