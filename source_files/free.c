/*
** free.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Fri Apr 28 11:20:36 2017 Corentin LEROY
** Last update Sat May 27 17:58:00 2017 Corentin LEROY
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "headers.h"

void	free_inttab(int **tab)
{
  int	i;

  i = 0;
  if (tab)
    {
      while (tab[i])
	{
	  free(tab[i]);
	  i += 1;
	}
      free(tab);
    }
}

void	free_intrecttab(sfIntRect **tab)
{
  int	i;

  i = 0;
  if (tab)
    {
      while (tab[i])
	{
	  free(tab[i]);
	  i += 1;
	}
      free(tab);
    }
}

void	free_pictures(t_picture **pics)
{
  int	i;

  i = 0;
  if (pics)
    {
      while (pics[i])
	{
	  sfSprite_destroy(pics[i]->sprite);
	  sfTexture_destroy(pics[i]->texture);
	  free(pics[i]->name);
	  free(pics[i]->path);
	  free(pics[i]);
	  i += 1;
	}
      free(pics);
    }
}

void	free_musics(t_sound **sounds)
{
  int	i;

  i = 0;
  if (sounds)
    {
      while (sounds[i])
	{
	  free(sounds[i]->name);
	  sfMusic_destroy(sounds[i]->music);
	  free(sounds[i]);
	  i += 1;
	}
      free(sounds);
    }
}

void	free_nodes(t_node **nodes)
{
  int	i;

  i = 0;
  if (nodes)
    {
      while (nodes[i])
	{
	  free(nodes[i]->name);
	  free(nodes[i]->nexts);
	  free(nodes[i]);
	  i += 1;
	}
      free(nodes);
    }
}
