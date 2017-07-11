/*
** my_free_tab.c for  in /home/leroyc/Delivery/PSU/
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Mon Nov 28 10:10:22 2016 Corentin LEROY
** Last update Tue Apr 18 13:18:52 2017 Corentin LEROY
*/

#include <stdlib.h>
#include "my.h"

void	my_free_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i])
    free(tab[i]);
  free(tab[i]);
  free(tab);
}
