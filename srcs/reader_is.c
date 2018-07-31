/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_is.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 00:03:18 by sgalasso          #+#    #+#             */
/*   Updated: 2018/08/01 00:04:27 by sgalasso         ###   ########.fr       */
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

int		ft_is_name(char *line)
{
	return (ft_strnequ(line, NAME_CMD_STRING, 5));
}

int		ft_is_comment(char *line)
{
	return (ft_strnequ(line, COMMENT_CMD_STRING, 8));
}
