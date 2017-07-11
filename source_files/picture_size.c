/*
** picture_size.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure/
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Thu May  4 19:46:58 2017 Corentin LEROY
** Last update Thu May  4 19:46:58 2017 Corentin LEROY
*/

#include <SFML/Graphics.h>

sfVector2f	get_size_from_bounds(sfSprite *sprite)
{
  sfVector2f	ret;
  sfFloatRect	rect;

  rect = sfSprite_getLocalBounds(sprite);
  ret.x = rect.width;
  ret.y = rect.height;
  return (ret);
}