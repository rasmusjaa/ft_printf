/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:32:36 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/11/19 12:45:30 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			is_nb(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'f' ||
			c == 'x' || c == 'X' || c == 'u')
		return (1);
	return (0);
}

int			plus_minus(char *str, t_node *current)
{
	if (*str == '-')
	{
		current->plus_flag = -1;
	}
	if (*str == '+')
	{
		current->plus_flag = 1;
	}
	return (1);
}

int			check_precision(char *str, t_node *current)
{
	int		i;

	i = 1;
	current->precision_set = 1;
	current->precision = 0;
	while (ft_isdigit(str[i]))
	{
		current->precision = current->precision * 10 + (str[i] - '0');
		i++;
	}
	return (i);
}
