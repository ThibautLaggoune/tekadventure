/*
** my_strisalpha.c for my_strisalpha in /home/XIII/delivery/CPool_Day06
** 
** Made by Corentin LEROY
** Login   <XIII@epitech.net>
** 
** Started on  Tue Oct 11 21:42:19 2016 Corentin LEROY
** Last update Mon May 22 21:18:34 2017 Corentin LEROY
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  if (!str)
    return (84);
  while (str[i] != '\0')
    {
      if ((str[i] < '0' || str[i] > '9'))
	return (0);
      i += 1;
    }
  return (1);
}
