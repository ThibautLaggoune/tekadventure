/*
** fill_map_struct_areas.h for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure/source_files
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Mon May 22 16:47:34 2017 Corentin LEROY
** Last update Tue May 23 01:21:51 2017 Corentin LEROY
*/

#include <stdlib.h>
#include "headers.h"
#include "print.h"
#include "macro.h"
#include "main.h"
#include "my.h"

sfIntRect	*rectareas(char *buff)
{
  char		**tmp;
  sfIntRect	*ret;

  if (!(tmp = str_wt(buff, ' ')))
    return (NULL);
  if (my_tablen(tmp) != 4)
    return (NULL);
  ret = allocintrect(tmp[0], tmp[1], tmp[2], tmp[3]);
  my_free_tab(tmp);
  return (ret);
}

int		fill_moveareas(t_map *map, char **buff, int *i)
{
  sfIntRect	**tmp;
  int		j;
  int		k;

  j = 0;
  map->move_areas = NULL;
  while (buff[*i] && buff[*i][0] == '\t')
    {
      j += 1;
      if (!(tmp = malloc(sizeof(*tmp) * (j + 1))) ||
	  !(tmp[j - 1] = rectareas(buff[*i] + 1)))
	return (-1);
      k = 0;
      while (map->move_areas && map->move_areas[k])
	{
	  tmp[k] = map->move_areas[k];
	  k += 1;
	}
      tmp[k + 1] = NULL;
      free(map->move_areas);
      map->move_areas = tmp;
      *i += 1;
    }
  return (j);
}

int	*intareas(char *buff)
{
  char	**tmp;
  int	*ret;
  int	i;

  if (!(tmp = str_wt(buff, ' ')))
    return (NULL);
  if (my_tablen(tmp) != IOFIELD)
    return (NULL);
  if (!(ret = malloc(sizeof(int) * IOFIELD)))
    return (NULL);
  i = 0;
  while (tmp[i])
    {
      ret[i] = my_getnbr(tmp[i]);
      i += 1;
    }
  my_free_tab(tmp);
  return (ret);
}

int	fill_ioareas(t_map *map, char **buff, int *i)
{
  int	**tmp;
  int	j;
  int	k;

  j = 0;
  map->io_areas = NULL;
  while (buff[*i] && buff[*i][0] == '\t')
    {
      j += 1;
      if (!(tmp = malloc(sizeof(*tmp) * (j + 1))) ||
	  !(tmp[j - 1] = intareas(buff[*i] + 1)))
	return (-1);
      k = 0;
      while (map->io_areas && map->io_areas[k])
	{
	  tmp[k] = map->io_areas[k];
	  k += 1;
	}
      tmp[k + 1] = NULL;
      free(map->io_areas);
      map->io_areas = tmp;
      *i += 1;
    }
  return (j);
}
