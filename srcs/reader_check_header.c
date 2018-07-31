/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_check_header.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 21:53:25 by sgalasso          #+#    #+#             */
/*   Updated: 2018/08/01 00:29:18 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		ft_handle_name(char *line, t_data *data)
{
	int i;
	int start;

	i = 6;
	while (line[i] && line[i] != '"')
		i++;
	if (line[i] != '"')
		return (0);
	start = i;
	i++;
	while (line[i] && line[i] != '"')
		i++;
	if (line[i] != '"' && line[i + 1] != 0)
		return (0);
	if (ft_strlen(line) - (start + 2) > PROG_NAME_LENGTH)
		return (0);
	if (!(data->name =
	ft_strsub(line, start + 1, ft_strlen(line) - (start + 2))))
		return (0);
	return (1);
}

int		reader_first(char *line, t_data *data, int start, int i)
{
	if (line[i] == 0)
	{
		if (!(data->comment))
		{
			data->comment = ft_strdup(line + start);
			data->comment = ft_strjoin(data->comment, "\n");
		}
	}
	else
	{
		if (!(data->comment =
		ft_strsub(line, start, ft_strlen(line) - (start + 1))))
			return (0);
		if (ft_strlen(data->comment) > COMMENT_LENGTH)
			return (0);
		return (1);
	}
	return (2);
}

int		reader_multiple(char *line, int fd, t_data *data, int i)
{
	if (line[i] != '"')
	{
		while (get_next_line(fd, &line) > 0)
		{
			i = 0;
			while (line[i])
			{
				if (line[i] == '"')
				{
					if (!(data->comment = ft_strjoin(data->comment,
					ft_strsub(line, 0, ft_strlen(line) - 1))))
						return (0);
					return ((ft_strlen(data->comment)
					> COMMENT_LENGTH) ? 0 : 1);
				}
				i++;
			}
			if (!(data->comment = ft_strjoin(data->comment, line)))
				return (0);
			if (!(data->comment = ft_strjoin(data->comment, "\n")))
				return (0);
			data->line_nb++;
		}
	}
	return (0);
}

int		ft_handle_comment(char *line, t_data *data, int fd)
{
	int	start;
	int ret;
	int i;

	ret = 0;
	i = 9;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] != '"')
		return (0);
	start = ++i;
	while (line[i] && line[i] != '"')
		i++;
	if ((ret = reader_first(line, data, start, i)) == 0)
		return (0);
	else if (ret == 1)
		return (1);
	if (reader_multiple(line, fd, data, i))
		return (1);
	return (0);
}

int		reader_check_header(t_data *data, char *line, int fd)
{
	if (reader_is_empty(line))
		return (1);
	while (*line == ' ' || *line == '\t')
		line++;
	if (ft_is_name(line))
	{
		if (ft_handle_name(line, data))
			return (1);
	}
	else if (ft_is_comment(line))
	{
		if (ft_handle_comment(line, data, fd))
			return (1);
	}
	return (0);
}
