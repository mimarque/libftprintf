/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfuncts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:10:50 by mimarque          #+#    #+#             */
/*   Updated: 2022/03/31 23:22:02 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Gets the lenght of a string
 * 
 * @param s the string to get the lenght
 * @return size_t 
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

/**
 * @brief The memchr() function locates the first occurrence
	of c (converted to an unsigned char) in string s.
	returns a pointer to the byte located,
	or NULL if no such byte exists within n bytes.
 * 
 * @param s string to look through
 * @param c char to look for
 * @param n max lenght to search
 * @return void* 
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	size_t			i;

	i = 0;
	src = (unsigned char *)s;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
			return ((void *)(src + i));
		i++;
	}
	return (NULL);
}

/**
 * @brief LibC function to find a character from a list of chars
 * 
 * @param s string to go through
 * @param accept list of chars to find in 's'
 * @return char* 
 */
char	*ft_strpbrk(const char *s, char *accept)
{
	char	*a;

	while (*s != '\0')
	{
		a = accept;
		while (*a != '\0')
			if (*a++ == *s)
				return ((char *) s);
		++s;
	}
	return (NULL);
}

/**
 * @brief Does the same as strpbrk but for len ammount of chars
 * 
 * @param s string to go through
 * @param len the limit amount of chars to go through (positive)
 * @param accept list of chars to find in 's'
 * @return char* 
 */
char	*ft_substrpbrk(char *s, size_t len, char *accept)
{
	char	*a;
	char	*l;

	if (len < 0)
		return (NULL);
	l = s + len;
	while (s != l)
	{
		a = accept;
		while (*a != '\0')
			if (*a++ == *s)
				return ((char *) s);
		++s;
	}
	return (NULL);
}

/**
 * @brief Check if  d is a digit
 * 
 * @param d 
 * @return true 
 * @return false 
 */
bool	is_digit(char d)
{
	return ((d) >= '0' && (d) <= '9');
}
