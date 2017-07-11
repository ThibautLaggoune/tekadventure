/*
** move_icone_io.c for  in /home/thibaut/delivery/Semestre_2/MUL/tekadventure/source_files
** 
** Made by thibaut
** Login   <thibaut.laggoune@epitech.eu@epitech.net>
** 
** Started on  Sun May 28 17:03:05 2017 thibaut
** Last update Sun May 28 18:55:01 2017 thibaut
*/

#include <stdlib.h>
#include "headers.h"
#include "macro.h"
#include "main.h"
#include "my.h"

int	save_int(t_editor *resource, int *tmp, t_main *core)
{
  int	**int_save;
  int	i;

  i = 0;
  if (resource->save->io_areas)
    while (resource->save->io_areas[i])
      i++;
  if ((int_save = malloc(sizeof(int*) * (i + 2))) == NULL)
    return (84);
  i = 0;
  if (resource->save->io_areas)
    while (resource->save->io_areas[i] != NULL)
      {
	int_save[i] = resource->save->io_areas[i];
	i++;
      }
  int_save[i] = tmp;
  int_save[i + 1] = NULL;
  if (resource->save->io_areas)
    free(resource->save->io_areas);
  resource->save->io_areas = int_save;
  display_rect_from_int(core, int_save, sfRed);
  sfRenderWindow_display(core->window);
  return (1);
}

int		check_move_io(sfEvent *event, t_main *core,
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

int	verif_io(sfVector2f *vec, t_editor *resource, t_main *core)
{
  int	*io_areastmp;

  io_areastmp = malloc(sizeof(int) * 5);
  io_areastmp[0] = compar_int(vec[0].x, vec[1].x);
  io_areastmp[1] = compar_int(vec[0].y, vec[1].y);
  io_areastmp[2] = MYABS((int)(vec[0].x - vec[1].x));
  io_areastmp[3] = MYABS((int)(vec[0].y - vec[1].y));
  io_areastmp[4] = 0;
  save_int(resource, io_areastmp, core);
  return (1);
}

int		event_icone_io(t_main *core, t_editor *resource,
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
      check_move_io(event, core, vec);
      if (vec[1].x != -1)
	if (verif_io(vec, resource, core) == 1)
	  return (2);
    }
  return (0);
}

int		move_icone_io(t_main *core, t_editor *resource)
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
	  if ((ret = event_icone_io(core, resource, &event, vec)) == 84)
	    return (84);
	}
    }
  if (ret == 2)
    ret = 1;
    return (1);
}
