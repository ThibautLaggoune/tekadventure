/*
** move_background.c for  in /home/thibaut/delivery/Semestre_2/MUL/tekadventure/source_files
** 
** Made by thibaut
** Login   <thibaut.laggoune@epitech.eu@epitech.net>
** 
** Started on  Tue Apr 25 20:46:31 2017 thibaut
** Last update Fri May  5 00:53:24 2017 Corentin LEROY
*/

#include <SFML/Graphics.h>
#include "headers.h"
#include "main.h"

int	move_next_bck(t_main *core, int param[2], t_editor *resource)
{
  (void)core;
  if (param[0] == 0)
    {
      param[1] = resource->cur_state.bg_state;
      if (resource->backgrounds[param[1] + 1] != NULL)
	param[1] += 1;
      else
	param[1] = 0;
      resource->cur_state.bg_state = param[1];
    }
  if (param[0] == 1)
    {
      param[1] = resource->cur_state.para_state;
      if (resource->parallax[param[1] + 1] != NULL)
	param[1] += 1;
      else
	param[1] = 0;
      resource->cur_state.para_state = param[1];
    }
  return (1);
}

int	move_previous_bck(t_main *core, int param[2], t_editor *resource)
{
  (void)core;
  if (param[0] == 0)
    {
      param[1] = resource->cur_state.bg_state;
      if (param[1] == 0)
	{
	  while (resource->backgrounds[param[1]])
	    param[1] += 1;
	}
      param[1] -= 1;
      resource->cur_state.bg_state = param[1];
    }
  if (param[0] == 1)
    {
      param[1] = resource->cur_state.para_state;
      if (param[1] == 0)
	{
	  while (resource->parallax[param[1]])
	    param[1] += 1;
	}
      param[1] -= 1;
      resource->cur_state.para_state = param[1];
    }
  return (1);
}

int	move_upper_bck(t_main *core, int param[2], t_editor *resource)
{
  (void)core;
  (void)resource;
  if (param[0] > 0)
    {
      param[0] -= 1;
    }
  return (1);
}

int	move_lower_bck(t_main *core, int param[2], t_editor *resource)
{
  (void)core;
  (void)resource;
  if (param[0] < 2)
    {
      param[0] += 1;
    }
  return (1);
}
