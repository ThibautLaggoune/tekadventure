/*
** getnbr.c for getnbr in /home/XIII/delivery/CPool_Day04
** 
** Made by Corentin LEROY
** Login   <XIII@epitech.net>
** 
** Started on  Tue Oct 11 10:42:53 2016 Corentin LEROY
** Last update Fri Mar 24 13:44:01 2017 Corentin LEROY
*/

int	print_getnbr(char *str)
{
  int	i;
  int	minus;
  long	test;

  i = -1;
  test = 0;
  minus = 1;
  while (str[++i] && (str[i] == '-' || str[i] == '+'))
    if (str[i] == '-')
      minus *= -1;
  while ('0' <= str[i] && str[i] <= '9')
    {
      test = test * 10 + str[i] - 48;
      if (test * minus > 2147483647 || test * minus < -2147483648)
	return (0);
      i++;
    }
  return (test * minus);
}
