/*
** sprites.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Wed Apr 12 13:58:41 2017 Corentin LEROY
** Last update Tue May 23 15:25:34 2017 thibaut
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>
#include "headers.h"
#include "macro.h"
#include "print.h"
#include "main.h"
#include "my.h"

t_picture	*set_texture(sfVector2f scale, char *path, char *name)
{
  t_picture	*ret;
  char		*file;

  if (!(file = my_sprintf("%s/%s", path, name)))
    return (NULL);
  if (!(ret = malloc(sizeof(*ret))))
    return (NULL);
  if (!(ret->name = my_strdup(name)) || !(ret->path = my_strdup(path)))
    return (NULL);
  if (!(ret->texture = sfTexture_createFromFile(file, NULL)) ||
      !(ret->sprite = sfSprite_create()))
    return (NULL);
  free(file);
  sfSprite_setTexture(ret->sprite, ret->texture, sfTrue);
  ret->size = get_size_from_bounds(ret->sprite);
  ret->size.x *= scale.x;
  ret->size.y *= scale.y;
  ret->resize = scale;
  sfSprite_setScale(ret->sprite, scale);
  return (ret);
}

void		move_parallax_rtl(sfRenderWindow *window, t_picture *obj,
				  sfVector2f *move, float move_factor)
{
  sfVector2f	temp;

  move->x += move_factor;
  if (move->x + obj->size.x <= SWIDTH)
    {
      temp.x = move->x + obj->size.x;
      temp.y = move->y;
      sfSprite_setPosition(obj->sprite, temp);
      sfRenderWindow_drawSprite(window, obj->sprite, NULL);
      if (move->x < -obj->size.x)
	move->x = 0;
    }
  sfSprite_setPosition(obj->sprite, *move);
  sfRenderWindow_drawSprite(window, obj->sprite, NULL);
}
