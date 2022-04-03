/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:34:41 by mimarque          #+#    #+#             */
/*   Updated: 2022/04/03 22:45:18 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdbool.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# define MY_TYPES "diuoxXfFeEgGaAcspn%"
# define MAXBUF 348
# define BUF 34
# define U_LONG unsigned long
# define MY_DIU "diouXx"
# define MY_DIUP "pdiouXx"
# define MY_UNSIGNED "uoxX"
# define MY_NUMS "123456789"
# define NO_SIGN_TYPE "cspuoxX"

/*
	A format specifier follows this prototype:
	%[param][flags][width][.precision][length]specifier
*/
typedef struct s_args
{
	char	*type;
	char	*cp;
	char	*pref;
	char	c;
	char	hash;
	char	dash;
	char	star;
	char	zero;
	char	dot;
	char	sign;
	char	base;
	int		width;
	int		precision;
	int		dprec;
	int		caps;
	int		size;
	int		realsz;
	int		prsize;
	U_LONG	ulval;
}	t_args;

size_t	ft_strlen(const char *s);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strpbrk(const char *s, char *accept);
char	*ft_substrpbrk(char *s, size_t len, char *accept);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_print(char *s, int len);
void	pad(int n, char with);

char	*print_base(char *cp, U_LONG value, unsigned int base, t_args *a);
int		get_value(char **format);
void	get_star(t_args *a, va_list args);
void	get_precision(t_args *a, char **format, va_list *args);
void	get_flags(char **fmt, t_args *a, va_list *args);
void	get_type_values(t_args *a, va_list *args);
void	adjustments(t_args *a);
void	s_setup(t_args *a);
void	csp_setup(t_args *a);
void	dioux_setup(t_args *a);
int		print_formating(t_args *a);
int		function_colection(char **fmt, t_args *a, va_list *args, char *buf);
int		ft_printf(const char *format, ...);

#endif