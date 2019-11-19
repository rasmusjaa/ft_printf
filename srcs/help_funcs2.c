/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:38:29 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/11/19 18:07:40 by rjaakonm         ###   ########.fr       */
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
		if (str[i] == '-' || str[i] == '+')
		{
			str[0] = str[i];
			str[i] = '0';
		}
	}
}

char					*decimal_ftoa(double nb, int acc)
{
	char				*str;
	char				*tmp1;
	char				*tmp2;
	int					i;
	unsigned long long	n;

	i = 0;
	str = (char *)malloc(sizeof(char) * (acc + 1));
	if (!str)
		return (NULL);
	n = (unsigned long long)(nb * ft_pow(10, acc) + 0.5);
	str = ft_base_ltoa(n, 10, BASE16LC);
	if (ft_strlen(str) < (size_t)acc)
	{
		tmp1 = ft_strnew_c(acc - ft_strlen(str), '0');
		tmp2 = str;
		str = ft_strjoin(tmp1, tmp2);
		free(tmp1);
		free(tmp2);
	}
	return (str);
}

char					*ft_ftoa(double nb, int acc)
{
	unsigned long long	n;
	char				*s1;
	char				*s2;
	char				*dbl;
	char				sign[2];

	sign[0] = 0;
	sign[1] = 0;
	if (nb < 0)
	{
		sign[0] = '-';
		nb = nb * -1;
	}
	n = (unsigned long long)nb;
	s1 = ft_base_ltoa(n, 10, BASE16LC);
	nb = nb - n;
	s2 = decimal_ftoa(nb, acc);
	if (acc <= 0)
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
