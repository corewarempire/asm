/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_syntax.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 19:24:04 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/29 01:46:31 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../includes/op.h"
#include "../libft/includes/libft.h"

int		parser_is_digits(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*parser_cut_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] && line[i] != '#')
		i++;
	if (line[i] == '#')
		line[i] = 0;
	return (line);
}

int		parser_is_empty(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int		parser_inst_sample(char *line, t_data *data, t_line *new, int nbp)
{
	if (!(line = parser_handle_inst(line, data->op_tab, new)))
		return (0);
	if (!(line = parser_handle_param(line, new, nbp)))
		return (0);
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	if (*line != 0)
		return (0);
	return (1);
}

char	*parser_check_syntax(char *line, t_data *data)
{
	char	*temp;
	t_line	*new;
	int		nbp;

	nbp = 0;
	temp = line;
	if (!(line = parser_cut_line(line)))
		return (0);
	if (parser_is_empty(line))
		return (temp);
	if (!(new = parser_lstnew()))
		return (0);
	if (!(line = parser_handle_label(line, new)))
		return (0);
	if (!parser_is_empty(line))
	{
		if (!parser_inst_sample(line, data, new, nbp))
			return (0);
	}
	parser_lstaddend(new, data);
	return (temp);
}
