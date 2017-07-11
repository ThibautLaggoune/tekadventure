/*
** pick_drop.c for  in /home/thibaut/delivery/Semestre_2/MUL/tekadventure
** 
** Made by thibaut
** Login   <thibaut.laggoune@epitech.eu@epitech.net>
** 
** Started on  Thu May 25 16:20:22 2017 thibaut
** Last update Sun May 28 02:00:53 2017 Corentin LEROY
*/

#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>
#include "headers.h"
#include "main.h"
#include "macro.h"
#include "my.h"

int		display_save(t_main *core)
{
  int		i;
  int		**tmp;
  sfVector2f	pos;
  t_chara	**image;

  i = 0;
  if (core->resource->save->move_areas)
    display_rect_from_intrect(core, core->resource->save->move_areas,
			      sfGreen);
  if ((tmp = core->resource->save->chara_locations) == NULL)
    return (0);
  image = core->resource->save->characters;
  while (image[i] != NULL)
    {
      pos = getv2f(tmp[i][0], tmp[i][1]);
      sfSprite_setPosition(image[i]->body->sprite, pos);
      sfRenderWindow_drawSprite(core->window, image[i]->body->sprite, NULL);
      i++;
    }
  return (1);
}

t_picture	*pick_sprite(t_main *core, sfEvent *event, t_picture **image,
			     int *s_chara)
{
  int           i;
  int           size;
  int           cont_chara;
  sfIntRect	rect;

  size = 0;
  while (image[size])
    size += 1;
  if (size > NBSPRITE)
    size = NBSPRITE;
  i = 0;
  cont_chara = s_chara[0] * SPRITE_PER_LINE + s_chara[s_chara[0] + 1];
  rect = getintrect(SHEIGHT - core->layout[0]->size.y, 0, 100, 100);
  while (image[i + cont_chara] &&
	 image[i + cont_chara]->size.x * (i + 1) < SWIDTH)
    {
      rect.left = (SWIDTH - (size * 100)) / (size + 1) * (i + 1) + i * 100;
      if (sfIntRect_contains(&rect, event->mouseButton.x,
			     event->mouseButton.y))
	return (image[i + cont_chara]);
      i++;
    }
  return (NULL);
}

int	save_pos(t_map *map, t_chara *chara)
{
  int	**tmp;
  int	*tmp_int;
  int	i;

  i = 0;
  while (map->chara_locations && map->chara_locations[i])
    i++;
  if (!(tmp_int = malloc(sizeof(int) * 2)) ||
      !(tmp = malloc(sizeof(int *) * (i + 2))))
    return (84);
  tmp_int[0] = chara->pos.x;
  tmp_int[1] = chara->pos.y;
  i = 0;
  while (map->chara_locations && map->chara_locations[i])
    {
      tmp[i] = map->chara_locations[i];
      i++;
    }
  tmp[i] = tmp_int;
  tmp[i + 1] = NULL;
  if (map->chara_locations)
    free(map->chara_locations);
  map->chara_locations = tmp;
  return (1);
}

int		save_map(t_editor *resource, t_chara *chara)
{
  t_map		*map;
  t_chara	**tmp;
  int		i;

  i = 0;
  map = resource->save;
  if (map->characters)
    while (map->characters[i])
      i++;
  if ((tmp = malloc(sizeof(t_chara*) * (i + 2))) == NULL)
    return (84);
  i = 0;
  if (map->characters)
    while (map->characters[i] != NULL)
      {
	tmp[i] = map->characters[i];
	i++;
      }
  tmp[i] = chara;
  tmp[i + 1] = NULL;
  save_pos(resource->save, chara);
  if (map->characters)
    free(map->characters);
  map->characters = tmp;
  return (1);
}

int		drop_sprite(t_main *core, sfEvent *event, t_picture *tmp)
{
  t_chara	*chara;

  if ((chara = malloc(sizeof(*chara))) == NULL)
    return (84);
  chara->body = tmp;
  chara->pos.x = event->mouseButton.x - 50;
  chara->pos.y = event->mouseButton.y - 50;
  chara->size = tmp->size;
  save_map(core->resource, chara);
  sfSprite_setPosition(chara->body->sprite, chara->pos);
  sfRenderWindow_drawSprite(core->window, chara->body->sprite, NULL);
  sfRenderWindow_display(core->window);
  return (1);
}
