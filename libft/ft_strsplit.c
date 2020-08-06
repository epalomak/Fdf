/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:49:36 by epalomak          #+#    #+#             */
/*   Updated: 2019/12/10 12:19:57 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	st;
	size_t	i;
	int		ac;

	if (!(str = (char**)malloc(sizeof(char*) * ft_count(s, c) + 1)))
		return (NULL);
	ac = -1;
	i = 0;
	while (++ac < ft_count(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		st = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i] == '\0' && s[i - 1] == c)
			break ;
		if (!(str[ac] = ft_strsub(s, st, i - st)))
			return (NULL);
		i++;
	}
	str[ac] = NULL;
	return (str);
}
