/*
** fill_map_struct_pictures.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Tue May 23 01:06:58 2017 Corentin LEROY
** Last update Tue May 23 01:18:27 2017 Corentin LEROY
*/

#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>
#include "headers.h"
#include "print.h"
#include "main.h"
#include "my.h"

int	fill_id(t_map *map, char **buff, int *i)
{
  (void)map;
  if (buff[*i])
    {
      *i += 1;
      return (1);
    }
  return (0);
}

int		fill_music(t_map *map, char **buff, int *i)
{
  t_sound	*ret;
  char		*path;

  if (buff[*i] && buff[*i][0] == '\t')
    {
      if (!(ret = malloc(sizeof(*ret))))
	return (-1);
      path = "resources/sound/musics/";
      if (!(ret->name = my_sprintf("%s%s", path, buff[*i] + 1)))
	return (-1);
      if (!(ret->music = sfMusic_createFromFile(ret->name)))
	return (-1);
      map->musical_theme = ret;
      *i += 1;
      return (1);
    }
  return (0);
}

int		fill_background(t_map *map, char **buff, int *i)
{
  t_picture	*ret;
  char		*path;

  if (!(map->backgrounds = malloc(sizeof(map->backgrounds) * 3)))
	return (-1);
  if (buff[*i] && buff[*i][0] == '\t')
    {
      path = "resources/pictures/backgrounds";
      if (!(ret = set_texture(getv2f(1, 1), path, buff[*i] + 1)))
	return (-1);
      map->backgrounds[0] = ret;
      map->backgrounds[1] = NULL;
      map->backgrounds[2] = NULL;
	  sfSprite_setPosition(ret->sprite, getv2f(0, 0));
      *i += 1;
      return (1);
    }
  return (0);
}

int		fill_parallax(t_map *map, char **buff, int *i)
{
  t_picture	*ret;
  char		*path;

  if (buff[*i] && buff[*i][0] == '\t')
    {
      path = "resources/pictures/parallax";
      if (!(ret = set_texture(getv2f(1, 1), path, buff[*i] + 1)))
	return (-1);
      map->backgrounds[1] = ret;
	  sfSprite_setPosition(ret->sprite, getv2f(0, 0));
      *i += 1;
      return (1);
    }
  return (0);
}
