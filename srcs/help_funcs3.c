/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:11:46 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/11/27 18:59:35 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void		add_empty(t_node *temp, t_node *current)
{
	char	*tmp;
	int 	i;

	if (current->arg == 'd')
	{
		if (temp->str[0] != '-' && temp->str[0] != '+')
		{
			tmp = temp->str;
			temp->str = ft_strjoin(" ", tmp);
			free(tmp);
		}
	}
	if (current->arg == 'f')
	{
		if (temp->str[0] != '-' && temp->str[0] != '+' && temp->str[0] != ' ')
		{
			if (temp->str[0] == '0')
				temp->str[0] = ' ';
			else
			{
				tmp = temp->str;
				temp->str = ft_strjoin(" ", tmp);
				free(tmp);
				i = 0;
				while (temp->str[i])
					i++;
				if (temp->str[i - 1] == ' ')
					temp->str[i - 1] = 0;
			}
		}
	}
}
