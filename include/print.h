/*
** my.h for my.h in /home/XIII/delivery/CPool_Day09
** 
** Made by Corentin LEROY
** Login   <XIII@epitech.net>
** 
** Started on  Thu Oct 13 11:12:04 2016 Corentin LEROY
** Last update Thu Jan 19 13:41:15 2017 Corentin LEROY
*/

#ifndef	PRINT_H_
# define PRINT_H_

# include <stdarg.h>
# ifndef NULL
#  define NULL 0
# endif /* !NULL */
# ifndef UNUSED
#  define UNUSED(x) ((void) x)
# endif /* !UNUSED */

/*
** Main functions
*/

int	my_printf(char *str, ...);
int	my_eprintf(char *str, ...);
int	my_dprintf(int fd, char *str, ...);
char	*my_sprintf(char *str, ...);

/*
** Str functions;
*/

int	print_putstr(char *str);
int	print_strlen(char *str);
int	print_str_isnum(char *str);
int	print_str_isalpha(char *str);
int	print_str_islower(char *str);
int	print_str_isupper(char *str);
int	print_str_isprintable(char *str);
int	print_strcmp(char *s1, char *s2);
int	print_strncmp(char *s1, char *s2, int n);
char	*print_revstr(char *str);
char	*print_strdup(char *str);
char	*print_strupcase(char *str);
char	*print_strlowcase(char *str);
char	*print_strcapitalize(char *str);
char	*print_dupncat(char *s1, char *s2);
char	*print_strcat(char *dest, char *src);
char	*print_strcpy(char *dest, char *src);
char	*print_strstr(char *str, char *to_find);
char	*print_strncpy(char *dest, char *src, int n);
char	*print_strncat(char *dest, char *src, int nb);

/*
** Nbr functions;
*/

int	print_getnbr(char *str);

/*
** Tab functions;
*/

int	print_tablen(char **tab);
int	print_free_tab(char **tab);
void	print_disptab(char **tab);

/*
** Handy functions;
*/

int	print_putstr_error(char *str);
int	print_infd(int fd, char *str, int size);
void	print_putchar_error(char c);
void	print_memset(char *toset, char tobeset, int size);

/*
** Printf structure;
*/

struct	s_arg
{
  int	topad;
  int	tot_size;
  char	sign;
  char	base;
  char	type;
  char	nbpre;
  char	lenmod;
  char	padsym;
  char	zerpad;
  char	pad_pos;
  char	*str;
};

typedef	struct s_arg	t_arg;

/*
** Printf functions;
*/

int	get_bflag(char c);
int	get_mod(char *str);
int	get_nbrargs(char *str);
int	disp_stdarg(char *s, ...);
int	get_arg_end(char *str, int i);
int	sum_stdarg(int i, int nb, ...);
int	pre_buff(va_list args, char *str, char **parsone);
void	get_sign(char *arg, t_arg *ret);
void	init_targ(t_arg *ret, char *arg);
void	get_lenmod(char *arg, t_arg *ret);
void	get_padpos(char *arg, t_arg *ret);
void	get_padsym(char *arg, t_arg *ret);
void	get_zerpad(char *arg, t_arg *ret);
void    print_putnbr_str(int nb, char *dup, int i);
void	get_ftab(char *(**ftab)(va_list, char *));
void	print_putlnbr_str(long long nb, char *dup, int i);
void	print_bufferize(char *buff, char *str, char **tab);
void	get_nbpre_topad(char *arg, t_arg *ret, va_list args);
void    print_putdec_str(unsigned long long nb, char *dup, int i);
void    print_putstr_base(unsigned long long nb, char *base, char *dup, int i);
char	*print_putlnb_str(long long nb);
char	*print_putsign(char *str, char sign);
char	*print_puterr(va_list arg, char *pars);
char	*print_putzerpad(char *str, char type);
char	*print_putoct_str(char *str, char *dup);
char	*print_putnb_str(va_list arg, char *pars);
char	*print_putnbr_bin(va_list arg, char *pars);
char	*print_putnbr_dec(va_list arg, char *pars);
char	*print_putnbr_hex(va_list arg, char *pars);
char	*print_putnbr_HEX(va_list arg, char *pars);
char	*print_putnbr_oct(va_list arg, char *pars);
char	*print_putstr_oct(va_list arg, char *pars);
char	*print_putstr_prf(va_list arg, char *pars);
char	*print_putstr_ptr(va_list arg, char *pars);
char	*print_putchar_mod(va_list arg, char *pars);
char	*print_putchar_str(va_list arg, char *pars);
char	*print_putprecision(char *str, int precision);
char	*print_putsprecision(char *str, int precision);
char	*print_buffered(char *str, char **tab, int size);
char	*print_putpadding(char *str, char padsym, char padpos, char topad);
char	*put_args(char *, char *(**ftab)(va_list, char *), va_list);
t_arg	*get_arg_struct(char *arg, va_list args);
char	**printf_towordtab(char *str);

#endif	/* !PRINT_H_ */
