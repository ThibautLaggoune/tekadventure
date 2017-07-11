/*
** my_disptab.c for my disp tab in /home/leroyc/Delivery/LIB/lib/my
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Mon Nov 28 11:02:37 2016 Corentin LEROY
** Last update Thu Apr  6 10:21:52 2017 Corentin LEROY
*/

#include "my.h"

void	my_disptab(char **tab)
{
  int	i;

  i = -1;
  if (tab)
    {
      while (tab[++i])
	{
	  my_putstr(tab[i]);
	  my_putchar('\n');
	}
    }
}
