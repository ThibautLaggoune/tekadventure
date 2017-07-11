/*
** play_map.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure/source_files
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Mon May 22 09:42:09 2017 Corentin LEROY
** Last update Sun May 28 18:46:27 2017 thibaut
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/RectangleShape.h>
#include <stdlib.h>
#include "headers.h"
#include "macro.h"
#include "main.h"
#include "my.h"

int			display_rect_from_intrect(t_main *core,
						  sfIntRect **tab,
						  sfColor color)
{
  sfVector2f		pos;
  sfRectangleShape	*rect;
  int			i;
  sfColor		incolor;

  i = 0;
  incolor = sfColor_fromRGBA(0, 0, 0, 0);
  if (!(rect = sfRectangleShape_create()))
    return (84);
  while (tab[i])
    {
      pos.x = tab[i]->left;
      pos.y = tab[i]->top;
      sfRectangleShape_setPosition(rect, pos);
      pos.x = tab[i]->width;
      pos.y = tab[i]->height;
      sfRectangleShape_setSize(rect, pos);
      sfRectangleShape_setFillColor(rect, incolor);
      sfRectangleShape_setOutlineColor(rect, color);
      sfRectangleShape_setOutlineThickness(rect, 3);
      sfRenderWindow_drawRectangleShape(core->window, rect, NULL);
      i += 1;
    }
  sfRectangleShape_destroy(rect);
  return (0);
}

int		display_rect_from_int(t_main *core, int **tab, sfColor color)
{
  sfVector2f		pos;
  sfRectangleShape	*rect;
  int			i;

  i = 0;
  if (!(rect = sfRectangleShape_create()))
    return (84);
  sfRectangleShape_setFillColor(rect, color);
  while (tab[i])
    {
      pos.x = tab[i][0];
      pos.y = tab[i][1];
      sfRectangleShape_setPosition(rect, pos);
      pos.x = tab[i][2];
      pos.y = tab[i][3];
      sfRectangleShape_setSize(rect, pos);
      sfRenderWindow_drawRectangleShape(core->window, rect, NULL);
      i += 1;
    }
  sfRectangleShape_destroy(rect);
  return (0);
}

int		display_map(t_main *core, t_map *map, int mode)
{
  sfVector2f	pos;

  if (mode)
    {
      pos.x = 0;
      pos.y = SHEIGHT - core->layout[0]->size.y;
      sfSprite_setPosition(core->layout[0]->sprite, pos);
      sfRenderWindow_drawSprite(core->window, core->layout[0]->sprite, NULL);
      return (0);
    }
  pos = sfSprite_getPosition(map->backgrounds[0]->sprite);
  pos.y = SHEIGHT - map->backgrounds[0]->size.y - core->layout[0]->size.y;
  sfSprite_setPosition(map->backgrounds[0]->sprite, pos);
  sfRenderWindow_drawSprite(core->window, map->backgrounds[0]->sprite, NULL);
  display_parallax(core, map);
  display_npc(core, map);
  return (0);
}

int	quit_map(t_main *core, t_map *map, int ret)
{
  unparse_map(core, map);
  return (ret);
}

int		play_map(t_main *core, t_play *resource, int id,
			 char *folder_name)
{
  int		ret;
  char		**files;
  sfEvent	event;

  if (!(files = get_files(folder_name)) ||
      !(resource->cur_map = get_map(id, files, folder_name)))
    return (-2);
  change_music(core, resource->cur_map->musical_theme->music);
  ret = 1;
  while (sfRenderWindow_isOpen(core->window) && (ret == 1 || ret == 0))
    {
      my_memset(&event, 0, sizeof(event));
      ret = 0;
      display_map(core, resource->cur_map, 1);
      while (sfRenderWindow_isOpen(core->window) && ret == 0)
	{
	  display_map(core, resource->cur_map, 0);
	  if ((ret = move_characters(core, resource)) >= 0)
		return (quit_map(core, resource->cur_map, ret));
	  sfRenderWindow_display(core->window);
	  if ((ret = event_play_map(core, &event, resource)) == 84)
	    return (quit_map(core, resource->cur_map, -2));
	}
    }
  return (quit_map(core, resource->cur_map, ret));
}
