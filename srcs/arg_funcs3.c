/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_funcs3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:41:12 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/11/19 17:41:27 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			arg_percent_to_node(t_node *current)
{
	t_node	*temp;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	temp->str = ft_strdup(" ");
	temp->str[0] = '%';
	current->arg = '%';
	flags_from_temp(temp, current);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}
