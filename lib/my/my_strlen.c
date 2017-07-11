/*
** my_strlen.c for my_strlen in /home/XIII/delivery/CPool_Day04
** 
** Made by Corentin LEROY
** Login   <XIII@epitech.net>
** 
** Started on  Thu Oct  6 16:25:52 2016 Corentin LEROY
** Last update Thu Apr  6 11:43:01 2017 Corentin LEROY
*/

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  if (!tab)
    return (0);
  while (tab[i])
    i++;
  return (i);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (!str)
    return (0);
  while (str[i])
    i++;
  return (i);
}
