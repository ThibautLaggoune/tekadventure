/*
** fill_map_struct_sound.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Fri May 26 12:49:00 2017 Corentin LEROY
** Last update Fri May 26 12:49:01 2017 Corentin LEROY
*/

#include <stdlib.h>
#include "headers.h"
#include "my.h"

t_sound	*get_sound(char *buff)
{
  t_sound	*ret;

  if (!(ret = malloc(sizeof(*ret))))
	return (NULL);
  if (!(ret->name = my_strdup(buff)))
	return (NULL);
  if (!(ret->music = sfMusic_createFromFile(buff)))
	return (NULL);
  return (ret);
}

int		fill_charasound(t_map *map, char **buff, int *i)
{
  t_sound	**tmp;
  int		j;
  int		k;

  j = 0;
  map->script_sound = NULL;
  while (buff[*i] && buff[*i][0] == '\t')
    {
      j += 1;
      if (!(tmp = malloc(sizeof(*tmp) * (j + 1))) ||
	  !(tmp[j - 1] = get_sound(buff[*i] + 1)))
	return (-1);
      k = 0;
      while (map->script_sound && map->script_sound[k])
	{
	  tmp[k] = map->script_sound[k];
	  k += 1;
	}
      tmp[k + 1] = NULL;
      free(map->script_sound);
      map->script_sound = tmp;
      *i += 1;
    }
  return (j);
}
