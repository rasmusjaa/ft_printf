/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:53:15 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/11/19 17:39:56 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	move_flags(t_node *temp, t_node *current)
{
	temp->width = current->width;
	temp->precision = current->precision;
	temp->precision_set = current->precision_set;
	temp->plus_flag = current->plus_flag;
	temp->arg = current->arg;
	temp->space = current->space;
	temp->hash = temp->space;
}

void		add_hash(t_node *temp, t_node *current)
{
	char	*tmp;

	if (current->arg == 'o')
	{
		tmp = temp->str;
		temp->str = ft_strjoin("0", tmp);
		free(tmp);
	}
	if (current->arg == 'x')
	{
		tmp = temp->str;
		temp->str = ft_strjoin("0x", tmp);
		free(tmp);
	}
	if (current->arg == 'X')
	{
		tmp = temp->str;
		temp->str = ft_strjoin("0X", tmp);
		free(tmp);
	}
}

void		flags_from_temp(t_node *temp, t_node *current)
{
	char	*tmp;

	move_flags(temp, current);
	if (current->plus_flag == 1)
	{
		if (current->arg == 'd' || current->arg == 'f')
		{
			tmp = temp->str;
			temp->str = ft_strjoin("+", tmp);
			free(tmp);
		}
		else
			exits(1);
	}
	if (current->precision_set == 1)
		add_precision(temp, current->precision);
	add_width(temp);
	if (current->space == 1 && current->plus_flag != 0 && is_nb(current->arg))
		swap_sign(temp->str);
	if (current->hash == 1)
		add_hash(temp, current);
}

static int	check_flags2(char **str, t_node *current)
{
	if (**str == '-' || **str == '+')
	{
		*str = (*str) + plus_minus(*str, current);
		return (1);
	}
	if (ft_isdigit(**str))
	{
		*str = (*str) + check_width(*str, current);
		return (1);
	}
	return (-1);
}

int			check_flags(char **str, t_node *current)
{
	if (**str == '.')
	{
		*str = (*str) + check_precision(*str, current);
		return (1);
	}
	if (**str == '0' && !(ft_isdigit(*(*str - 1))))
	{
		current->space = 1;
		*str = (*str) + 1;
		return (1);
	}
	if (**str == '#')
	{
		current->hash = 1;
		*str = (*str) + 1;
		return (1);
	}
	return (check_flags2(str, current));
}
