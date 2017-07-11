/*
** my_strisalpha.c for my_strisalpha in /home/XIII/delivery/CPool_Day06
** 
** Made by Corentin LEROY
** Login   <XIII@epitech.net>
** 
** Started on  Tue Oct 11 21:42:19 2016 Corentin LEROY
** Last update Thu Apr  6 11:40:42 2017 Corentin LEROY
*/

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  if (!str)
    return (84);
  while (str[i] != '\0')
    {
      if ((str[i] >= 'a' && str[i] <= 'z'))
	i = i + 1;
      else
	return (0);
    }
  return (1);
}
