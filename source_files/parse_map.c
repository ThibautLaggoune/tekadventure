/*
** parse_map.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure/source_files
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Mon May 22 11:18:10 2017 Corentin LEROY
** Last update Mon May 29 00:56:03 2017 thibaut
*/

#include <SFML/Graphics.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "headers.h"
#include "print.h"
#include "main.h"
#include "my.h"

int	check_id(int fd, int id)
{
  int	size;
  char	prebuff[5];
  char	*buff;

  prebuff[4] = 0;
  if ((size = read(fd, prebuff, 4)) == -1)
    return (84);
  else if (size != 4 || my_strcmp("id\n\t", prebuff) != 0)
    return (0);
  if (!(buff = get_next_line(fd)))
    return (84);
  if (my_str_isnum(buff) == 0 || my_getnbr(buff) != id)
    return (0);
  free(buff);
  return (1);
}

t_map	*parse_map(int id, char *name)
{
  int	i;
  int	fd;
  int	size;
  t_map	*ret;
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
  if (!(ret = fill_map_struct(id, buff)))
    return (NULL);
  return (ret);
}

t_map	*get_map(int id, char **files, char *folder_name)
{
  t_map	*ret;
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
      if (check_id(fd, id) == 1)
	test = 0;
      else
	free(name);
      close(fd);
      i++;
    }
    my_free_tab(files);
  if (!test && !(ret = parse_map(id, name)))
      return (NULL);
  return (ret);
}

void	unparse_map(t_main *core, t_map *map)
{
  if (map)
    {
      if (map->musical_theme)
	{
	  free(map->musical_theme->name);
	  sfMusic_stop(map->musical_theme->music);
	  change_music(core, core->cur_background);
	  sfMusic_destroy(map->musical_theme->music);
	  free(map->musical_theme);
	}
      if (map->io_areas)
	free_inttab(map->io_areas);
      if (map->script_sound)
	free_musics(map->script_sound);
      if (map->move_areas)
	free_intrecttab(map->move_areas);
      free(map);
    }
}
