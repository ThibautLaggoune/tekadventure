/*
** t_args.c for t_arg in /home/leroyc/Delivery/PSU/
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Sun Nov 20 15:07:48 2016 Corentin LEROY
** Last update Sun Nov 20 15:08:48 2016 Corentin LEROY
*/

#include <stdlib.h>
#include "print.h"

void	init_targ(t_arg *ret, char *arg)
{
  int	i;
  char	tmp;

  i = 0;
  ret->pad_pos = 0;
  ret->sign = 0;
  ret->padsym = 0;
  ret->zerpad = 0;
  ret->topad = 0;
  ret->nbpre = 0;
  ret->lenmod = 0;
  while (arg[i])
    i++;
  tmp = arg[i - 1];
  ret->type = tmp;
  ret->base = ((tmp == 'p' || tmp == 'x') ? (3) : (0));
  ret->base = ((tmp == 'X') ? (4) : (ret->base));
  ret->base = ((tmp == 'o') ? (1) : (ret->base));
  ret->base = ((tmp == 'b') ? (2) : (ret->base));
}

t_arg	*get_arg_struct(char *arg, va_list args)
{
  t_arg	*ret;

  if ((ret = malloc(sizeof(*ret))) == NULL)
    return (0);
  init_targ(ret, arg);
  get_padpos(arg, ret);
  get_sign(arg, ret);
  get_zerpad(arg, ret);
  get_padsym(arg, ret);
  get_nbpre_topad(arg, ret, args);
  get_lenmod(arg, ret);
  return (ret);
}
