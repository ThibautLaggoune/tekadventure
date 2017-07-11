/*
** my_power_rec.c for my_power_rec in /home/XIII/delivery/Day05
** 
** Made by Corentin LEROY
** Login   <XIII@epitech.net>
** 
** Started on  Fri Oct  7 11:41:25 2016 Corentin LEROY
** Last update Thu Apr  6 10:43:01 2017 Corentin LEROY
*/

int	my_pow(int nb, int p)
{
  long	tester;

  tester = nb;
  if ((nb * nb) > 2147483647)
    nb = 0;
  else if (p == 0)
    nb = 1;
  else if (p == 1)
    return (nb);
  else if (p < 0)
    nb = 0;
  else
    {
      if (p > 1)
	{
	  tester = tester * my_pow(nb, p - 1);
	  nb = tester;
	  if (tester != nb)
	    nb = 0;
	}
    }
  return (nb);
}
