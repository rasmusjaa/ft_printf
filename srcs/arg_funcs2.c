/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_funcs2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:40:15 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/11/19 17:40:55 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			arg_o_to_node(t_node *current, va_list args)
{
	t_node	*temp;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	temp->str = ft_base_ltoa(va_arg(args, unsigned int), 8, BASE16UC);
	current->arg = 'o';
	plus_minus(temp->str, current);
	flags_from_temp(temp, current);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}

int			arg_u_to_node(t_node *current, va_list args)
{
	t_node	*temp;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	temp->str = ft_base_ltoa(va_arg(args, unsigned int), 10, BASE16UC);
	current->arg = 'u';
	plus_minus(temp->str, current);
	flags_from_temp(temp, current);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}

int			arg_f_to_node(t_node *current, va_list args)
{
	t_node	*temp;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	temp->str = ft_ftoa(va_arg(args, double), current->precision);
	current->arg = 'f';
	plus_minus(temp->str, current);
	flags_from_temp(temp, current);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}

int			arg_x_to_node(t_node *current, va_list args)
{
	t_node	*temp;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	temp->str = ft_base_ltoa(va_arg(args, unsigned int), 16, BASE16LC);
	current->arg = 'x';
	plus_minus(temp->str, current);
	flags_from_temp(temp, current);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}

int			arg_ucx_to_node(t_node *current, va_list args)
{
	t_node	*temp;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	temp->str = ft_base_ltoa(va_arg(args, unsigned int), 16, BASE16UC);
	current->arg = 'X';
	plus_minus(temp->str, current);
	flags_from_temp(temp, current);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}
