/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:42:09 by meyami            #+#    #+#             */
/*   Updated: 2017/11/15 19:42:10 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr;
	t_list	*begin;

	if (!lst)
		return (0);
	ptr = f(lst);
	begin = ptr;
	while (lst->next)
	{
		lst = lst->next;
		ptr->next = f(lst);
		ptr = ptr->next;
	}
	return (begin);
}
