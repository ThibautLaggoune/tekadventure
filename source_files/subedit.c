/*
** subedit.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Thu May 25 23:46:02 2017 Corentin LEROY
** Last update Sat May 27 18:29:49 2017 thibaut
*/

#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>
#include "headers.h"
#include "macro.h"
#include "main.h"
#include "my.h"

int		draw_image(t_main *core, t_picture **image, int *s_chara)
{
  int		i;
  int		size;
  int		shift;
  sfVector2f	pos;
  sfVector2f	scale;

  size = 0;
  while (image[++size]);
  if (size > NBSPRITE)
    size = NBSPRITE;
  i = -1;
  pos.y = SHEIGHT - 140;
  shift = s_chara[0] * SPRITE_PER_LINE + s_chara[s_chara[0] + 1];
  sfRenderWindow_drawSprite(core->window, core->layout[0]->sprite, NULL);
  while (image[++i + shift] && image[i + shift]->size.x * (i + 1) < SWIDTH)
    {
      pos.x = (SWIDTH - (size * 100)) / (size + 1) * (i + 1) + i * 100;
      scale = getv2f(100 / image[i + shift]->size.x,
		     100 / image[i + shift]->size.y);
      sfSprite_setScale(image[i + shift]->sprite, scale);
      sfSprite_setPosition(image[i + shift]->sprite, pos);
      sfRenderWindow_drawSprite(core->window, image[i + shift]->sprite, 0);
      scale = getv2f(1 / scale.x, 1 / scale.y);
    }
  return (1);
}

int		draw_icone_monsters(t_main *core, t_editor *resource)
{
  int           ret;
  sfEvent       event;
  int           s_chara[5];

  ret = 1;
  my_memset(s_chara, 0, sizeof(int) * 5);
  s_chara[4] = -1;
  while (sfRenderWindow_isOpen(core->window) && ret == 1)
    {
      my_memset(&event, 0, sizeof(event));
      sfRenderWindow_drawSprite(core->window, core->layout[0]->sprite, NULL);
      draw_image(core, resource->creatures, s_chara);
      sfRenderWindow_display(core->window);
      ret = 0;
      while (ret == 0 && sfRenderWindow_isOpen(core->window))
	{
	  ret = event_icone_chara(core, resource->creatures, &event, s_chara);
	  if (ret == 84)
	    return (84);
	}
    }
  if (ret == 2)
    ret = 1;
  return (ret);
}

int		draw_icone_chara(t_main *core, t_editor *resource)
{
  int		ret;
  sfEvent	event;
  int		s_chara[10];

  ret = 1;
  my_memset(s_chara, 0, sizeof(int) * 10);
  s_chara[9] = -1;
  while (sfRenderWindow_isOpen(core->window) && ret == 1)
    {
      my_memset(&event, 0, sizeof(event));
      sfRenderWindow_drawSprite(core->window, core->layout[0]->sprite, NULL);
      draw_image(core, resource->characters, s_chara);
      sfRenderWindow_display(core->window);
      ret = 0;
      while (ret == 0 && sfRenderWindow_isOpen(core->window))
	{
	  ret = event_icone_chara(core, resource->characters, &event, s_chara);
	  if (ret == 84)
	    return (84);
	}
    }
  if (ret == 2)
    ret = 1;
  return (ret);
}

void	initiconeptr(int (**ptr)())
{
  ptr[0] = draw_icone_chara;
  ptr[1] = draw_icone_monsters;
  ptr[2] = draw_icone_move_area;
  ptr[3] = draw_icone_chara;
  ptr[4] = draw_icone_chara;
}

int	edit_sub_sprite(t_main *core, t_editor *resource, sfEvent *event)
{
  sfIntRect	rect;
  int		(*ptr[NBICONE])(t_main*, t_editor*);
  int		ret;
  int		i;

  rect = getintrect(SHEIGHT - 140, 0, 100, 100);
  ret = 0;
  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
    return (2);
  initiconeptr(ptr);
  if (event->type == sfEvtMouseButtonPressed &&
      sfMouse_isButtonPressed(sfMouseLeft))
    {
      i = 0;
      while (resource->icones[i])
	{
	  rect.left = (SWIDTH - NBICONE * 100) / (NBICONE + 1) * (i + 1);
	  rect.left += i * 100;
	  if (sfIntRect_contains(&rect, event->mouseButton.x,
				 event->mouseButton.y))
	    ret = ptr[i](core, resource);
	  i++;
	}
    }
  return (ret);
}
