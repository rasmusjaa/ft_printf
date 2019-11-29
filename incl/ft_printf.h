/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:39:15 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/11/29 16:15:04 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# define N_TYPES 10
# define NULL_STRING "(null)"
# define BASE16UC "0123456789ABCDEF"
# define BASE16LC "0123456789abcdef"
# define BLUE "\033[0;34m"
# define CYAN "\033[0;36m"
# define GREEN "\033[0;32m"
# define MAGENTA "\033[0;35m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define BBLUE "\033[1;34m"
# define BCYAN "\033[1;36m"
# define BGREEN "\033[1;32m"
# define BMAGENTA "\033[1;35m"
# define BRED "\033[1;31m"
# define BYELLOW "\033[1;33m"
# define EOC "\033[0m"

typedef struct		s_node
{
	char			*str;
	char			arg;
	int				plus_flag;
	int				minus_flag;
	int				space;
	int				empty;
	int				width;
	int				precision;
	int				precision_set;
	int				l_flag;
	int				ll_flag;
	int				ucl_flag;
	int				h_flag;
	int				hh_flag;
	int				hash;
	int				xflag;
	long long int	nb;
	double			float_left;
	double			float_right;
	int				cnull;
	struct s_node	*next;
}					t_node;

typedef int			(*t_func)(t_node *, va_list);

typedef struct		s_types
{
	char			c;
	t_func			func;
}					t_types;

int					text_to_node(t_node *current, char *str, int len);
int					arg_c_to_node(t_node *current, va_list args);
int					arg_s_to_node(t_node *current, va_list args);
int					arg_p_to_node(t_node *current, va_list args);
int					arg_d_to_node(t_node *current, va_list args);
int					arg_o_to_node(t_node *current, va_list args);
int					arg_u_to_node(t_node *current, va_list args);
int					arg_x_to_node(t_node *current, va_list args);
int					arg_ucx_to_node(t_node *current, va_list args);
int					arg_f_to_node(t_node *current, va_list args);

int					arg_percent_to_node(t_node *current);

extern t_types		g_types[N_TYPES];

int					ft_putstr_ret(t_node *current);
char				*ft_strndup(const char *s, int len);
char				*ft_strnew_c(size_t size, char c);
char				*trim_n_first(int n, char *str);

char				*ft_ftoa(long double nb, t_node *current);
char				*address_pre(char *str);
int					set_prefixes(char *str, t_node *current);

void				add_empty(t_node *temp, t_node *current);

int					check_width(char *str, t_node *current);
void				add_width(t_node *current);
void				add_precision(t_node *current, int precision);

void				swap_sign(char *str);
void				flags_from_temp(t_node *temp, t_node *current);
int					check_flags(char **str, t_node *current);

void				exits(int i);

int					ft_printf(const char *format, ...);

int					is_nb(char c);
int					plus_minus(char *str, long long n, t_node *current);
int					plus_minus2(char *str, t_node *current);
int					check_precision(char *str, t_node *current);

#endif
