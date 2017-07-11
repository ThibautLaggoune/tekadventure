/*
** my_putchar.c for my_putchar in /home/XIII/delivery/CPool_Day07
** 
** Made by Corentin LEROY
** Login   <XIII@epitech.net>
** 
** Started on  Tue Oct 11 10:33:31 2016 Corentin LEROY
** Last update Thu Apr  6 10:43:47 2017 Corentin LEROY
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	my_putchar(char c)
{
  if (write(1, &c, 1) != 1)
    return (0);
  return (1);
}
