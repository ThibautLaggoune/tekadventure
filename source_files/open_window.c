/*
** open_window.c for  in /home/thibaut/delivery/Semestre_2/MUL/2/tekadventure/
** 
** Made by thibaut
** Login   <thibaut.laggoune@epitech.eu@epitech.net>
** 
** Started on  Tue Mar 28 14:16:17 2017 thibaut
** Last update Tue Mar 28 16:10:59 2017 thibaut
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfRenderWindow		*open_window(char *name, int width, int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfClose, NULL);
  if (window == NULL)
    return (NULL);
  return (window);
}
