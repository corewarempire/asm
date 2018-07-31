/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_handle_label.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 23:50:48 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/31 18:39:18 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../includes/op.h"
#include "../libft/includes/libft.h"

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

char	*parser_get_label(char *line, t_line *new, t_data *data)
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
		if (!labels_add(data, new, ft_strsub(line, temp, i - temp)))
			return (0);
		line += i + 1;
		return (line);
	}
	if (line[i] == 0)
		return (0);
	return (line);
}

char	*parser_handle_label(char **line, t_data *data, int fd, t_line *new)
{
	int		ret;

	if (parser_is_label(*line))
	{
		while ((ret = get_next_line(fd, line)) > 0)
		{
			if (parser_is_label(*line))
			{
				if (!(*line = parser_get_label(*line, new, data)))
					return (0);
				if (!parser_is_empty(*line))
					break ;
			}
			else if (ret == 0)
			{
				//if (!labels_add(data, 0, ft_strsub(*line, , ))) // fin unique label
				//	return (0);
				return (*line);
			}
		}
	}
	return (*line);
}
