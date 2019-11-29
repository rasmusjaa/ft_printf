/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:38:29 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/11/29 17:35:15 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void					swap_sign(char *str)
{
	int					i;

	i = 0;
	if (str[i] == '0')
	{
		while (str[i] && str[i] != '-' && str[i] != '+')
			i++;
		if (str[i] == '-' || str[i] == '+' || (str[i] == ' ' && i == 0))
		{
			str[0] = str[i];
			str[i] = '0';
		}
	}
	i = 0;
	if (str[i] == '0')
	{
		while (str[i] && str[i] == '0')
			i++;
		if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != 0)
		{
			str[i] = '0';
			str[0] = ' ';
		}
		if ((str[i] == 'x' || str[i] == 'X') && i != 1)
		{
			str[1] = str[i];
			str[i] = '0';
		}
		i = 0;
		while (str[i] == ' ')
			i++;
		if (i > 1 && str[i - 1] == ' ' && str[i] != ' ' && str[i] != 0)
		{
			str[i - 1] = '0';
			str[0] = ' ';
		}
	}
}

char					*float_begin(long double nb, t_node *current)
{
	int					x;
	int					y;
	double 				nb2;
	char				*s1;

	x = 0;
	y = 0;
	nb2 = 0;
	while (nb >= 1)
	{
		nb = nb / 10;
		x++;
	}
	if (x > 0)
		s1 = ft_strnew(x);
	else
	{
		s1 = ft_strnew(1);
		s1[0] = '0';
	}
	while (x > 0)
	{
		nb = nb * 10;
		s1[y] = (int)nb + '0';
		nb2 = nb2 * 10 + (int)nb;
		nb = nb - (int)nb;
		x--;
		y++;
	}
	current->float_left = nb2;
	return (s1);
}

long double				double_divide(long double nb, int n, int divider)
{
	if (n <= 0)
		return (0);
	while (n > 0)
	{
		nb = nb / divider;
		n--;
	}
	return (nb);
}

char					*float_end(long double nb, t_node *current)
{
	int					x;
	double 				nb2;
	char				*s2;
	int					not;

	x = 0;
	not = 0;
	nb2 = 0;
	s2 = ft_strnew(current->precision);
	while (nb >= 1)
		nb = nb - double_divide(0.5, current->precision, 10);
	while (x < current->precision)
	{
		nb = nb * 10;
		if ((int)nb >= 10)
			return (NULL);
		s2[x] = (int)(nb) + '0';
		nb2 = nb2 * 10 + (int)nb;
		nb = nb - (double)(int)nb;
		x++;
	}
	if (nb * 10 >=5 && current->precision >= 19 && s2[x - 1] < '9')
		s2[x - 1]++;
	current->float_right = nb2;
	return (s2);
}

char					*ft_ftoa(long double nb, t_node *current)
{
	char				*s1;
	char				*s2;
	char				*dbl;
	char				sign[2];

	sign[0] = nb < 0 ? '-' : 0;
	sign[1] = 0;
	if (nb < 0)
		nb = nb * -1;
	nb = nb + double_divide(0.5, current->precision, 10);
	s1 = float_begin(nb, current);
	if (nb - current->float_left >= 0.5 && current->precision <= 0)
		s1 = float_begin(nb + 1, current);
	s2 = float_end(nb - current->float_left, current);
	if (current->precision <= 0)
		dbl = ft_strjoin(sign, s1);
	else
		dbl = ft_strjoin(ft_strjoin(ft_strjoin(sign, s1), "."), s2);
	free(s2);
	free(s1);
	return (dbl);
}

char					*address_pre(char *str)
{
	char				pre[3];
	char				*tmp;

	pre[0] = '0';
	pre[1] = 'x';
	pre[2] = 0;
	tmp = ft_strjoin(pre, str);
	free(str);
	return (tmp);
}

int						set_prefixes(char *str, t_node *current)
{
	if(str[0] == 'l')
	{
		if(str[1] == 'l')
		{
			current->ll_flag = 1;
			return (2);
		}
		current->l_flag = 1;
	}
	if(str[0] == 'h')
	{
		if(str[1] == 'h')
		{
			current->hh_flag = 1;
			return (2);
		}
		current->h_flag = 1;
	}
	if(str[0] == 'L')
		current->ucl_flag = 1;
	return (1);
}
