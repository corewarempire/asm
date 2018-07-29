/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:46:13 by meyami            #+#    #+#             */
/*   Updated: 2017/11/08 16:46:25 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>

# define BUFFER_SIZE 1000
# define BUFF_SIZE 32
# define UTF_MAX 1114111

typedef struct		s_env
{
	void	(*types[256]) (struct s_env *);
	char	buffer[BUFFER_SIZE];
	int		buffer_index;
	int		nb_printed;
	int		left_align;
	int		alternate_form;
	int		padding_0;
	int		pre_space;
	int		plus_sign;
	int		width;
	int		precision;
	int		has_precision;
	int		precision_zero;
	int		length;
	int		shift;
	int		type;
	int		neg;
	int		err;
	va_list	args;
}					t_env;

int					ft_printf(char *format, ...);
void				ft_error(int code);
int					ft_substr(char *haystack, char needle);
long int			ft_abs_value(long int number);
int					ft_wcharlen(int c);
int					ft_wstrlen(t_env *e, int *str);
char				*itoa_long(t_env *e, long int n);
char				*itoa_long_base(t_env *e, unsigned long int n, int base,
									char *symbols);
void				initializer_init(t_env *e);
void				initializer_types_init(t_env *e);
void				initializer_reset(t_env *e);
void				buffer_fill_char(t_env *e, char c, int n);
void				buffer_fill_string(t_env *e, char *str, int n);
void				buffer_fill_utf_char(t_env *e, int c);
void				buffer_fill_utf_string(t_env *e, int *str, int n);
void				buffer_print(t_env *e);
void				converter_parse(t_env *e, char *format, int *index);
void				converter_convert(t_env *e, char *flag);
int					format_find(t_env *e, char format);
int					width_find(t_env *e, char *width);
int					precision_find(t_env *e, char *precision);
int					length_find(t_env *e, char *length);
int					type_find(char type);
void				type_d_i(t_env *e);
void				type_ld(t_env *e);
void				type_c(t_env *e);
void				type_s(t_env *e);
void				type_lc(t_env *e);
void				type_ls(t_env *e);
void				type_o(t_env *e);
void				type_lo(t_env *e);
void				type_x(t_env *e);
void				type_maj_x(t_env *e);
void				type_u(t_env *e);
void				type_lu(t_env *e);
void				type_p(t_env *e);
void				type_percent(t_env *e);
void				type_b(t_env *e);

int					ft_isdigit(int c);
int					ft_isnumber(char *s);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
size_t				ft_strlen(const char *s);
size_t				ft_strtablen(const char **tab);
char				*ft_strdup(const char *s1);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_atoi(const char *str);
long int			ft_atoi_long(const char *str);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

typedef struct		s_content
{
	char	*s;
	int		newline;
	int		len;
	int		size;
}					t_content;

int					get_next_line(const int fd, char **line);

#endif
