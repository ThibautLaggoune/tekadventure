/*
** my_filelenght.c for  in /home/leroyc/Delivery/2016/LIB/lib/my
** 
** Made by Corentin LEROY
** Login   <corentin.leroy@epitech.eu@epitech.net>
** 
** Started on  Tue Jan 31 09:43:10 2017 Corentin LEROY
** Last update Mon May 22 19:16:08 2017 Corentin LEROY
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	my_filelenght(char *file)
{
  int	fd;
  int	size;
  char	*str;

  size = 0;
  if ((fd = open(file, O_RDONLY)) == -1)
    return (0);
  while ((str = get_next_line(fd)))
    {
      free(str);
      size++;
    }
  close(fd);
  return (size);
}
