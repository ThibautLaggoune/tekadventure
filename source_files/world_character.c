/*
** move_character.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Wed May 24 00:22:57 2017 Corentin LEROY
** Last update Sun May 28 18:40:48 2017 Corentin LEROY
*/

#include <SFML/Graphics.h>
#include "headers.h"
#include "macro.h"
#include "main.h"

sfVector2f	get_pos_from_world(t_world *map, t_picture *chara)
{
  sfVector2f	ret;
  sfVector2f	shift;

  shift.x = SWIDTH / 2 - map->list[map->location]->pos.x;
  shift.y = (SHEIGHT - 140) / 2;
  shift.y -= map->list[map->location]->pos.y;
  ret.x = map->list[map->location]->pos.x - chara->size.x + shift.x;
  ret.y = map->list[map->location]->pos.y - chara->size.y + shift.y;
  return (ret);
}

static void	move_wwidth(t_play *resource)
{
  int		pos;

  if (resource->chara_pos.x + resource->size.x / 2 > resource->to_be.x)
    {
      pos = get_pos(0);
      if (pos > 0)
	resource->cur_way = 7;
      else
	resource->cur_way = 6;
      resource->chara_pos.x -= 0.5;
    }
  else if (resource->chara_pos.x + resource->size.x / 2 < resource->to_be.x)
    {
      pos = get_pos(1);
      if (pos > 0)
	resource->cur_way = 5;
      else
	resource->cur_way = 4;
      resource->chara_pos.x += 0.5;
    }
  else if (!(resource->chara_pos.y + resource->size.y > resource->to_be.y) &&
	   !(resource->chara_pos.y + resource->size.y < resource->to_be.y))
    resource->cur_way = 0;
}

int	check_if_newmap(t_main *core, t_play *resource, t_world *map)
{
  int		i;
  sfIntRect	test;
  sfVector2f	shift;

  shift.x = SWIDTH / 2 - map->list[map->location]->pos.x;
  shift.y = (SHEIGHT - core->layout[0]->size.y) / 2;
  shift.y -= map->list[map->location]->pos.y;
  i = 0;
  while (map->list[i])
    {
      test = getintrect(map->list[i]->pos.y + shift.y - 15,
			map->list[i]->pos.x + shift.x - 15, 30, 30);
      if (sfIntRect_contains(&test,
			     resource->chara_pos.x + resource->size.x / 2,
			     resource->chara_pos.y + resource->size.y) &&
	  map->location != i)
	return (i);
      i += 1;
    }
  return (0);
}

int		world_characters(t_main *core, t_play *resource, t_world *map)
{
  int		pos;
  int		ret;
  sfSprite	*tmp;

  pos = resource->cur_chara * 27 + resource->cur_way;
  tmp = resource->characters[pos]->sprite;
  if (resource->chara_pos.x == -SWIDTH)
    {
      resource->chara_pos = get_pos_from_world(map,
					       resource->characters[pos]);
      resource->to_be = resource->chara_pos;
      resource->to_be.y += resource->size.y;
    }
  move_wwidth(resource);
  move_height(resource);
  sfSprite_setPosition(tmp, resource->chara_pos);
  sfRenderWindow_drawSprite(core->window, tmp, NULL);
  ret = check_if_newmap(core, resource, map);
  sfRenderWindow_display(core->window);
  return (ret);
}
