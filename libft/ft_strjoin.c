/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:23:52 by epalomak          #+#    #+#             */
/*   Updated: 2019/11/07 10:54:52 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*dst;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	if (!(dst = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (dst);
}
