/*
** event_world.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Sat May 27 18:19:30 2017 Corentin LEROY
** Last update Sun May 28 16:18:26 2017 Corentin LEROY
*/

#include <SFML/Window/Event.h>
#include <SFML/Graphics/Rect.h>
#include "headers.h"
#include "macro.h"
#include "main.h"

int		check_world_move(t_main *core, sfEvent *event, t_play *resource,
				 t_world *map)
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
      if (sfIntRect_contains(&test, event->mouseButton.x,
			     event->mouseButton.y))
	{
	  resource->to_be = getv2f(event->mouseButton.x,
				   event->mouseButton.y);
	  return (-1);
	}
      i += 1;
    }
  return (0);
}

int	event_world_map(t_main *core, sfEvent *event, t_play *resource,
			t_world *map)
{
  int	ret;

  (void)resource;
  ret = 0;
  if (sfRenderWindow_pollEvent(core->window, event))
    {
      if (event->type == sfEvtClosed)
	sfRenderWindow_close(core->window);
      if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape)
	ret = -3;
      else if (event->type == sfEvtMouseButtonPressed &&
	       sfMouse_isButtonPressed(sfMouseLeft))
	{
	  ret = check_world_move(core, event, resource, map);
	}
    }
  return (ret);
}
