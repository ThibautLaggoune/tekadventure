/*
** printf_towordtab.c for printf wordtab in /home/leroyc/Delivery/PSU/
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Sat Nov 12 15:30:58 2016 Corentin LEROY
** Last update Fri Mar 24 14:01:54 2017 Corentin LEROY
*/

#include <stdlib.h>
#include "print.h"

int	get_bflag(char c)
{
  int	i;
  char	*str;

  str = "dicsSouxX%pb";
  i = 0;
  while ((c != str[i]) && (str[i] != 0))
    i++;
  return (i);
}

int	get_nbrargs(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      while ((str[i] != '%') && (str[i] != 0))
	i++;
      if (str[i] == '%')
	{
	  j++;
	  i++;
	}
      while (get_bflag(str[i]) == 14 && str[i] != 0)
	i++;
      ((str[i] == 0) ? (i) : (i++));
    }
  return (j);
}

int	get_arg_end(char *str, int i)
{
  while (get_bflag(str[i]) == 12 && str[i] != 0)
    i++;
  return (i);
}

char	**printf_towordtab(char *str)
{
  char	**tab;
  int	j;
  int	k;
  int	argend;
  int	i;

  if ((tab = malloc(sizeof(char *) * (get_nbrargs(str) + 1))) == NULL)
    return (0);
  i = 0;
  j = 0;
  while (j < get_nbrargs(str))
    {
      k = 0;
      while (str[i] != '%')
	i++;
      argend = get_arg_end(str, i + 1);
      if ((tab[j] = malloc(sizeof(char) * (argend - i + 1))) == NULL)
	return (0);
      while (i++ < argend)
	tab[j][k++] = str[i];
      tab[j++][k] = 0;
    }
  tab[j] = 0;
  return (tab);
}
