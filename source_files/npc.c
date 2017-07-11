/*
** npc.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Thu May 25 14:57:11 2017 Corentin LEROY
** Last update Sun May 28 23:41:31 2017 Corentin LEROY
*/

#include <SFML/Graphics.h>
#include "headers.h"
#include "macro.h"
#include "main.h"

int		display_npc(t_main *core, t_map *map)
{
  int		i;
  t_picture	*tmp;
  sfVector2f	pos;

  i = 0;
  if (map->characters && map->chara_locations)
    while (map->characters[i] && map->chara_locations[i])
      {
	tmp = map->characters[i]->body;
	pos = sfSprite_getPosition(tmp->sprite);
	if (pos.x == -SWIDTH && pos.y == -SHEIGHT)
	  pos = getv2f(map->chara_locations[i][2],
		       map->chara_locations[i][3]);
	sfSprite_setPosition(tmp->sprite, pos);
	sfRenderWindow_drawSprite(core->window, tmp->sprite, NULL);
	i += 1;
      }
  return (0);
}
