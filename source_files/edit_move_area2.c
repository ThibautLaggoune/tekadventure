/*
** edit_move_area2.c for  in /home/thibaut/delivery/Semestre_2/MUL/tekadventure/source_files
** 
** Made by thibaut
** Login   <thibaut.laggoune@epitech.eu@epitech.net>
** 
** Started on  Mon May 29 01:04:54 2017 thibaut
** Last update Mon May 29 01:36:41 2017 thibaut
*/

#include <stdlib.h>
#include "headers.h"
#include "macro.h"
#include "main.h"
#include "my.h"

int		save_rekt(t_editor *resource, sfIntRect *rect, t_main *core)
{
  sfIntRect	**rect_save;
  int		i;

  i = 0;
  if (resource->save->move_areas)
    while (resource->save->move_areas[i])
      i++;
  if ((rect_save = malloc(sizeof(sfIntRect*) * (i + 2))) == NULL)
    return (84);
  i = 0;
  if (resource->save->move_areas)
    while (resource->save->move_areas[i] != NULL)
      {
	rect_save[i] = resource->save->move_areas[i];
	i++;
      }
  rect_save[i] = rect;
  rect_save[i + 1] = NULL;
  if (resource->save->move_areas)
    free(resource->save->move_areas);
  resource->save->move_areas = rect_save;
  display_rect_from_intrect(core, resource->save->move_areas, sfGreen);
  sfRenderWindow_display(core->window);
  return (1);
}

int	compar_int(float f_p, float s_p)
{
  if (f_p > s_p)
    return ((int)s_p);
  else
    return ((int)f_p);
}

int	check_norm(t_main *core, sfEvent event, t_editor *resource,
		   sfIntRect rect)
{
  int	ret;

  ret = 0;
  rect = getintrect(SHEIGHT - (int)core->layout[0]->size.y + 50,
		    50, 100, 100);
  if (sfIntRect_contains(&rect, event.mouseButton.x,
			 event.mouseButton.y))
    if ((ret = move_icone_move_area(core, resource)) == 84)
      return (84);
  rect = getintrect(SHEIGHT - (int)core->layout[0]->size.y + 50,
		    200, 100, 100);
  if (sfIntRect_contains(&rect, event.mouseButton.x,
			 event.mouseButton.y))
    if ((ret = move_icone_io(core, resource)) == 84)
      return (84);
  return (0);
}
