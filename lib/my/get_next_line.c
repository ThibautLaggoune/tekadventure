/*
** get_next_line.c for main in /home/leroyc/Delivery/2016/B1/CPE/Bootstrap/
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Tue Jan  3 09:15:31 2017 Corentin LEROY
** Last update Tue Apr 18 13:25:45 2017 Corentin LEROY
*/

#include <unistd.h>
#include <stdlib.h>

static char	*gnl_get_the_line(char *str)
{
  int		i;
  char		*ret;
  int		size;

  size = 0;
  if (str == NULL)
    return (NULL);
  while (str[size] && str[size] != '\n')
    size++;
  if (!(ret = malloc(size + 1)))
    return (NULL);
  i = 0;
  while (str[i] && str[i] != '\n')
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = 0;
  return (ret);
}

static int	gnl_is_a_line(char *str, int state)
{
  int		i;

  if (state == 0)
    return (1);
  if (str == NULL)
    return (0);
  i = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	return (1);
      i++;
    }
  return (0);
}

static char	*gnl_add_to_mem(char *str, char new)
{
  int		size;
  int		i;
  char		*ret;

  size = 0;
  if (str != NULL)
    {
      while (str[size])
	size++;
    }
  if (!(ret = malloc(size + 2)))
    return (NULL);
  i = 0;
  while (i < size + 1)
    {
      if (size == i)
	ret[i] = new;
      else
	ret[i] = str[i];
      i++;
    }
  ret[i] = 0;
  free(str);
  return (ret);
}

char	*get_next_line(int fd)
{
  char	*mem;
  char	*ret;
  int	size;
  int	state;
  char	buff;

  mem = NULL;
  state = 1;
  while (gnl_is_a_line(mem, state) == 0)
    {
      if ((size = read(fd, &buff, 1)) == -1)
	return (NULL);
      else if (size == 0)
	state = 0;
      else
	{
	  if (!(mem = gnl_add_to_mem(mem, buff)))
	    return (NULL);
	}
    }
  if (!(ret = gnl_get_the_line(mem)))
    return (NULL);
  free(mem);
  return (ret);
}
