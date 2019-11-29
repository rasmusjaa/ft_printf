/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:39:03 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/11/29 17:36:26 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"
#include "../libft/incl/libft.h"

int			print_list(t_node *start)
{
	int		total;
	t_node	*temp;

	total = 0;
	temp = start;
	start = start->next;
	free(temp);
	while (start->next != NULL)
	{
		total = total + ft_putstr_ret(start);
		temp = start;
		start = start->next;
		free(temp->str);
		free(temp);
	}
	total = total + ft_putstr_ret(start);
	temp = start;
	start = start->next;
	free(temp->str);
	free(temp);
	return (total);
}

void		default_flags(t_node *current)
{
	current->plus_flag = 0;
	current->minus_flag = 0;
	current->width = 0;
	current->precision = 6;
	current->precision_set = 0;
	current->space = 0;
	current->empty = 0;
	current->hash = 0;
	current->l_flag = 0;
	current->ll_flag = 0;
	current->ucl_flag = 0;
	current->h_flag = 0;
	current->hh_flag = 0;
	current->nb = 0;
	current->float_left = 0.0;
	current->float_right = 0.0;
	current->cnull = 0;
	current->arg = '0';
}

int			check_arg(char **str, va_list args, t_node *current)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	default_flags(current);
	while (j >= 0)
		j = check_flags(str, current);
	while (i < N_TYPES)
	{
		if (g_types[i].c == **str)
			if (g_types[i].func(current, args) == -1)
				return (-1);
		i++;
	}
	if (**str == '%')
		arg_percent_to_node(current);
	(*str)++;
	if (current->arg == '0')
		return (-1);
	return (0);
}

int			parse(char *str, va_list args, t_node *start)
{
	size_t	len;
	t_node	*current;

	current = start;
	while (*str)
	{
		len = 0;
		while (*(str + len) && *(str + len) != '%')
			len++;
		str = str + len;
		if (len > 0)
		{
			if ((text_to_node(current, str, len) == -1))
				return (-1);
			current = current->next;
		}
		if (*(str) == '\0')
			break ;
		++str;
		if ((check_arg(&str, args, current)) == -1)
			return (-1);
		current = current->next;
	}
	return (print_list(start));
}

int			ft_printf(const char *format, ...)
{
	char	*str;
	va_list	args;
	t_node	*start;
	int		rvalue;

	if (!(start = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	start->next = NULL;
	va_start(args, format);
	str = (char *)format;
	if (!str || str[0] == 0)
		return (1);
	rvalue = parse(str, args, start);
	if (rvalue == -1)
		return (1);
	va_end(args);
	return (rvalue);
}
