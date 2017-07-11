/*
** my_memset.c for my memset in /home/leroyc/Delivery/LIB/lib/my
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Mon Nov 28 16:01:37 2016 Corentin LEROY
** Last update Thu Apr  6 10:41:53 2017 Corentin LEROY
*/

void	my_memset(void *toset, char tobeset, int size)
{
  char  *bytes;

  bytes = (char *)toset;
  while (toset && size--)
    {
      *bytes = tobeset;
      bytes++;
    }
}
