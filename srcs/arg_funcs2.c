/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_funcs2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:40:15 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/11/29 17:33:37 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int							arg_o_to_node(t_node *current, va_list args)
{
	t_node					*temp;
	long long unsigned int	n;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	n = va_arg(args, long long unsigned int);
	if (current->l_flag == 1)
		temp->str = ft_base_ltoa((long unsigned int)n, 8, BASE16UC);
	else if (current->ll_flag == 1)
		temp->str = ft_base_ltoa(n, 8, BASE16UC);
	else
		temp->str = ft_base_ltoa((unsigned int)n, 8, BASE16UC);
	current->arg = 'o';
	plus_minus(temp->str, n, current);
	flags_from_temp(temp, current);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}

int							arg_u_to_node(t_node *current, va_list args)
{
	t_node					*temp;
	long long unsigned int	n;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	n = va_arg(args, long long unsigned int);
	if (current->l_flag == 1)
		temp->str = ft_base_ltoa((long unsigned int)n, 10, BASE16UC);
	else if (current->ll_flag == 1)
		temp->str = ft_base_ltoa(n, 10, BASE16UC);
	else
		temp->str = ft_base_ltoa((unsigned int)n, 10, BASE16UC);
	current->arg = 'u';
	plus_minus(temp->str, n, current);
	flags_from_temp(temp, current);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}

int							arg_f_to_node(t_node *current, va_list args)
{
	t_node					*temp;
	double					n;
	long double				ln;

	n = 0.0;
	ln = 0.0;
	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	if (current->ucl_flag == 1)
	{
		ln = va_arg(args, long double);
		temp->str = ft_ftoa(ln, current);
	}
	else
	{
		n = va_arg(args, double);
		temp->str = ft_ftoa((double)n, current);
	}
	current->arg = 'f';
	plus_minus(temp->str, n, current);
	flags_from_temp(temp, current);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}

int							arg_x_to_node(t_node *current, va_list args)
{
	t_node					*temp;
	long long unsigned int	n;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	n = va_arg(args, long long unsigned int);
	current->nb = n;
	if (current->l_flag == 1)
		temp->str = ft_base_ltoa((long unsigned int)n, 16, BASE16LC);
	else if (current->ll_flag == 1)
		temp->str = ft_base_ltoa(n, 16, BASE16LC);
	else
		temp->str = ft_base_ltoa((unsigned int)n, 16, BASE16LC);
	current->arg = 'x';
	plus_minus(temp->str, n, current);
	flags_from_temp(temp, current);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}

int							arg_ucx_to_node(t_node *current, va_list args)
{
	t_node					*temp;
	long long unsigned int	n;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	n = va_arg(args, long long unsigned int);
	current->nb = n;
	if (current->l_flag == 1)
		temp->str = ft_base_ltoa((long unsigned int)n, 16, BASE16UC);
	else if (current->ll_flag == 1)
		temp->str = ft_base_ltoa(n, 16, BASE16UC);
	else
		temp->str = ft_base_ltoa((unsigned int)n, 16, BASE16UC);
	current->arg = 'X';
	plus_minus(temp->str, n, current);
	flags_from_temp(temp, current);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}
