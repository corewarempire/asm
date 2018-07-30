/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_handle_param.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 00:04:08 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/30 20:56:43 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../includes/op.h"
#include "../libft/includes/libft.h"

char	*parser_get_param(char *line, t_line *new, int nbp)
{
	char	*param;
	int		temp;
	int		i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	temp = i;
	while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] != ',')
		i++;
	if (!(param = ft_strsub(line, temp, i - temp)))
		return (0);
	if ((param[0] == '%' && parser_is_digits(param + 1))
	|| (param[0] == '%' && param[1] == ':' && parser_is_label(param + 2))
	|| (param[0] == ':' && parser_is_label(param + 1))
	|| (param[0] == 'r' && parser_is_digits(param + 1)
	&& ft_atoi(param + 1) < 100 && ft_atoi(param + 1) >= 0)
	|| (param[0] != 'r' && parser_is_digits(param + 1)))
	{
		new->params[nbp] = param;
		line += i;
		return (line);
	}
	return (0);
}

char	*parser_handle_param(char *line, t_line *new, int nbp)
{
	if (!(line = parser_get_param(line, new, nbp++)))
		return (0);
	while (nbp < new->nb_params && *line)
	{
		while (*line && (*line == ' ' || *line == '\t'))
			line++;
		if (*line != ',')
			return (0);
		line++;
		while (*line && (*line == ' ' || *line == '\t'))
			line++;
		if (!(line = parser_get_param(line, new, nbp++)))
			return (0);
	}
	if (nbp != new->nb_params)
		return (0);
	return (line);
}
