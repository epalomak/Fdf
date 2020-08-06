/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:23:16 by epalomak          #+#    #+#             */
/*   Updated: 2019/11/07 11:09:03 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	size_t				i;

	src = s;
	i = 0;
	while (n > i && src[i] != '\0')
	{
		if (src[i] == (unsigned char)c)
			return ((void*)&src[i]);
		i++;
	}
	if (src[i] == (unsigned char)c && src[i] == '\0')
		return ((void*)&src[i]);
	return (NULL);
}
