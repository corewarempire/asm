/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 20:38:15 by meyami            #+#    #+#             */
/*   Updated: 2018/07/26 20:38:16 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error_exit(t_data *data)
{
	data_free(data);
	exit(1);
}

int		error_wrong_extension(char *file_name)
{
	int i;

	i = -1;
	while (file_name[++i + 1])
		if (ft_strequ(file_name + i, ".s") == 0)
			return (1);
	return (0);
}
