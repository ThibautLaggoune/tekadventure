/*
** memset.c for my memset in /home/leroyc/Delivery/LIB/lib/my
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Mon Nov 28 16:01:37 2016 Corentin LEROY
** Last update Mon Nov 28 16:01:38 2016 Corentin LEROY
*/

void	print_memset(char *toset, char tobeset, int size)
{
  toset[--size] = '\0';
  while (size > 0)
    {
      size = size - 1;
      toset[size] = tobeset;
    }
}
