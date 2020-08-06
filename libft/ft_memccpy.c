/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:45:56 by epalomak          #+#    #+#             */
/*   Updated: 2019/11/05 11:16:01 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (n-- > 0)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
		{
			i++;
			return ((unsigned char*)d + i);
		}
		i++;
	}
	return (NULL);
}
