/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:04:47 by meyami            #+#    #+#             */
/*   Updated: 2017/11/14 17:04:48 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int nb_words;
	int i;

	nb_words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			nb_words++;
			while (s[i] && s[i] != c)
				i++;
		}
		if (s[i])
			i++;
	}
	return (nb_words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		begin_word;

	if (!s || !(tab = malloc(sizeof(char*) * (ft_countwords(s, c) + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			begin_word = i;
			while (s[i] && s[i] != c)
				i++;
			tab[j] = ft_strsub(s, begin_word, i - begin_word);
			j++;
		}
		if (s[i])
			i++;
	}
	tab[j] = 0;
	return (tab);
}
