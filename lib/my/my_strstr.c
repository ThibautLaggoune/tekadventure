/*
** my_strstr.c for my_strstr in /home/XIII/delivery/CPool_Day06
** 
** Made by Corentin LEROY
** Login   <XIII@epitech.net>
** 
** Started on  Mon Oct 10 11:14:01 2016 Corentin LEROY
** Last update Tue Oct 11 21:38:59 2016 Corentin LEROY
*/
#include <stdlib.h>

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	lenght;
  int	pause;

  lenght = 0;
  if (to_find[0] == '\0')
    return (str);
  while (str[lenght] != '\0')
    {
      i = 0;
      if (str[lenght] == to_find[0])
	{
	  pause = lenght;
	  while (str[lenght] == to_find[i] && str[lenght] != '\0')
	    {
	      lenght = lenght + 1;
	      i = i + 1;
	      if (to_find[i] == '\0')
		return (&str[pause]);
	    }
	  lenght = pause;
	}
      lenght = lenght + 1;
    }
  return (NULL);
}
