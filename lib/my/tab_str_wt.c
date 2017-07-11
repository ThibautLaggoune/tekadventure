/*
** tab_str_wt.c for  in /home/leroyc/Delivery/2016/B1/PSU/PSU_2016_minishell1
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Wed Jan  4 09:31:11 2017 Corentin LEROY
** Last update Tue Apr 18 13:27:16 2017 Corentin LEROY
*/

#include <stdlib.h>
#include "my.h"

static int	wt_cwords(char *str, char sep)
{
  int		i;
  int		mem;
  int		ret;

  if (!str)
    return (0);
  i = 0;
  ret = 0;
  while (str[i])
    {
      while (str[i] && str[i] == sep)
	i++;
      mem = i;
      while (str[i] && str[i] != sep)
	i++;
      if (i != mem)
	ret++;
    }
  return (ret);
}

static char	*wt_forward(char *str, int j, char sep, int k)
{
  char		*ret;
  int		i;

  i = 0;
  if (k == 0 || !(ret = malloc(k + 1)))
    return (NULL);
  while (i < k && str[i + j - k] && str[i + j - k] != sep)
    {
      ret[i] = str[i + j - k];
      i++;
    }
  ret[i] = 0;
  return (ret);
}

char	**str_wt(char *str, char sep)
{
  char	**ret;
  int	count;
  int	i;
  int	j;
  int	k;

  if (!(count = wt_cwords(str, sep)) ||
      !(ret = malloc(sizeof(char *) * (count + 1))))
    return (NULL);
  i = -1;
  j = 0;
  while (++i < count && str[j])
    {
      while (str[j] && str[j] == sep)
	j++;
      k = j;
      while (str[j] && str[j] != sep)
	j++;
      if (!(ret[i] = wt_forward(str, j, sep, j - k)))
	return (NULL);
    }
  ret[i] = NULL;
  return (ret);
}
