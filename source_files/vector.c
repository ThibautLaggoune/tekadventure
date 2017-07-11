/*
** vector.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Wed Apr 12 16:11:32 2017 Corentin LEROY
** Last update Wed Apr 12 16:11:33 2017 Corentin LEROY
*/

#include <SFML/System/Vector2.h>

sfVector2f	getv2f(float x, float y)
{
  sfVector2f	ret;

  ret.x = x;
  ret.y = y;
  return (ret);
}

sfVector2i	getv2i(int x, int y)
{
  sfVector2i	ret;

  ret.x = x;
  ret.y = y;
  return (ret);
}
