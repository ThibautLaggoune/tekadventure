/*
** my_square_root.c for my_square_root in /home/XIII/delivery/CPool_Day05
** 
** Made by Corentin LEROY
** Login   <XIII@epitech.net>
** 
** Started on  Fri Oct  7 13:48:01 2016 Corentin LEROY
** Last update Thu Apr  6 11:34:50 2017 Corentin LEROY
*/

int	my_sqrt(int nb)
{
  int	square;
  int	test;

  square = 0;
  test = 0;
  while (square <= nb)
    {
      test = square * square;
      if (test == nb)
	return (square);
      else if (test > nb || square > 46340)
	return (0);
      else
	square = square + 1;
    }
  return (0);
}
