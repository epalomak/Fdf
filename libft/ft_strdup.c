/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:41:53 by epalomak          #+#    #+#             */
/*   Updated: 2019/11/06 13:49:29 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*des;

	len = 0;
	while (s1[len] != '\0')
		len++;
	if (!(des = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		des[i] = s1[i];
		i++;
	}
	des[i] = '\0';
	return (des);
}
