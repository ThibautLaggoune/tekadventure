/*
** change_map.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Sun May 28 21:49:34 2017 Corentin LEROY
** Last update Sun May 28 21:57:00 2017 Corentin LEROY
*/

#include <SFML/Graphics.h>
#include "main.h"

int		change_map(t_play *resource, int *cur_zone)
{
  sfIntRect	test;
  int		**areas;
  int		i;
  sfVector2f	pos;

  pos = resource->chara_pos;
  i = 0;
  areas = resource->cur_map->io_areas;
  while (areas[i])
    {
      test = getintrect(areas[i][1], areas[i][0], areas[i][2],
			areas[i][3]);
      if (*cur_zone == -1)
	if (sfIntRect_contains(&test, pos.x + resource->size.x / 2,
			       pos.y + resource->size.y))
	  {
	    *cur_zone = 0;
	    return (areas[i][4]);
	  }
      i += 1;
    }
  return (-1);
}

int		get_out(t_play *resource)
{
  static int	cur_zone = 0;
  int		**areas;
  sfIntRect	test;
  sfVector2f	pos;

  pos = resource->chara_pos;
  areas = resource->cur_map->io_areas;
  if (cur_zone == 0)
    {
      test = getintrect(areas[0][1], areas[0][0], areas[0][2], areas[0][3]);
      if (!sfIntRect_contains(&test, pos.x + resource->size.x / 2,
			      pos.y + resource->size.y))
	cur_zone = -1;
    }
  else
    return (change_map(resource, &cur_zone));
  return (-1);
}
