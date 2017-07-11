/*
** my.h for my.h in /home/XIII/delivery/CPool_Day09
** 
** Made by Corentin LEROY
** Login   <XIII@epitech.net>
** 
** Started on  Thu Oct 13 11:12:04 2016 Corentin LEROY
** Last update Thu Apr  6 10:43:57 2017 Corentin LEROY
*/

#ifndef	MY_H_
# define MY_H_

# include <stdarg.h>
# ifndef NULL
#  define NULL 0
# endif /* !NULL */
# ifndef UNUSED
#  define UNUSED(x) ((void) x)
# endif /* !UNUSED */

/*
** Str functions;
*/

int	my_putchar(char c);
int	my_putstr(char *str);
int	my_str_isnum(char *str);
int	my_str_isalpha(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_strcmp(char *s1, char *s2);
char	*my_strcpy(char *dest, char *src);
char	*my_strdup(char *str);
int	my_strlen(char *str);
char	*my_strlowcase(char *str);
char	*my_strstr(char *str, char *to_find);
char	*my_strupcase(char *str);

/*
** Nbr functions;
*/

int	my_putnbr(int nb);
int	my_getnbr(char *str);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
int	my_pow(int nb, int power);
void	my_sort_int_tab(char *str);
int	my_sqrt(int nb);

/*
** Tab functions;
*/

int	my_tablen(char **tab);
void	my_free_tab(char **tab);
void	my_disptab(char **tab);
char	**str_wt(char *str, char sep);
char	**my_tabcpy(char **tab);

/*
** Handy functions;
*/

void	my_memset(void *toset, char tobeset, int size);

/*
** GNL functions;
*/

# ifndef READ_SIZE
#  define READ_SIZE 1
# endif /* !READ_SIZE */

char	*get_next_line(int fd);
int	my_filelenght(char *file);

#endif	/* !MY_H_ */
