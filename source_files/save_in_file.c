/*
** save_in_file.c for  in /home/thibaut/delivery/Semestre_2/MUL/tekadventure/source_files
** 
** Made by thibaut
** Login   <thibaut.laggoune@epitech.eu@epitech.net>
** 
** Started on  Sun May 28 19:34:56 2017 thibaut
** Last update Mon May 29 01:34:54 2017 thibaut
*/

#include <fcntl.h>
#include <unistd.h>
#include "print.h"
#include "macro.h"
#include "headers.h"
#include "my.h"

void		print_move(int fd, t_editor *resource)
{
  sfIntRect	**tmp;
  int		i;

  my_dprintf(fd, "%s\n", FILLMO);
  i = 0;
  if ((tmp = resource->save->move_areas) != NULL)
    {
      while (tmp[i])
	{
	  my_dprintf(fd, "\t%d %d %d %d\n", tmp[i]->left, tmp[i]->top,
		     tmp[i]->width, tmp[i]->height);
	  i++;
	}
    }
}

void		print_io(int fd, t_editor *resource)
{
  int		**tmp;
  int		i;

  my_dprintf(fd, "%s\n", my_strdup(FILLIO));
  i = 0;
  if ((tmp = resource->save->io_areas))
    while (tmp[i])
      {
	my_dprintf(fd, "\t%d %d %d %d %d %d\n", tmp[i][0], tmp[i][1],
		   tmp[i][2], tmp[i][3], tmp[i][4], 0);
	i++;
      }
}

void		print_npc(int fd, t_editor *resource)
{
  int		i;
  int		**tmp;
  t_chara	**bod;

  my_dprintf(fd, "%s\n", my_strdup(FILLPO));
  i = 0;
  if ((tmp = resource->save->chara_locations))
    while (tmp[i])
      {
	my_dprintf(fd, "\t%d %d %d %d\n", tmp[i][0], tmp[i][1], tmp[i][2],
		   tmp[i][3]);
	i++;
      }
  i = 0;
  my_dprintf(fd, "%s\n", my_strdup(FILLNP));
  if ((bod = resource->save->characters))
    while (bod[i])
      {
	my_dprintf(fd, "\t%d %d\t%s/%s\n", (int)bod[i]->body->size.x,
		   (int)bod[i]->body->size.y, bod[i]->body->path, bod[i]->body->name);
	i += 1;
      }
}

int		save_in_file(t_editor *resource)
{
  int		fd;
  t_sound	**tmp;
  int		i;

  if ((fd = open("save.teka", O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
    return (84);
  my_dprintf(fd, "%s\n\t%d\n", my_strdup(FILLID), resource->save->id_map);
  my_dprintf(fd, "%s\n\t%s\n", my_strdup(FILLMU), "town-pravoka.ogg");
  my_dprintf(fd, "%s\n\t%s\n", FILLBG, resource->save->backgrounds[0]->name);
  my_dprintf(fd, "%s\n\t%s\n", FILLPA, resource->save->backgrounds[1]->name);
  print_move(fd, resource);
  print_io(fd, resource);
  print_npc(fd, resource);
  my_dprintf(fd, "%s\n\t%s\n\t%s\n", FILLTE, "ohlala je suis en retard", "blo");
  i = 0;
  my_dprintf(fd, "%s\n", FILLSO);
  if ((tmp = resource->sounds))
    while (tmp[i])
      {
	my_dprintf(fd, "\t%s\n", tmp[i]->name);
	i++;
      }
  close(fd);
  return (1);
}
