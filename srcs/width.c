/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:16:43 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/11/29 17:32:09 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			check_width(char *str, t_node *current)
{
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	if (current->minus_flag == -1)
		sign = -1;
	while (ft_isdigit(str[i]))
	{
		current->width = current->width * 10 + (str[i] - '0');
		i++;
	}
	current->width = current->width * sign;
	return (i);
}

static void	move_and_free(t_node *current, char *tmp, char *tmp2)
{
	free(current->str);
	free(tmp);
	current->str = tmp2;
}

void		add_width(t_node *current)
{
	int		len;
	int		diff;
	char	*tmp;
	char	*tmp2;
	char	c;

	c = ' ';
	if (current->space == 1 && (is_nb(current->arg) || current->arg == '%') &&
			current->width > 0 && (current->precision_set == 0 || current->arg == 'f'))
		c = '0';
	len = ft_strlen(current->str);
	if (current->width > 0 && current->width > len)
	{
		diff = current->width - len;
		tmp = ft_strnew_c(diff, c);
		tmp2 = ft_strjoin(tmp, current->str);
		move_and_free(current, tmp, tmp2);
	}
	if (current->width < 0 && (-1 * current->width) > len)
	{
		diff = -1 * current->width - len;
		tmp = ft_strnew_c(diff, c);
		tmp2 = ft_strjoin(current->str, tmp);
		move_and_free(current, tmp, tmp2);
	}
}

void		add_precision(t_node *current, int precision)
{
	char	*temp;
	int		diff;
	char	*tmp;
	char	*tmp2;

	temp = current->str;
	if (current->arg == 's' && (int)ft_strlen(current->str) > precision)
	{
		if (precision == 0 && current->width != 0)
			current->str = ft_strdup(" ");
		else
			current->str = ft_strsub(current->str, 0, precision);
		free(temp);
	}
	if (is_nb(current->arg))
	{
		if (current->str[0] == '-' || current->str[0] == '+')
			precision++;
		if (precision == 0 && current->str[0] == '0' && current->plus_flag == 0 && current->arg != 'f')
		{
			current->str = ft_strdup("");
			free(temp);
		}
		if (precision == 1 && current->str[1] == '0' && current->plus_flag == 1)
		{
			current->str = ft_strdup("+");
			free(temp);
		}
		if (precision > (int)ft_strlen(current->str))
		{
			diff = precision - ft_strlen(current->str);
			tmp = ft_strnew_c(diff, '0');
			tmp2 = ft_strjoin(tmp, current->str);
			swap_sign(tmp2);
			move_and_free(current, tmp, tmp2);
		}
	}
}
