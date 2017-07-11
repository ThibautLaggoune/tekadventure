/*
** get_arg.c for get arg in /home/leroyc/Delivery/PSU/
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Sun Nov 13 13:42:42 2016 Corentin LEROY
** Last update Thu Apr  6 15:27:04 2017 Corentin LEROY
*/

#include "print.h"

void	get_lenmod(char *arg, t_arg *ret)
{
  int	i;
  int	test;

  i = 0;
  test = -1;
  while (test == -1 &&  arg[i] != 0)
    {
      if ((arg[i] == 'l' || arg[i] == 'h' || arg[i] == 'j' ||
	   arg[i] == 'z' || arg[i] == 't') && arg[i + 1] != 0)
	test = 0;
      else
	i++;
    }
  test = ((test == 0 && arg[i] == 'l') ? (1) : (test));
  test = ((test == 1 && arg[i + 1] == 'l') ? (2) : (test));
  test = ((test == 0 && arg[i] == 'h') ? (3) : (test));
  test = ((test == 3 && arg[i + 1] == 'h') ? (4) : (test));
  test = ((test == 0 && arg[i] == 'j') ? (5) : (test));
  test = ((test == 0 && arg[i] == 'z') ? (6) : (test));
  test = ((test == 0 && arg[i] == 't') ? (7) : (test));
  ret->lenmod = ((test > 0) ? (test) : (0));
}

void	get_padpos(char *arg, t_arg *ret)
{
  int	i;
  int	test;

  i = -1;
  test = 0;
  while (test == 0 && arg[++i] != 0)
    if (arg[i] == '-')
      test = 1;
  if (test == 1)
    ret->pad_pos = 1;
}

void	get_sign(char *arg, t_arg *ret)
{
  int	i;
  int	test;

  i = -1;
  test = 0;
  while (test == 0 && arg[++i] != 0)
    if (arg[i] == '+')
      test = 1;
  i = -1;
  while (test == 0 && arg[++i] != 0)
    if (arg[i] == ' ')
      test = 2;
  ret->sign = test;
}

void	get_zerpad(char *arg, t_arg *ret)
{
  int	i;
  int	test;

  i = -1;
  if (ret->type == 'p')
    test = 1;
  else
    test = 0;
  while (test == 0 && arg[++i] != 0)
    if (arg[i] == '#')
      test = 1;
  ret->zerpad = test;
}
