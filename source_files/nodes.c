/*
** nodes.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Sat May 27 13:52:34 2017 Corentin LEROY
** Last update Sat May 27 13:52:34 2017 Corentin LEROY
*/

#include <stdlib.h>
#include "headers.h"
#include "main.h"
#include "my.h"

int	get_nodenbr(t_node *ret, char *buff)
{
  char	**tmp;

  if (!(tmp = str_wt(buff, ' ')) || my_tablen(tmp) != 3)
	return (84);
  ret->level = my_getnbr(tmp[0]);
  ret->pos = getv2f(my_getnbr(tmp[1]), my_getnbr(tmp[2]));
  my_free_tab(tmp);
  return (0);
}

int	*get_nexts(char * buff)
{
  char	**tmp;
  int	*ret;
  int	size;
  int	i;

  if (!(tmp = str_wt(buff, ' ')) || !(size = my_tablen(tmp)) ||
  !(ret = malloc(sizeof(*ret) * (size + 1))))
	return (NULL);
  i = 0;
  while (i < size)
  {
	  ret[i] = my_getnbr(tmp[i]);
	  i++;
  }
  ret[i] = -1;
  my_free_tab(tmp);
  return (ret);
}

t_node	*get_node(char *buff)
{
  t_node	*ret;
  char		**tmp;

  if (!(ret = malloc(sizeof(*ret))) ||
    !(tmp = str_wt(buff, '\t')) || my_tablen(tmp) != 3 ||
	!(ret->name = my_strdup(tmp[1])))
	return (NULL);
  if (get_nodenbr(ret, tmp[0]) == 84)
	return (NULL);
  if (!(ret->nexts = get_nexts(tmp[2])))
	return (NULL);
  my_free_tab(tmp);
  return (ret);
}

int		fillw_nodes(t_world *map, char **buff, int *i)
{
  t_node	**tmp;
  int		j;
  int		k;

  j = 0;
  map->list = NULL;
  while (buff[*i] && buff[*i][0] == '\t')
    {
      j += 1;
      if (!(tmp = malloc(sizeof(*tmp) * (j + 1))) ||
	  !(tmp[j - 1] = get_node(buff[*i] + 1)))
	return (-1);
      k = 0;
      while (map->list && map->list[k])
	{
	  tmp[k] = map->list[k];
	  k += 1;
	}
      tmp[k + 1] = NULL;
      free(map->list);
      map->list = tmp;
      *i += 1;
    }
  return (j);
}
