/*
** loading.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure/
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Tue May  9 11:13:07 2017 Corentin LEROY
** Last update Tue May  9 11:15:42 2017 Corentin LEROY
*/

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include "headers.h"
#include "macro.h"
#include "main.h"

int		loading_screen(t_main *core)
{
  sfText	*load;
  sfVector2f	pos;

  if (!(load = create_new_text("LOADING...", sfBlack, core->fonts[0], 80)))
    return (84);
  pos.x = SWIDTH / 2 - 100;
  pos.y = SHEIGHT / 2 - 30;
  sfText_setPosition(load, pos);
  sfRenderWindow_clear(core->window, sfWhite);
  sfRenderWindow_drawText(core->window, load, NULL);
  sfRenderWindow_display(core->window);
  return (0);
}
