/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_check_header.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 21:53:25 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/29 23:19:07 by sgalasso         ###   ########.fr       */
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

int		ft_handle_comment(char *line, t_data *data)
{
	int i;
	int start;

	i = 9;
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
	if (ft_strlen(line) - (start + 2) > COMMENT_LENGTH)
		return (0);
	if (!(data->comment =
	ft_strsub(line, start + 1, ft_strlen(line) - (start + 2))))
		return (0);
	return (1);
}

int		ft_is_name(char *line)
{
	return (ft_strnequ(line, NAME_CMD_STRING, 5));
}

int		ft_is_comment(char *line)
{
	return (ft_strnequ(line, COMMENT_CMD_STRING, 8));
}

int		reader_check_header(t_data *data, char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (ft_is_name(line))
	{
		if (ft_handle_name(line, data))
			return (1);
	}
	else if (ft_is_comment(line))
	{
		if (ft_handle_comment(line, data))
			return (1);
	}
	else if (*line == '#' || *line == 0)
		return (1);
	ft_printf("Header error: line %d, (%s)\n", data->line_nb, line);
	return (0);
}
