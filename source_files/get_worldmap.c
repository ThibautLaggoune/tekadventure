/*
** get_worldmap.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Sat May 27 11:35:49 2017 Corentin LEROY
** Last update Sat May 27 11:35:50 2017 Corentin LEROY
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "headers.h"
#include "main.h"
#include "print.h"
#include "my.h"

t_world	*parse_worldmap(char *name)
{
  int	i;
  int	fd;
  int	size;
  t_world	*ret;
  char	**buff;

  if (!(size = my_filelenght(name)) ||
      !(buff = malloc(sizeof(char *) * (size + 1))) ||
      !(fd = open(name, O_RDONLY)))
    return (NULL);
  i = 0;
  while ((buff[i] = get_next_line(fd)))
    i += 1;
  close(fd);
  free(name);
  if (i != size)
    {
      my_free_tab(buff);
      return (NULL);
    }
  if (!(ret = fill_worldmap_struct(buff)))
    return (NULL);
  return (ret);
}

t_world	*get_worldmap(char **files, char *folder_name)
{
  t_world  *ret;
  char	*name;
  int	test;
  int	fd;
  int	i;

  i = 0;
  test = 1;
  ret = NULL;
  while (files[i] && test)
    {
      if (!(name = my_sprintf("%s/%s", folder_name, files[i])) ||
	  (fd = open(name, O_RDONLY)) == -1)
	return (NULL);
      if (check_id(fd, 0) == 1)
	test = 0;
      else
	free(name);
      close(fd);
      i++;
    }
  if (!test)
    if (!(ret = parse_worldmap(name)))
      return (NULL);
  return (ret);
}

void	unparse_worldmap(t_main *core, t_world *map)
{
  if (map)
    {
      if (map->music)
	{
	  free(map->music->name);
	  sfMusic_stop(map->music->music);
	  change_music(core, core->cur_background);
	  sfMusic_destroy(map->music->music);
	  free(map->music);
	}
      if (map->list)
	free_nodes(map->list);
      free(map);
    }
}
