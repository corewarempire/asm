/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_handle_label.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 23:50:48 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/29 01:29:57 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../includes/op.h"
#include "../libft/includes/libft.h"

int		parser_is_label(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_partof(str[i], LABEL_CHARS))
			return (0);
		i++;
	}
	return (1);
}

char	*parser_handle_label(char *line, t_line *new)
{
	int i;
	int temp;

	i = 0;
	while (line[i] && line[i] == ' ' && line[i] == '\t')
		i++;
	temp = i;
	if (line[i] == ':')
		return (0);
	while (line[i] && line[i] != ':' && line[i] != ' ' && line[i] != '\t')
	{
		if (!ft_partof(line[i++], LABEL_CHARS))
			return (0);
	}
	if (line[i] == ':')
	{
		new->label = ft_strsub(line, temp, i - temp);
		line += i + 1;
		return (line);
	}
	if (line[i] == 0)
		return (0);
	return (line);
}
