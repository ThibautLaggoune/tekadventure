/*
** event_play.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Tue May 23 21:40:02 2017 Corentin LEROY
** Last update Fri May 26 17:46:56 2017 Corentin LEROY
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Window.h>
#include "headers.h"
#include "main.h"

int	check_event_move(sfEvent *event, t_play *resource)
{
  int	i;

  i = 0;
  while (resource->cur_map->move_areas[i])
    {
      if (sfIntRect_contains(resource->cur_map->move_areas[i],
			     event->mouseButton.x,
			     event->mouseButton.y))
	{
	  resource->to_be = getv2f(event->mouseButton.x,
				   event->mouseButton.y);
	  return (1);
	}
      i += 1;
    }
  return (0);
}

int		check_event_npc(t_main *core, sfEvent *event,
				t_play *resource)
{
  int		i;
  t_map		*tmp;
  sfFloatRect	rect;

  i = 0;
  tmp = resource->cur_map;
  while (tmp->characters[i] && tmp->chara_locations[i] &&
	 tmp->script_text[i])
    {
      rect = sfSprite_getGlobalBounds(tmp->characters[i]->body->sprite);
      if (sfFloatRect_contains(&rect, event->mouseButton.x,
			       event->mouseButton.y))
	{
	  if (tmp->script_text)
		display_text(core, tmp->script_text[i]);
	  if (tmp->script_sound)
		play_sound(core, tmp->script_sound[i]);
	  return (0);
	}
      i += 1;
    }
  return (0);
}

int	event_play_map(t_main *core, sfEvent *event, t_play *resource)
{
  int	ret;

  ret = 0;
  if (resource->to_be.x != resource->chara_pos.x + resource->size.x / 2 ||
      resource->to_be.y - resource->size.y != resource->chara_pos.y)
    ret = 1;
  if (sfRenderWindow_pollEvent(core->window, event))
    {
      if (event->type == sfEvtClosed)
	sfRenderWindow_close(core->window);
      if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape)
	ret = -1;
      else if (event->type == sfEvtMouseButtonPressed &&
	       sfMouse_isButtonPressed(sfMouseLeft))
	{
	  if ((ret = check_event_npc(core, event, resource)))
	    return (ret);
	  ret = check_event_move(event, resource);
	}
    }
  return (ret);
}
