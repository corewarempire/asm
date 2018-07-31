/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_check_header.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 21:53:25 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/31 19:44:15 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		reader_is_empty(char *line)
{
	int i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '#' || line[i] == 0)
		return (1);
	return (0);
}

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

int		ft_handle_comment(char *line, t_data *data, int fd)
{
	int	start;
	int i;

	i = 9;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] != '"')
		return (0);
	start = ++i;
	while (line[i] && line[i] != '"')
		i++;
	if (line[i] == 0)
	{
		if (!(data->comment = ft_strdup("\n")))
			return (0);
	}
	else
	{
		if (!(data->comment = ft_strsub(line, start, ft_strlen(line) - (start + 1))))
			return (0);
		return (1);
	}
	if (line[i] != '"')
	{
		while (get_next_line(fd, &line) > 0)
		{
			i = 0;
			while (line[i])
			{
				if (line[i] == '"')
				{
					if (!(data->comment = ft_strjoin(data->comment, line)))
						return (0);
					return (1);
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

int		ft_is_name(char *line)
{
	return (ft_strnequ(line, NAME_CMD_STRING, 5));
}

int		ft_is_comment(char *line)
{
	return (ft_strnequ(line, COMMENT_CMD_STRING, 8));
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
	ft_printf("Header error: line %d, (%s)\n", data->line_nb, line);
	return (0);
}
