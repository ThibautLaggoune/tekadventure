/*
** rectangle.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure/source_files
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Wed Apr 12 23:31:56 2017 Corentin LEROY
** Last update Wed Apr 12 23:31:57 2017 Corentin LEROY
*/

#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "macro.h"
#include "main.h"
#include "my.h"

sfIntRect	getintrect(int top, int left, int width, int height)
{
  sfIntRect	ret;

  ret.top = top;
  ret.left = left;
  ret.width = width;
  ret.height = height;
  return (ret);
}

void	getrectoptions(sfIntRect menu[4])
{
  menu[0] = getintrect(240, 300, 300, 10);
  menu[1] = getintrect(340, 300, 300, 10);
  menu[2] = getintrect(440, 300, 300, 10);
  menu[3] = getintrect(SHEIGHT / 2 + 140, 50, 170, 80);
}

void	getrectmenu(sfIntRect menu[4])
{
  menu[0] = getintrect(SHEIGHT / 2 - 160, 50, 122, 80);
  menu[1] = getintrect(SHEIGHT / 2 - 60, 50, 140, 80);
  menu[2] = getintrect(SHEIGHT / 2 + 40, 50, 160, 80);
  menu[3] = getintrect(SHEIGHT / 2 + 140, 50, 170, 80);
}

sfIntRect	*allocintrect(char *left, char *top, char *width, char *height)
{
  sfIntRect	*ret;

  if (!(ret = malloc(sizeof(*ret))))
	return (NULL);
  ret->top = my_getnbr(top);
  ret->left = my_getnbr(left);
  ret->width = my_getnbr(width);
  ret->height = my_getnbr(height);
  return (ret);
}

int		print_rectangle(sfVector2f tl, sfVector2i wh, sfColor color,
				sfRenderWindow *window)
{
  sfUint8	buff[wh.x * wh.y * 4];
  sfTexture	*texture;
  sfSprite	*sprite;
  int		i;

  i = -1;
  while (++i < wh.x * wh.y)
    {
      buff[i * 4] = color.r;
      buff[i * 4 + 1] = color.g;
      buff[i * 4 + 2] = color.b;
      buff[i * 4 + 3] = color.a;
    }
  if (!(texture = sfTexture_create(wh.x, wh.y)) ||
      !(sprite = sfSprite_create()))
    return (84);
  sfTexture_updateFromPixels(texture, buff, wh.x, wh.y, 0, 0);
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfSprite_setPosition(sprite, tl);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfTexture_destroy(texture);
  sfSprite_destroy(sprite);
  return (0);
}