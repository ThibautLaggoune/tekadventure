/*
** quitmenu.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure/source_files
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Thu Apr 13 01:40:05 2017 Corentin LEROY
** Last update Mon May 29 01:08:33 2017 thibaut
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "main.h"

int	quitgame(t_main *core)
{
  sfRenderWindow_close(core->window);
  return (0);
}

int	quitoptions(t_main *core, int x, int y)
{
  (void)x;
  (void)y;
  (void)core;
  return (2);
}

int	quit_edit(t_main *core, int param[2], t_editor *resource)
{
  (void)param;
  (void)core;
  if ((resource->save->backgrounds = malloc(sizeof(t_picture*) * 3)) == NULL)
    return (84);
  resource->save->backgrounds[0] = resource->backgrounds[param[0]];
  resource->save->backgrounds[1] = resource->parallax[param[1]];
  resource->save->backgrounds[2] = NULL;
  save_in_file(resource);
  return (2);
}

int	return_backward(t_main *core, t_picture **sprite, int **s_chara)
{
  (void)core;
  (void)sprite;
  (void)s_chara;
  return (2);
}
