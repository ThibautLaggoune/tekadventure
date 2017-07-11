/*
** free_tab.c for  in /home/leroyc/Delivery/PSU/
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Mon Nov 28 10:10:22 2016 Corentin LEROY
** Last update Mon Nov 28 10:43:40 2016 Corentin LEROY
*/

#include <stdlib.h>
#include "print.h"

int	print_free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab[i]);
  free(tab);
  return (0);
}
