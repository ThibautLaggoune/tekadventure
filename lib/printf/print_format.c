/*
** format.c for my format in /home/leroyc/Delivery/PSU/
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Fri Nov 18 13:22:11 2016 Corentin LEROY
** Last update Sun Apr  2 12:59:02 2017 Corentin LEROY
*/

#include <stdlib.h>
#include "print.h"

char	*print_putpadding(char *str, char padsym, char padpos, char topad)
{
  char	*ret;
  int	size;
  int	i;
  int	j;

  size = print_strlen(str);
  if (size >= topad)
    return (str);
  padsym = ((padsym == 1  && padpos == 0) ? ('0') : (' '));
  if ((ret = malloc(sizeof(char) * (topad + 1))) == NULL)
    return (NULL);
  print_memset(ret, padsym, topad + 1);
  j = ((padpos == 0) ? (topad - size) : (0));
  i = 0;
  while (str[i])
    ret[j++] = str[i++];
  i = ((padsym == '0') ? (0) : (i));
  j = 0;
  while (padsym == '0' && j == 0 && ret[i] != 0)
    j = ((ret[i++] == '-') ? (1) : (0));
  ret[i - 1] = ((padsym == '0' && j == 1) ? (padsym) : (ret[i - 1]));
  ret[0] = ((padsym == '0' && j == 1) ? ('-') : (ret[0]));
  free(str);
  return (ret);
}

char	*print_putzerpad(char *str, char type)
{
  char	*ret;
  int	size;
  int	i;
  int	j;

  j = print_strlen(str);
  size = ((type == 'o') ? (j + 1) : (j + 2));
  if ((ret = malloc(sizeof(char) * (size + 1))) == NULL)
    return (0);
  print_memset(ret, '0', size + 1);
  if (type == 'x' || type == 'X')
    ret[1] = ((type == 'x') ? ('x') : ('X'));
  i = 0;
  while (ret[i])
    i++;
  while (j > 0)
    ret[--i] = str[--j];
  free(str);
  return (ret);
}

char	*print_putsign(char *str, char sign)
{
  char	*ret;
  int	i;

  if (str[0] != '-')
    {
      i = -1;
      if ((ret = malloc(sizeof(char) * (print_strlen(str) + 2))) == NULL)
	return (NULL);
      while (str[++i])
	ret[i + 1] = str[i];
      ret[i + 1] = '\0';
      ret[0] = ((sign == 1) ? ('+') : (' '));
      free(str);
      return (ret);
    }
  else
    return (str);
}

char	*print_putprecision(char *str, int precision)
{
  int	strsize;
  char	*ret;
  int	i;

  i = 0;
  strsize = print_strlen(str);
  if (strsize >= precision)
    return (str);
  if ((ret = malloc(sizeof(char) * (precision + 1))) == NULL)
    return (0);
  print_memset(ret, '0', precision + 1);
  while (ret[i])
    i++;
  while (strsize > 0)
    {
      ret[--i] = str[--strsize];
    }
  return (ret);
}
