/*
** event.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure/source_files
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Tue Apr  4 15:43:49 2017 Corentin LEROY
** Last update Thu May 25 20:23:11 2017 thibaut
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window.h>
#include "macro.h"
#include "main.h"

int		event_option_menu(t_main *core, sfEvent *event)
{
  sfIntRect	menu[4];
  int		(*ptr[4])(t_main *, int, int);
  int		i;
  int		ret;

  ret = 0;
  while (sfRenderWindow_pollEvent(core->window, event))
    {
      if (event->type == sfEvtClosed)
	sfRenderWindow_close(core->window);
      if (event->type == sfEvtMouseButtonPressed &&
	  sfMouse_isButtonPressed(sfMouseLeft))
	{
	  getrectoptions(menu);
	  initoptptr(ptr);
	  i = -1;
	  while (++i < 4)
	    if (sfIntRect_contains(&menu[i], event->mouseButton.x,
				   event->mouseButton.y))
	      ret = ptr[i](core, event->mouseButton.x, event->mouseButton.y);
	}
    }
  return (ret);
}

int		event_main_menu(t_main *core, sfEvent *event)
{
  sfIntRect	menu[4];
  int		(*ptr[4])(t_main *);
  int		i;
  int		ret;

  ret = 0;
  while (sfRenderWindow_pollEvent(core->window, event))
    {
      if (event->type == sfEvtClosed || (event->type == sfEvtKeyPressed &&
					 event->key.code == sfKeyEscape))
	sfRenderWindow_close(core->window);
      if (event->type == sfEvtMouseButtonPressed &&
	  sfMouse_isButtonPressed(sfMouseLeft))
	{
	  getrectmenu(menu);
	  initmenuptr(ptr);
	  i = -1;
	  while (++i < 4)
	    if (sfIntRect_contains(&menu[i], event->mouseButton.x,
				   event->mouseButton.y))
	      ret = ptr[i](core);
	}
    }
  return (ret);
}

void	getcompare(int *compare)
{
  compare[0] = sfMouseLeft;
  compare[1] = sfMouseRight;
  compare[2] = sfKeyLeft;
  compare[3] = sfKeyRight;
  compare[4] = sfKeyEscape;
  compare[5] = sfKeyUp;
  compare[6] = sfKeyDown;
}

int	event_edit_menu_curl(t_main *core, sfEvent *event,
			     t_editor *resource, int param[2])
{
  int	compare[PTREDIT];
  int	(*ptr[PTREDIT])(t_main *, int *, t_editor *);
  int	i;
  int	ret;

  getcompare(compare);
  initeditptr(ptr);
  ret = 0;
  i = -1;
  while (++i < 2 && event->type == sfEvtMouseButtonPressed)
    if (sfMouse_isButtonPressed(compare[i]))
      ret = ptr[i](core, param, resource);
  i = 1;
  while (++i < PTREDIT && event->type == sfEvtKeyPressed)
    if (sfKeyboard_isKeyPressed(compare[i]))
      ret = ptr[i](core, param, resource);
  return (ret);
}

int	event_edit_menu(t_main *core, sfEvent *event, t_editor *resource,
			int param[2])
{
  int	ret;

  ret = 1;
  while (sfRenderWindow_pollEvent(core->window, event))
    {
      if (event->type == sfEvtClosed)
	sfRenderWindow_close(core->window);
      if (event->type != sfEvtMouseButtonPressed &&
	  event->type != sfEvtKeyPressed)
	return (ret);
      ret = event_edit_menu_curl(core, event, resource, param);
      if (ret == 1 && param[0] == 2)
	ret = edit_sub_sprite(core, resource, event);
    }
  return (ret);
}

