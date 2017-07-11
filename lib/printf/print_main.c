/*
** printf.c for  in /home/leroyc/Delivery/UnixSysteme/
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Wed Nov  9 10:55:34 2016 Corentin LEROY
** Last update Tue May 23 00:43:24 2017 Corentin LEROY
*/

#include <stdarg.h>
#include <stdlib.h>
#include "print.h"

char	*put_args(char *parsone, char *(**ftab)(va_list, char *),
		  va_list args)
{
  char	t;
  char	psym;
  char	*ret;
  t_arg	*arg;

  arg = get_arg_struct(parsone, args);
  arg->str = ftab[get_bflag(arg->type)](args, parsone);
  t = arg->type;
  if ((t != 's') && (t != 'S') && (t != 'c') && (t != '%'))
    {
      if (arg->nbpre != 0)
	arg->str = print_putprecision(arg->str, arg->nbpre);
      if (arg->sign != 0 && (t == 'i' || t == 'd' || t == 'p'))
	arg->str = print_putsign(arg->str, arg->sign);
      if (arg->zerpad != 0 && (t == 'o' || t == 'x' || t == 'X'))
	arg->str = print_putzerpad(arg->str, arg->type);
    }
  if ((t == 's' || t == 'S') && arg->nbpre != 0)
    arg->str = print_putsprecision(arg->str, arg->nbpre);
  psym = ((arg->type == 's') ? (0) : (arg->padsym));
  if (arg->topad != 0)
    arg->str = print_putpadding(arg->str, psym, arg->pad_pos, arg->topad);
  (ret = arg->str) ? free(arg) : free (arg);
  free(parsone);
  return (ret);
}

int	pre_buff(va_list args, char *str, char **parsone)
{
  int		i;
  int		j;
  int		size;
  char		*(*ftab[13])(va_list, char *);

  get_ftab(ftab);
  size = 0;
  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i++] != '%')
	size++;
      else
	{
	  while (str[i] != 0 && get_bflag(str[i]) == 12)
	    i++;
	  parsone[j] = put_args(parsone[j], ftab, args);
	  size += print_strlen(parsone[j++]);
	  i += ((str[i] == 0) ? (0) : (1));
	}
    }
  return (size);
}

void	print_bufferize(char *buff, char *str, char **tab)
{
  int	i;
  int	j;
  int	k;
  int	l;

  i = 0;
  j = 0;
  k = 0;
  while (str[i])
    {
      if (str[i++] != '%')
	buff[j++] = str[i - 1];
      else
	{
	  while (str[i] != 0 && get_bflag(str[i]) == 12)
	    i++;
	  l = 0;
	  while (tab[k][l])
	    buff[j++] = tab[k][l++];
	  k++;
	  i += ((str[i] == 0) ? (0) : (1));
	}
    }
  buff[j] = '\0';
}

char	*print_buffered(char *str, char **tab, int size)
{
  char	*buff;

  if ((buff = malloc(sizeof(char) * (size + 1))) == NULL)
    return (0);
  print_bufferize(buff, str, tab);
  print_free_tab(tab);
  return (buff);
}

int		my_printf(char *str, ...)
{
  va_list	args;
  char		*buff;
  char		**parsone;
  int		size;

  parsone = printf_towordtab(str);
  va_start(args, str);
  size = pre_buff(args, str, parsone);
  va_end(args);
  buff = print_buffered(str, parsone, size);
  print_infd(1, buff, size);
  free(buff);
  return (size);
}
