/*
** play_worldmap.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Sat May 27 11:26:01 2017 Corentin LEROY
** Last update Sun May 28 18:21:21 2017 Corentin LEROY
*/

#include <SFML/Graphics/Sprite.h>
#include "headers.h"
#include "macro.h"
#include "main.h"
#include "my.h"

int		display_overlay(t_main *core, t_world *map)
{
  sfVector2f	pos;
  sfText	*text;

  pos = getv2f(0, SHEIGHT - core->layout[0]->size.y);
  sfSprite_setPosition(core->layout[0]->sprite, pos);
  sfRenderWindow_drawSprite(core->window, core->layout[0]->sprite, NULL);
  if (!(text = create_new_text(map->list[map->location]->name, sfWhite,
			       core->fonts[1], 23)))
    return (84);
  pos = getv2f(20, SHEIGHT - core->layout[0]->size.y + 30);
  sfText_setPosition(text, pos);
  sfRenderWindow_drawText(core->window, text, NULL);
  return (0);
}

int		display_worldmap(t_main *core, t_world *map, int mode,
				 int level)
{
  sfVector2f	pos;
  sfVector2f	shift;
  int		i;

  shift.x = SWIDTH / 2 - map->list[map->location]->pos.x;
  shift.y = (SHEIGHT - core->layout[0]->size.y) / 2;
  shift.y -= map->list[map->location]->pos.y;
  sfSprite_setPosition(map->background->sprite, shift);
  sfRenderWindow_drawSprite(core->window, map->background->sprite, NULL);
  i = 0;
  while (map->list[i])
    {
      if (map->list[i]->level <= level)
	{
	  pos.x = map->list[i]->pos.x + shift.x - 15;
	  pos.y = map->list[i]->pos.y + shift.y - 15;
	  if (print_rectangle(pos, getv2i(30, 30), sfRed, core->window) == 84)
	    return (84);
	}
      i += 1;
    }
  if (mode)
    return (display_overlay(core, map));
  return (0);
}

int	quit_world(t_main *core, t_world *map, int ret)
{
  unparse_worldmap(core, map);
  return (ret);
}

int		play_worldmap(t_main *core, t_play *resource, char *path,
			      int origine)
{
  int		ret;
  t_world	*map;
  char		**files;
  sfEvent	event;

  if (!(files = get_files(path)) || !(map = get_worldmap(files, path)))
    return (-2);
  my_free_tab(files);
  map->location = origine;
  ret = -1;
  while (sfRenderWindow_isOpen(core->window) && ret == -1)
    {
      my_memset(&event, 0, sizeof(event));
      ret = 0;
      while (sfRenderWindow_isOpen(core->window) && ret == 0)
	{
	  if (display_worldmap(core, map, 1, resource->level) == 84)
	    return (-2);
	  if ((ret = world_characters(core, resource, map)) == 0)
	    if ((ret = event_world_map(core, &event, resource, map)) == 84)
	      return (quit_world(core, map, -2));
	}
    }
  return (quit_world(core, map, ret));
}
