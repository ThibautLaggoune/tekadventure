/*
** edit_move_area.c for  in /home/thibaut/delivery/Semestre_2/MUL/tekadventure
** 
** Made by thibaut
** Login   <thibaut.laggoune@epitech.eu@epitech.net>
** 
** Started on  Sat May 27 12:57:35 2017 thibaut
** Last update Mon May 29 01:27:13 2017 thibaut
*/

#include <stdlib.h>
#include "headers.h"
#include "macro.h"
#include "main.h"
#include "my.h"

int		check_move_area(sfEvent *event, t_main *core,
				sfVector2f *vec)
{
  sfVector2f	s_p;

  if (event->mouseButton.y < SHEIGHT - (int)core->layout[0]->size.y &&
      vec[0].x != -1 && (int)(vec[1].x) == -1)
    {
      s_p.x = event->mouseButton.x;
      s_p.y = event->mouseButton.y;
      vec[1] = s_p;
      return (1);
    }
  return (0);
}

int		verif(sfVector2f *vec, t_editor *resource, t_main *core)
{
  sfIntRect	*rect;

  if (!(rect = malloc(sizeof(*rect))))
    return (84);
  *rect = getintrect(compar_int(vec[0].y, vec[1].y),
		     compar_int(vec[0].x, vec[1].x),
		     MYABS((int)(vec[0].x - vec[1].x)),
		     MYABS((int)(vec[0].y - vec[1].y)));
  save_rekt(resource, rect, core);
  return (1);
}

int	event_icone_move_area(t_main *core, t_editor *resource,
			      sfEvent *event, sfVector2f *vec)
{
  while (sfRenderWindow_pollEvent(core->window, event))
    {
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	return (2);
      if (event->type == sfEvtClosed)
	sfRenderWindow_close(core->window);
      else if (!(event->type == sfEvtMouseButtonPressed &&
		 sfMouse_isButtonPressed(sfMouseLeft)))
	return (0);
      if (event->mouseButton.y < SHEIGHT - (int)core->layout[0]->size.y &&
	  vec[0].x < 0)
	{
	  vec[0] = getv2f(event->mouseButton.x, event->mouseButton.y);
	  return (1);
	}
      check_move_area(event, core, vec);
      if (vec[1].x != -1)
	if (verif(vec, resource, core) == 1)
	  return (2);
    }
  return (0);
}

int	move_icone_move_area(t_main *core, t_editor *resource)
{
  int		ret;
  sfEvent	event;
  sfVector2f	vec[2];

  ret = 1;
  vec[0] = getv2f(-1, -1);
  vec[1] = getv2f(-1, -1);
  while (ret == 1 && sfRenderWindow_isOpen(core->window))
    {
      print_draw_rect_ma(core);
      my_memset(&event, 0, sizeof(sfEvent));
      ret = 0;
      while (sfRenderWindow_isOpen(core->window) && ret == 0)
	{
	  ret = event_icone_move_area(core, resource, &event, vec);
	  if (ret == 84)
	    return (84);
	}
    }
  if (ret == 2)
    ret = 1;
  return (ret);
}

int             draw_icone_move_area(t_main *core, t_editor *resource)
{
  sfIntRect     rect;
  int           ret;
  sfEvent       event;

  ret = 1;
  while (ret == 1 && sfRenderWindow_isOpen(core->window))
    {
      print_draw_rect_ma(core);
      my_memset(&event, 0, sizeof(event));
      ret = 0;
      while (sfRenderWindow_isOpen(core->window) && ret == 0)
	{
	  while (sfRenderWindow_pollEvent(core->window, &event))
	    {
	      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
		return (1);
	      if (check_norm(core, event, resource, rect) == 84)
		return (84);
	    }
	}
    }
  return (1);
}
