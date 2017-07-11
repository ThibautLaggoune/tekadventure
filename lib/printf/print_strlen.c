/*
** strlen.c for my strlen in /home/XIII/delivery/CPool_Day04
** 
** Made by Corentin LEROY
** Login   <XIII@epitech.net>
** 
** Started on  Thu Oct  6 16:25:52 2016 Corentin LEROY
** Last update Thu Feb  2 13:57:20 2017 Corentin LEROY
*/

#include <stdlib.h>

int	print_tablen(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return (0);
  while (tab[i])
    i++;
  return (i);
}

int	print_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    i++;
  return (i);
}
