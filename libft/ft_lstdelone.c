/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:56:22 by meyami            #+#    #+#             */
/*   Updated: 2017/11/15 16:56:23 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;

	if (!alst || *alst == 0)
		return ;
	ptr = *alst;
	del(ptr->content, ptr->content_size);
	free(ptr);
	*alst = 0;
}
