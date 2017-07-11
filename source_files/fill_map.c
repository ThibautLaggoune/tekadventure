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

void	initfillmaptab(char **tab)
{
  tab[0] = FILLID;
  tab[1] = FILLMU;
  tab[2] = FILLBG;
  tab[3] = FILLPA;
  tab[4] = FILLMO;
  tab[5] = FILLIO;
  tab[6] = FILLNP;
  tab[7] = FILLPO;
  tab[8] = FILLTE;
  tab[9] = FILLSO;
}

void	initfillmapptr(int (**ptr)())
{
  ptr[0] = fill_id;
  ptr[1] = fill_music;
  ptr[2] = fill_background;
  ptr[3] = fill_parallax;
  ptr[4] = fill_moveareas;
  ptr[5] = fill_ioareas;
  ptr[6] = fill_chara;
  ptr[7] = fill_charapos;
  ptr[8] = fill_charatext;
  ptr[9] = fill_charasound;
}

t_map	*init_map(int id)
{
  t_map	*ret;

  if (!(ret = malloc(sizeof(*ret))))
    return (NULL);
  ret->id_map = id;
  ret->musical_theme = NULL;
  ret->move_areas = NULL;
  ret->io_areas = NULL;
  ret->obj_locations = NULL;
  ret->chara_locations = NULL;
  ret->characters = NULL;
  ret->chara_scripts = NULL;
  ret->script_sound = NULL;
  ret->script_text = NULL;
  ret->script_scene = NULL;
  ret->backgrounds = NULL;
  return (ret);
}

int	fill_map_curl(t_map *ret, char **buff, int *i)
{
  int	j;
  int	(*ptr[MAPFIELD])(t_map *, char **, int *);
  char	*cmp[MAPFIELD];

  initfillmaptab(cmp);
  initfillmapptr(ptr);
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

t_map	*fill_map_struct(int id, char **buff)
{
  int	i;
  t_map	*ret;

  if (!(ret = init_map(id)))
    return (NULL);
  i = 0;
  while (buff[i])
    {
      if (fill_map_curl(ret, buff, &i) < 1)
	return (NULL);
    }
  my_free_tab(buff);
  return (ret);
}
