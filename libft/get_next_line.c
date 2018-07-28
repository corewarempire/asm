/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:37:37 by meyami            #+#    #+#             */
/*   Updated: 2017/11/27 13:37:39 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_init_content(t_content **content)
{
	if (!(*content = malloc(sizeof(t_content))))
		return (0);
	if (!((*content)->s = malloc(sizeof(char) * BUFF_SIZE)))
		return (0);
	(*content)->size = 0;
	(*content)->len = 0;
	(*content)->newline = -1;
	return (1);
}

static int		ft_find_newline(t_content *content)
{
	char *pos;

	if (content->s[0] == '\n')
	{
		content->newline = 0;
		return (1);
	}
	pos = (char *)ft_memchr(content->s, '\n', content->len);
	if (!pos)
	{
		content->newline = -1;
		return (0);
	}
	else
	{
		content->newline = pos - content->s;
		return (1);
	}
}

static int		fill_content(t_content *content, const int fd)
{
	char	buf[BUFF_SIZE];
	int		nb_read;
	char	*new;

	if (content->len && ft_find_newline(content))
		return (1);
	if ((nb_read = read(fd, buf, BUFF_SIZE)) < 1)
		return (nb_read);
	if (content->size < content->len + nb_read)
	{
		if (!(new = malloc(content->len + nb_read)))
			return (-1);
		ft_memcpy(new, content->s, content->len);
		ft_memcpy(new + content->len, buf, nb_read);
		free(content->s);
		content->s = new;
		content->len += nb_read;
		content->size = content->len;
	}
	else
	{
		ft_memcpy(content->s + content->len, buf, nb_read);
		content->len += nb_read;
	}
	return (2);
}

static int		ft_fill_line(char **line, t_content *content)
{
	if (content->newline == -1)
	{
		if (!(*line = malloc(sizeof(char) * (content->len + 1))))
			return (0);
		ft_memcpy(*line, content->s, content->len);
		*(*line + content->len) = 0;
		content->len = 0;
		return (1);
	}
	if (!(*line = malloc(sizeof(char) * (content->newline + 1))))
		return (0);
	ft_memcpy(*line, content->s, content->newline);
	*(*line + content->newline) = 0;
	ft_memmove(content->s, content->s + content->newline + 1,
				content->len - content->newline - 1);
	content->len -= content->newline + 1;
	content->newline = -1;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_content	*content = 0;
	int					reading;

	if (!line)
		return (-1);
	if (!content && !ft_init_content(&content))
		return (-1);
	while ((reading = fill_content(content, fd)) == 2)
	{
	}
	if (reading == 0 && !content->len)
		return (0);
	else if (reading == -1)
		return (-1);
	else
	{
		if (!(ft_fill_line(line, content)))
			return (-1);
		return (1);
	}
}
