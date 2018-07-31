/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_handle_label.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 23:50:48 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/31 22:23:57 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		parser_is_label(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i])
	{
		if (!ft_partof(str[i], LABEL_CHARS))
			return (0);
		i++;
	}
	return (1);
}

char	*parser_handle_label(char *line, t_data *data)
{
	int i;
	int temp;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
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
		if (!labels_add(data, ft_strsub(line, temp, i - temp)))
			return (0);
		line += i + 1;
		return (line);
	}
	if (line[i] == 0)
		return (0);
	return (line);
}
