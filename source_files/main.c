/*
** main.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure/source_files
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Tue Mar 28 16:27:31 2017 Corentin LEROY
** Last update Thu Apr 13 00:06:32 2017 Corentin LEROY
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "main.h"

t_main		*prepare_mainstruct()
{
  t_main	*ret;

  if (!(ret = malloc(sizeof(*ret))))
    return (NULL);
  if ((ret->window = open_window("Tek Adventure", 1280, 720)) == 0 ||
      !(ret->fonts = init_fonts()) ||
      !(ret->options = init_options(50, 50, 50)) ||
	  !(ret->layout = get_pictures("resources/pictures/layout")))
    return (NULL);
  ret->cur_background = NULL;
  return (ret);
}

void	delete_mainstructure(t_main *core)
{
  sfRenderWindow_destroy(core->window);
  sfFont_destroy(core->fonts[0]);
  sfFont_destroy(core->fonts[1]);
  sfMusic_stop(core->cur_background);
  sfMusic_destroy(core->cur_background);
  free_pictures(core->layout);
  free(core->fonts);
  free(core->options);
  free(core);
}

int		main()
{
  t_main	*core;
  int		ret;

  if (!(core = prepare_mainstruct()))
    return (84);
  if ((ret = loading_screen(core)) != 84)
	ret = main_menu(core);
  delete_mainstructure(core);
  return (ret);
}
