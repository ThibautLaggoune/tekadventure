/*
** print_draw_rect_ma.c for  in /home/thibaut/delivery/Semestre_2/MUL/tekadveture
** 
** Made by thibaut
** Login   <thibaut.laggoune@epitech.eu@epitech.net>
** 
** Started on  Sat May 27 20:06:10 2017 thibaut
** Last update Sun May 28 01:54:34 2017 Corentin LEROY
*/

#include "main.h"
#include "headers.h"
#include "macro.h"

int	print_draw_rect_ma(t_main *core)
{
  sfRenderWindow_drawSprite(core->window, core->layout[0]->sprite, NULL);
  print_rectangle(getv2f(50, SHEIGHT - (int)core->layout[0]->size.y + 50),
		  getv2i(100, 100), sfGreen, core->window);
  print_rectangle(getv2f(200, SHEIGHT - (int)core->layout[0]->size.y + 50),
		  getv2i(100, 100), sfRed, core->window);
  sfRenderWindow_display(core->window);
  return (0);
}
