/*
** fill_map_struct_chara.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Wed May 24 23:36:56 2017 Corentin LEROY
** Last update Fri May 26 15:23:37 2017 Corentin LEROY
*/

#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>
#include "headers.h"
#include "print.h"
#include "macro.h"
#include "main.h"
#include "my.h"

t_chara		*get_chara(char *buff)
{
  char		**tmp;
  t_chara	*ret;
  sfVector2f	size;

  if (!(tmp = str_wt(buff, '\t')) ||
      my_tablen(tmp) != 2 || !(ret = malloc(sizeof(*ret))) ||
      !(ret->body = set_texture(getv2f(1, 1), ".", tmp[1])))
    return (NULL);
  my_free_tab(tmp);
  if (!(tmp = str_wt(buff, ' ')) || my_tablen(tmp) != 2)
    return (NULL);
  size.x = my_getnbr(tmp[0]);
  size.y = my_getnbr(tmp[1]);
  my_free_tab(tmp);
  ret->body->resize.x = (float)(size.x / ret->body->size.x);
  ret->body->resize.y = (float)(size.y / ret->body->size.y);
  ret->body->size = size;
  sfSprite_setScale(ret->body->sprite, ret->body->resize);
  ret->size = size;
  ret->dir = 0;
  sfSprite_setPosition(ret->body->sprite, getv2f(-SWIDTH, -SHEIGHT));
  return (ret);
}

int		fill_chara(t_map *map, char **buff, int *i)
{
  t_chara	**tmp;
  int		j;
  int		k;

  j = 0;
  map->characters = NULL;
  while (buff[*i] && buff[*i][0] == '\t')
    {
      j += 1;
      if (!(tmp = malloc(sizeof(*tmp) * (j + 1))) ||
	  !(tmp[j - 1] = get_chara(buff[*i] + 1)))
	return (-1);
      k = 0;
      while (map->characters && map->characters[k])
	{
	  tmp[k] = map->characters[k];
	  k += 1;
	}
      tmp[k + 1] = NULL;
      free(map->characters);
      map->characters = tmp;
      *i += 1;
    }
  return (j);
}

int	*get_charapos(char *buff)
{
  char	**tmp;
  int	*ret;

  if (!(tmp = str_wt(buff, ' ')))
    return (NULL);
  if (my_tablen(tmp) != 4 || !(ret = malloc(sizeof(*ret) * 4)))
    return (NULL);
  ret[0] = my_getnbr(tmp[0]);
  ret[1] = my_getnbr(tmp[1]);
  ret[2] = my_getnbr(tmp[2]);
  ret[3] = my_getnbr(tmp[3]);
  my_free_tab(tmp);
  return (ret);
}

int	fill_charapos(t_map *map, char **buff, int *i)
{
  int	**tmp;
  int	j;
  int	k;

  j = 0;
  map->chara_locations = NULL;
  while (buff[*i] && buff[*i][0] == '\t')
    {
      j += 1;
      if (!(tmp = malloc(sizeof(*tmp) * (j + 1))) ||
	  !(tmp[j - 1] = get_charapos(buff[*i] + 1)))
	return (-1);
      k = 0;
      while (map->chara_locations && map->chara_locations[k])
	{
	  tmp[k] = map->chara_locations[k];
	  k += 1;
	}
      tmp[k + 1] = NULL;
      free(map->chara_locations);
      map->chara_locations = tmp;
      *i += 1;
    }
  return (j);
}

int		fill_charatext(t_map *map, char **buff, int *i)
{
  sfText	**tmp;
  int		j;
  int		k;

  j = 0;
  map->script_text = NULL;
  while (buff[*i] && buff[*i][0] == '\t')
    {
      j += 1;
      if (!(tmp = malloc(sizeof(*tmp) * (j + 1))) ||
	  !(tmp[j - 1] = sfText_create()))
	return (-1);
      sfText_setString(tmp[j - 1], buff[*i] + 1);
      k = 0;
      while (map->script_text && map->script_text[k])
	{
	  tmp[k] = map->script_text[k];
	  k += 1;
	}
      tmp[k + 1] = NULL;
      free(map->script_text);
      map->script_text = tmp;
      *i += 1;
    }
  return (j);
}
