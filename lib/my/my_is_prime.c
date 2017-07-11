/*
** my_is_prime.c for my_is_prime in /home/XIII/delivery/CPool_Day05
** 
** Made by Corentin LEROY
** Login   <XIII@epitech.net>
** 
** Started on  Fri Oct  7 14:00:30 2016 Corentin LEROY
** Last update Mon Oct 10 14:09:33 2016 Corentin LEROY
*/

int	my_is_prime(int nb)
{
  int	tester;
  int	i;

  i = 2;
  tester = 0;
  if (nb < 2)
    return (0);
  else if (nb == 2 || nb == 5 ||
	   nb == 3 || nb == 7)
    return (1);
  else
    {
      while (i <= 7)
	{
	  tester = nb / i;
	  tester = tester * i;
	  i = i + 1;
	  if (tester == nb)
	    return (0);
	}
      return (1);
    }
}
