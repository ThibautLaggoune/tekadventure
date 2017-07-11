/*
** my_swap.c for my_swap in /home/XIII/delivery/CPool_Day04
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu>
** 
** Started on  Thu Oct  6 12:56:35 2016 Corentin LEROY
** Last update Thu Oct  6 13:01:42 2016 Corentin LEROY
*/

int	my_swap(int *a, int *b)
{
  int	tempa;

  tempa = *a;
  *a = *b;
  *b = tempa;
  return (0);
}
