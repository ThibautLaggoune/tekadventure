/*
** parallax.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Fri May 26 00:26:02 2017 Corentin LEROY
** Last update Sun May 28 23:35:27 2017 Corentin LEROY
*/

#include <SFML/Graphics/Sprite.h>
#include "headers.h"
#include "macro.h"

void		para_curl(t_play *resources, float shift)
{
  sfVector2f	npcpos;
  t_chara	**npc;
  int		**loca;
  int		i;

  i = 0;
  npc = resources->cur_map->characters;
  loca = resources->cur_map->chara_locations;
  while (npc && npc[i] && loca && loca[i])
    {
      npcpos = sfSprite_getPosition(npc[i]->body->sprite);
      npcpos.x -= shift;
      loca[i][0] -= shift;
      loca[i][2] -= shift;
      sfSprite_setPosition(npc[i]->body->sprite, npcpos);
      i += 1;
    }
}

void		position_parallax(t_play *resources, float shift)
{
  sfSprite	*tmp;
  sfVector2f	pos;

  tmp = resources->cur_map->backgrounds[1]->sprite;
  pos = sfSprite_getPosition(tmp);
  if (pos.x + resources->cur_map->backgrounds[1]->size.x - shift > SWIDTH &&
      pos.x + resources->cur_map->backgrounds[1]->size.x - shift > 0)
    {
      para_curl(resources, shift);
      pos.x -= shift;
      sfSprite_setPosition(resources->cur_map->backgrounds[1]->sprite, pos);
    }
}

void		display_parallax(t_main *core, t_map *map)
{
  sfVector2f	pos;

  pos = sfSprite_getPosition(map->backgrounds[1]->sprite);
  pos.y = SHEIGHT - map->backgrounds[1]->size.y - core->layout[0]->size.y;
  sfSprite_setPosition(map->backgrounds[1]->sprite, pos);
  sfRenderWindow_drawSprite(core->window, map->backgrounds[1]->sprite, NULL);
}
