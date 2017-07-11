/*
** text.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure/source_files
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Tue Apr  4 14:35:53 2017 Corentin LEROY
** Last update Fri Apr 28 11:49:21 2017 Corentin LEROY
*/

#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>
#include "headers.h"
#include "macro.h"
#include "main.h"

void	text_destroy(sfText *t1, sfText *t2, sfText *t3, sfText *t4)
{
  if (!t1)
    sfText_destroy(t1);
  if (!t2)
    sfText_destroy(t2);
  if (!t3)
    sfText_destroy(t3);
  if (!t4)
    sfText_destroy(t4);
}

void		display_text(t_main *core, sfText *to_disp)
{
  sfVector2f	pos;

  if (to_disp)
  {
  pos = getv2f(0, SHEIGHT - (int)core->layout[0]->size.y);
  sfSprite_setPosition(core->layout[0]->sprite, pos);
  sfRenderWindow_drawSprite(core->window, core->layout[0]->sprite, NULL);
  pos = getv2f(20, SHEIGHT - (int)core->layout[0]->size.y + 30);
  sfText_setFont(to_disp, core->fonts[1]);
  sfText_setPosition(to_disp, pos);
  sfRenderWindow_drawText(core->window, to_disp, NULL);
  sfRenderWindow_display(core->window);
  }
}

sfText		*create_new_text(char *text, sfColor color, sfFont *font,
				 int size)
{
  sfText	*ret;

  if ((ret = sfText_create()) == NULL)
    return (NULL);
  sfText_setString(ret, text);
  sfText_setFont(ret, font);
  sfText_setColor(ret, color);
  sfText_setCharacterSize(ret, size);
  return (ret);
}

sfFont		**init_fonts()
{
  sfFont	**fonts;

  fonts = malloc(sizeof(*fonts) * 2);
  if (fonts == NULL)
    return (NULL);
  fonts[0] = sfFont_createFromFile("resources/fonts/menu-font.ttf");
  if (fonts[0] == NULL)
    return (NULL);
  fonts[1] = sfFont_createFromFile("resources/fonts/text-font.ttf");
  if (fonts[1] == NULL)
    return (NULL);
  return (fonts);
}
