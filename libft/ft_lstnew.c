/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:46:40 by meyami            #+#    #+#             */
/*   Updated: 2017/11/15 16:46:41 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;
	void	*content_copy;

	if (!(ptr = malloc(sizeof(t_list))))
		return (0);
	if (!content)
	{
		ptr->content = 0;
		ptr->content_size = 0;
	}
	else
	{
		if (!(content_copy = malloc(content_size)))
			return (0);
		ft_memcpy(content_copy, content, content_size);
		ptr->content = content_copy;
		ptr->content_size = content_size;
	}
	ptr->next = 0;
	return (ptr);
}
