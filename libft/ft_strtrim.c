/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:03:24 by meyami            #+#    #+#             */
/*   Updated: 2017/11/14 15:25:56 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int i;
	int start;
	int end;

	if (!s)
		return (0);
	else if (!s[0])
		return (ft_strdup(""));
	start = 0;
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (s[i])
		start = i;
	else
		return (ft_strdup(""));
	i = ft_strlen(s) - 1;
	while (i >= 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i--;
	if (i >= 0)
		end = i;
	else
		return (ft_strdup(""));
	return (ft_strsub(s, start, end - start + 1));
}
