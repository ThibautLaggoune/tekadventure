/*
** play.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure/source_files
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Thu Apr 13 00:54:26 2017 Corentin LEROY
** Last update Sun May 28 22:17:02 2017 Corentin LEROY
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "headers.h"
#include "macro.h"
#include "main.h"

t_play		*init_play()
{
  t_play	*ret;
  char		*path;
  sfVector2f	size;

  size = getv2f(36, 36);
  path = "resources/pictures/sprites/characters/ff1-psp-sprites.png";
  if (!(ret = malloc(sizeof(*ret))) ||
      !(ret->characters = get_multi(path, 973, 288, size)))
    return (NULL);
  ret->cur_map = NULL;
  ret->size = getv2f(72, 72);
  ret->to_be.x = -SWIDTH;
  ret->to_be.y = -SHEIGHT;
  ret->cur_chara = 0;
  ret->cur_way = 5;
  ret->level = 0;
  return (ret);
}

void	unparse_play(t_play *var)
{
  free_pictures(var->characters);
  free(var);
}

int		play_menu(t_main *core)
{
  int		ret;
  t_play	*resource;

  ret = 0;
  while (sfRenderWindow_isOpen(core->window) && ret >= 0)
    {
      if (loading_screen(core))
	return (84);
      if (!(resource = init_play()))
	return (84);
      resource->chara_pos.x = -SWIDTH;
      resource->chara_pos.y = -SHEIGHT;
      if (ret == 0)
	ret = play_worldmap(core, resource, "saves/banaladventure", ret);
      else
	ret = play_map(core, resource, ret, "saves/banaladventure");
      if (ret == -2)
	{
	  unparse_play(resource);
	  return (84);
	}
      unparse_play(resource);
    }
  return (1);
}
