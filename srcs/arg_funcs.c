/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:26:46 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/11/19 18:47:52 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			text_to_node(t_node *current, char *str, int len)
{
	t_node	*temp;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	temp->str = (ft_strndup(str - len, len));
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}

int			arg_c_to_node(t_node *current, va_list args)
{
	t_node	*temp;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	temp->str = ft_strdup(" ");
	temp->str[0] = va_arg(args, int);
	current->arg = 'c';
	flags_from_temp(temp, current);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}

int			arg_s_to_node(t_node *current, va_list args)
{
	t_node	*temp;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	temp->str = ft_strdup(va_arg(args, char *));
	current->arg = 's';
	flags_from_temp(temp, current);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}

int			arg_p_to_node(t_node *current, va_list args)
{
	t_node	*temp;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	temp->str = ft_base_ltoa(va_arg(args, long long), 16, BASE16LC);
	current->arg = 'p';
	temp->str = address_pre(temp->str);
	flags_from_temp(temp, current);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}

int			arg_d_to_node(t_node *current, va_list args)
{
	t_node	*temp;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	if (current->l_flag == 1)
		temp->str = ft_base_ltoa(va_arg(args, long int),
			10, BASE16LC);
	else if (current->ll_flag == 1)
		temp->str = ft_base_ltoa(va_arg(args, long long int),
			10, BASE16LC);
	else
		temp->str = ft_itoa(va_arg(args, int));
	plus_minus(temp->str, current);
	current->arg = 'd';
	flags_from_temp(temp, current);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}
