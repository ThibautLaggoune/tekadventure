/*
** event_sprites.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Fri May 26 00:19:18 2017 Corentin LEROY
** Last update Fri May 26 00:19:19 2017 Corentin LEROY
*/

#include <SFML/Window/Keyboard.h>
#include "headers.h"
#include "macro.h"
#include "main.h"

void	get_compare_input(int *compare)
{
  compare[0] = sfKeyLeft;
  compare[1] = sfKeyRight;
  compare[2] = sfKeyUp;
  compare[3] = sfKeyDown;
  compare[4] = sfKeyEscape;
}

int			check_click(sfEvent *event, t_main *core,
				    t_picture **sprite,
				    int *s_chara)
{
  static int		bool = 0;
  static t_picture	*tmp = NULL;

  if (event->mouseButton.y > SHEIGHT - (int)core->layout[0]->size.y)
    {
      tmp = pick_sprite(core, event, sprite, s_chara);
      if (tmp)
	{
	  bool = 1;
	}
    }
  else if (event->mouseButton.y < SHEIGHT - (int)core->layout[0]->size.y &&
	   bool)
    {
      if (drop_sprite(core, event, tmp) == 1)
	{
	  bool = 0;
	  tmp = NULL;
	}
    }
  return (1);
}

int	event_icone_chara(t_main *core, t_picture **sprite, sfEvent *event,
			  int *s_chara)
{
  int	compare[PTRSPRITE];
  int	(*ptr[PTRSPRITE])(t_main*, t_picture**, int*);
  int	i;
  int	ret;

  ret = 0;
  while (sfRenderWindow_pollEvent(core->window, event))
    {
      if (event->type == sfEvtClosed)
	sfRenderWindow_close(core->window);
      if (event->type == sfEvtKeyPressed)
	{
	  get_compare_input(compare);
	  init_compare_input(ptr);
	  i = -1;
	  while (++i < PTRSPRITE && event->type == sfEvtKeyPressed)
	    if (sfKeyboard_isKeyPressed(compare[i]))
	      ret = ptr[i](core, sprite, s_chara);
	}
      else if (event->type == sfEvtMouseButtonPressed)
	ret = check_click(event, core, sprite, s_chara);
    }
  return (ret);
}
