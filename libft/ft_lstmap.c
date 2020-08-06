/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:10:13 by epalomak          #+#    #+#             */
/*   Updated: 2019/11/07 17:21:32 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*new;

	if (!lst)
		return (NULL);
	if (!(new = f(lst)))
		return (NULL);
	first = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new->next = f(lst)))
			return (NULL);
		new = new->next;
	}
	return (first);
}
