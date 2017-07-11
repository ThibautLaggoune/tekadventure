/*
** my_getnbr.c for my_getnbr in /home/XIII/delivery/CPool_Day04
** 
** Made by Corentin LEROY
** Login   <XIII@epitech.net>
** 
** Started on  Tue Oct 11 10:42:53 2016 Corentin LEROY
** Last update Mon May 22 21:21:56 2017 Corentin LEROY
*/

int	my_getnbr(char *str)
{
  int	i;
  int	minus;
  long	test;

  i = 0;
  test = 0;
  minus = 1;
  if (!str)
    return (0);
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	minus *= -1;
      i += 1;
    }
  while ('0' <= str[i] && str[i] <= '9')
    {
      test = test * 10 + str[i] - 48;
      i += 1;
    }
  return (test * minus);
}
