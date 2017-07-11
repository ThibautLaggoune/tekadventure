/*
** getfiles.c for  in /home/thibaut/delivery/Semestre_2/MUL/tekadventure/source_files
** 
** Made by thibaut
** Login   <thibaut.laggoune@epitech.eu@epitech.net>
** 
** Started on  Wed Apr 19 14:03:46 2017 thibaut
** Last update Tue May 23 00:50:15 2017 Corentin LEROY
*/

#include <stdlib.h>
#include <dirent.h>
#include <SFML/Graphics.h>
#include "main.h"
#include "my.h"

char		**sort_tab(char **tab)
{
  int		i;
  char		*tmp;

  i = 1;
  while (tab[i] != NULL)
    {
      if (my_strcmp(tab[i], tab[i - 1]) == -1)
	{
	  tmp = tab[i - 1];
	  tab[i - 1] = tab[i];
	  tab[i] = tmp;
	  i = 0;
	}
      i += 1;
    }
  return (tab);
}

char		**get_files(char *path)
{
  char		**tab;
  int		i;
  DIR		*rep;
  struct dirent	*act_file;

  if ((rep = opendir(path)) == NULL)
    return (NULL);
  i = 0;
  while ((act_file = readdir(rep)))
    if (act_file->d_name[0] != '.')
      i += 1;
  closedir(rep);
  if (!(tab = malloc(sizeof(char *) * (i + 1))) || !(rep = opendir(path)))
    return (NULL);
  i = 0;
  while ((act_file = readdir(rep)))
    if (act_file->d_name[0] != '.')
      {
	if (!(tab[i] = my_strdup(act_file->d_name)))
	  return (NULL);
	i += 1;
      }
  tab[i] = NULL;
  closedir(rep);
  return (sort_tab(tab));
}
