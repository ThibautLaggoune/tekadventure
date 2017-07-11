/*
** get_arg.c for get arg 2 in /home/leroyc/Delivery/PSU/
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Thu Nov 17 21:32:50 2016 Corentin LEROY
** Last update Fri Mar 24 14:03:06 2017 Corentin LEROY
*/

#include "print.h"

void	get_padsym(char *arg, t_arg *ret)
{
  int	i;
  int	test;

  i = -1;
  test = 0;
  while (test == 0 && arg[++i] != 0)
    if (arg[i] == '.')
      test = 1;
  i = -1;
  while (test == 0 && arg[++i] != 0)
    if (arg[i] == '0')
      test = 2;
  i--;
  if (test == 2)
    {
      if (!i || arg[i - 1] < 48 || arg[i - 1] > 57)
	ret->padsym = 1;
      else
	ret->padsym = 0;
    }
  else
    ret->padsym = 0;
  if (ret->type == 'p' || ret->type == 'c')
    ret->padsym = 0;
}

void	get_star(char *arg, t_arg *ret, va_list args)
{
  int	i;
  int	test;

  i = 0;
  test = 0;
  while (test == 0 && arg[i] != 0)
    test = ((arg[i++] == '*') ? (1) : (0));
  if (test == 1)
    ret->topad = va_arg(args, int);
  i = 0;
  test = 0;
  while (test == 0 && arg[++i] != 0)
    if (arg[i] == '.')
      test = 1;
  while (test == 1 && arg[++i] != 0)
    if (arg[i] == '*')
      test = 2;
  if (test == 2)
    ret->nbpre = va_arg(args, int);
}

void	get_nbpre_topad(char *arg, t_arg *ret, va_list args)
{
  int	i;
  int	test;

  i = 0;
  test = 0;
  while ((arg[i] < '0' || arg[i] > '9') && arg[i] != 0)
    i++;
  if (i == 0 || arg[i - 1] != '.')
    {
      while ('0' <= arg[i] && arg[i] <= '9')
	ret->topad = ret->topad * 10 + arg[i++] - 48;
      while (test == 0 && arg[i] != 0)
	test = ((arg[i++] == '.') ? (1) : (0));
    }
  else
    test = 1;
  while (test == 1 && '0' <= arg[i] && arg[i] <= '9')
    ret->nbpre = ret->nbpre * 10 + arg[i++] - 48;
  ret->nbpre = ((ret->nbpre == 0 && test == 1) ? (-1) :(ret->nbpre));
  get_star(arg, ret, args);
}
