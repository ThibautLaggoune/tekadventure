/*
** utils.c for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Wed Apr 12 23:20:30 2017 Corentin LEROY
** Last update Fri Apr 28 11:49:47 2017 Corentin LEROY
*/

#include <stdlib.h>

void	my_memset(void *var, const char c, unsigned int nbr)
{
  char	*to_clean;

  to_clean = (char *)var;
  while (var && nbr)
    {
      nbr -= 1;
      *to_clean = c;
      to_clean++;
    }
}

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return (0);
  while (tab[i])
    {
      i += 1;
    }
  return (i);
}

void	my_free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i += 1;
    }
  free(tab);
}

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      i += 1;
    }
  return (i);
}

char    *my_strdup(char *str)
{
  int   i;
  char  *ret;

  if ((ret = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      ret[i] = str[i];
      i += 1;
    }
  ret[i] = '\0';
  return (ret);
}
