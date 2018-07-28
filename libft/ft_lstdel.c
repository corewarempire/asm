/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:53:36 by meyami            #+#    #+#             */
/*   Updated: 2017/11/15 18:53:37 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*previous;

	if (!alst || *alst == 0)
		return ;
	ptr = *alst;
	*alst = 0;
	while (ptr->next)
	{
		previous = ptr;
		ptr = ptr->next;
		del(previous->content, previous->content_size);
		free(previous);
	}
	del(ptr->content, ptr->content_size);
	free(ptr);
}
