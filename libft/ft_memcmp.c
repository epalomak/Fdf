/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:42:21 by epalomak          #+#    #+#             */
/*   Updated: 2020/06/01 18:01:27 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sr1;
	const unsigned char	*sr2;
	size_t				i;

	sr1 = s1;
	sr2 = s2;
	if (n <= 0)
		return (0);
	i = 0;
	while (sr1[i] == sr2[i] && i < n - 1)
		i++;
	return ((unsigned char)sr1[i] - (unsigned char)sr2[i]);
}
