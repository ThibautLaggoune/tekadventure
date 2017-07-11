/*
** my_tabcpy.c for tabcpy in /home/leroyc/Delivery/2016/LIB/lib/my
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Thu Jan 19 13:37:59 2017 Corentin LEROY
** Last update Thu Apr  6 11:48:42 2017 Corentin LEROY
*/

#include <stdlib.h>
#include "my.h"

char	**my_tabcpy(char **tab)
{
  char	**ret;
  int	i;

  if (!tab)
    return (NULL);
  if (!(ret = malloc(sizeof(char *) * (my_tablen(tab) + 1))))
    return (NULL);
  i = -1;
  while (tab[++i])
    if (!(ret[i] = my_strdup(tab[i])))
      return (NULL);
  ret[i] = NULL;
  return (ret);
}
