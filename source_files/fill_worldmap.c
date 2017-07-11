/*
** fill_map.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Tue May 23 00:52:08 2017 Corentin LEROY
** Last update Thu May 25 12:20:22 2017 Corentin LEROY
*/

#include <stdlib.h>
#include "headers.h"
#include "macro.h"
#include "main.h"
#include "my.h"

void	initfillworldmaptab(char **tab)
{
  tab[0] = FILLID;
  tab[1] = FILLMU;
  tab[2] = FILLBG;
  tab[3] = FILLNO;

}

void	initfillworldmapptr(int (**ptr)())
{
  ptr[0] = fillw_id;
  ptr[1] = fillw_music;
  ptr[2] = fillw_background;
  ptr[3] = fillw_nodes;
}

int	fill_worldmap_curl(t_world *ret, char **buff, int *i)
{
  int	j;
  int	(*ptr[WORLDMAPFIELD])(t_world *, char **, int *);
  char	*cmp[WORLDMAPFIELD];

  initfillworldmaptab(cmp);
  initfillworldmapptr(ptr);
  j = 0;
  while (j < MAPFIELD)
    {
      if (!my_strcmp(cmp[j], buff[*i]))
	{
	  *i += 1;
	  return (ptr[j](ret, buff, i));
	}
      j += 1;
    }
  return (0);
}

t_world	*init_worldmap()
{
  t_world	*ret;

  if (!(ret = malloc(sizeof(*ret))))
	return (NULL);
  ret->background = NULL;
  ret->music = NULL;
  ret->list = NULL;
  return (ret);
}

t_world	*fill_worldmap_struct(char **buff)
{
  int	i;
  t_world	*ret;

  if (!(ret = init_worldmap()))
    return (NULL);
  i = 0;
  while (buff[i])
    {
      if (fill_worldmap_curl(ret, buff, &i) < 1)
	return (NULL);
    }
  my_free_tab(buff);
  return (ret);
}
