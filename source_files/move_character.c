/*
** move_character.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Wed May 24 00:22:57 2017 Corentin LEROY
** Last update Sun May 28 21:48:03 2017 Corentin LEROY
*/

#include <SFML/Graphics.h>
#include "headers.h"
#include "macro.h"
#include "main.h"

sfVector2f	get_pos_from_map(t_map *map, t_play *resource)
{
  sfVector2f	ret;

  ret.x = map->io_areas[0][0];
  ret.y = map->io_areas[0][1];
  resource->to_be.x = map->io_areas[0][0] + resource->size.x / 2;
  resource->to_be.y = map->io_areas[0][1] + resource->size.y;
  return (ret);
}

int		get_pos(int mode)
{
  static int	pos[4] = {0, 0, 0, 0};

  if (pos[mode] > 100)
    pos[mode] = -100;
  pos[mode] += 1;
  return (pos[mode]);
}

static void	move_width(t_play *resource)
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
      position_parallax(resource, -0.3);
    }
  else if (resource->chara_pos.x + resource->size.x / 2 < resource->to_be.x)
    {
      pos = get_pos(1);
      if (pos > 0)
	resource->cur_way = 5;
      else
	resource->cur_way = 4;
      resource->chara_pos.x += 0.5;
      position_parallax(resource, 0.3);
    }
  else if (!(resource->chara_pos.y + resource->size.y > resource->to_be.y) &&
	   !(resource->chara_pos.y + resource->size.y < resource->to_be.y))
    resource->cur_way = 0;
}

void	move_height(t_play *resource)
{
  int	pos;

  if (resource->chara_pos.y + resource->size.y > resource->to_be.y)
    {
      pos = get_pos(3);
      if (pos > 0)
	resource->cur_way = 3;
      else
	resource->cur_way = 2;
      resource->chara_pos.y -= 0.5;
    }
  else if (resource->chara_pos.y + resource->size.y < resource->to_be.y)
    {
      pos = get_pos(4);
      if (pos > 0)
	resource->cur_way = 1;
      else
	resource->cur_way = 0;
      resource->chara_pos.y += 0.5;
    }
  else
    if (!(resource->chara_pos.x + resource->size.x / 2 > resource->to_be.x) &&
	!(resource->chara_pos.y + resource->size.y / 2 < resource->to_be.y))
      resource->cur_way = 0;
}

int		move_characters(t_main *core, t_play *resource)
{
  int		pos;
  sfSprite	*tmp;

  pos = resource->cur_chara * 27 + resource->cur_way;
  tmp = resource->characters[pos]->sprite;
  if (resource->chara_pos.x == -SWIDTH)
    {
      resource->chara_pos = get_pos_from_map(resource->cur_map, resource);
    }
  move_width(resource);
  move_height(resource);
  sfSprite_setPosition(tmp, resource->chara_pos);
  sfRenderWindow_drawSprite(core->window, tmp, NULL);
  return (get_out(resource));
}
