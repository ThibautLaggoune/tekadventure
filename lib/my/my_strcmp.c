/*
** my_strcmp.c for my_strcmp in /home/XIII/delivery/CPool_Day06
** 
** Made by Corentin LEROY
** Login   <XIII@epitech.net>
** 
** Started on  Mon Oct 10 16:30:50 2016 Corentin LEROY
** Last update Mon May 22 16:12:54 2017 Corentin LEROY
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  if (s1 == NULL || s2 == NULL)
    return (84);
  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    {
      i += 1;
    }
  if (s1[i] > s2[i])
    return (1);
  else if (s1[i] < s2[i])
    return (-1);
  return (0);
}
