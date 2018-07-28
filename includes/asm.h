/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 19:40:53 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/26 19:03:50 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# include "op.h"

typedef struct s_line			t_line;
typedef struct s_label			t_label;
typedef struct s_data			t_data;
typedef struct s_op				t_op;

struct	s_op
{
	char			*name;							//Name
	int				nb_params;						//Nombre d'argument
	int				argv[3];						//Decomposition des arguments
	int				op_code;						//Valeur de l'opcode
	int				cycles;							//duree d'execution
	char			*lname;							//Long name?
	int				octal;							//format
	int				direct_size;						//direct size 2
};

struct	s_line
{
	int		index;
	char	*label;
	int		line_nb;
	int		command;
	int		nb_params;
	char	**params;
	char	params_type[4];
	char	params_code_byte;
	t_line	*next;
};

struct	s_label
{
	char	*name;
	t_line	*destination;
	t_label	*next;
};

struct	s_data
{
	t_line			*lines;
	t_label			*labels;
	t_op			*op_tab;
	int				prog_size;
	char			*name;
	char			*comment;
};

void	error_exit(t_data *data);
int		error_wrong_extension(char *file_name);

void	data_initialize(t_data *data);
void	data_free(t_data *data);

int		reader_read(int fd, t_data *data);
int		reader_check_header(t_data *data, char *line);

char	*parser_check_syntax(char *line, t_data *data);

void 	lines_free(t_line *lines);
int		lines_evaluate_size(t_line *line, t_op op);
int		lines_review(t_data *data);

void	labels_free(t_label *labels);
int		labels_add(t_data *data, t_line *line);
int		labels_find(t_data *data, int line_nb, char *to_find);
int		labels_replace(t_data *data);

void	parameters_set_types(t_line *line);
int 	parameters_check_legal(t_line *line, t_op op);
char	parameters_encode(char type, int shift);
void	parameters__set_code_byte(t_line *line);

void	file_write_number(int nb, char type, int direct_size, int fd);
void 	file_write_parameters(t_data *data, t_line *line, int fd);
void	file_write_header(t_data *data, int fd);
char	*file_create_name(char *path);
int		file_write(t_data *data, int fd, char *path);


#endif
