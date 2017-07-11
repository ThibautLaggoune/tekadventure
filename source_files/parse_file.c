/*
** parse_file.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure/
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Tue Apr 25 14:05:27 2017 Corentin LEROY
** Last update Mon May 29 01:33:39 2017 thibaut
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "print.h"
#include "headers.h"
#include "main.h"
#include "my.h"

t_picture	**get_pictures(char *path)
{
  t_picture	**ret;
  char		**filelist;
  sfVector2f	scale;
  int		i;

  if (!(filelist = get_files(path)))
    return (NULL);
  if (!(ret = malloc(sizeof(*ret) * (my_tablen(filelist) + 1))))
    return (NULL);
  i = 0;
  scale = getv2f(1, 1);
  while (filelist[i])
    {
      if (!(ret[i] = set_texture(scale, path, filelist[i])))
	return (NULL);
      ret[i]->size = get_size_from_bounds(ret[i]->sprite);
      i += 1;
    }
  ret[i] = NULL;
  my_free_tab(filelist);
  return (ret);
}

void	sub_multi(t_picture *ret, sfVector2f size)
{
  ret->size = size;
  ret->resize = getv2f(2, 2);
  sfSprite_setScale(ret->sprite, ret->resize);
  sfSprite_setTexture(ret->sprite, ret->texture, sfTrue);
}

t_picture	**get_multi(char *path, int width, int height,
			    sfVector2f size)
{
  t_picture	**ret;
  sfVector2i	nbpic;
  sfIntRect	zone;
  int		i;

  nbpic = getv2i(width / size.x, height / size.y);
  if (!(ret = malloc(sizeof(*ret) * (nbpic.x * nbpic.y + 1))))
    return (NULL);
  i = -1;
  while (++i < nbpic.x * nbpic.y)
    {
      zone = getintrect(size.y * (i / nbpic.x), size.x * (i % nbpic.x),
			size.x, size.y);
      if (!(ret[i] = malloc(sizeof(**ret))) ||
	  !(ret[i]->path = my_strdup(path)) ||
	  !(ret[i]->name = my_sprintf("Monster %d", i + 1)) ||
	  !(ret[i]->texture = sfTexture_createFromFile(path, &zone)) ||
	  !(ret[i]->sprite = sfSprite_create()))
	return (NULL);
      sub_multi(ret[i], size);
    }
  ret[i] = NULL;
  return (ret);
}

t_sound		**get_musics(char *path)
{
  t_sound	**ret;
  char		**filelist;
  char		*name;
  int		i;

  if (!(filelist = get_files(path)))
    return (NULL);
  if (!(ret = malloc(sizeof(*ret) * (my_tablen(filelist) + 1))))
    return (NULL);
  i = 0;
  while (filelist[i])
    {
      if (!(name = my_sprintf("%s/%s", path, filelist[i])) ||
	  !(ret[i] = malloc(sizeof(**ret))) ||
	  !(ret[i]->music = sfMusic_createFromFile(name)))
	return (NULL);
      ret[i]->name = filelist[i];
      free(name);
      i += 1;
    }
  ret[i] = NULL;
  free(filelist);
  return (ret);
}

t_editor	*parse_files_editor()
{
  char		*path;
  t_editor	*ret;

  if (!(ret = malloc(sizeof(*ret))))
    return (NULL);
  if (!(ret->backgrounds = get_pictures("resources/pictures/backgrounds")))
    return (NULL);
  if (!(ret->icones = get_pictures("resources/pictures/sprites/icones")))
    return (NULL);
  if (!(ret->parallax = get_pictures("resources/pictures/parallax")))
    return (NULL);
  path = "resources/pictures/sprites/creatures/monsters.png";
  if (!(ret->creatures = get_multi(path, 990, 679, getv2f(110, 97))))
    return (NULL);
  path = "resources/pictures/sprites/characters/ff1-psp-sprites.png";
  if (!(ret->characters = get_multi(path, 973, 288, getv2f(36, 36))))
    return (NULL);
  if (!(ret->musics = get_musics("resources/sound/musics")))
    return (NULL);
  if (!(ret->sounds = get_musics("resources/sound/sounds")))
    return (NULL);
  if (!(ret->save = init_map(-1)))
    return (NULL);
  my_memset(&(ret->cur_state), 0, sizeof(ret->cur_state));
  return (ret);
}
