/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:52:02 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/11/29 17:34:53 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_types g_types[N_TYPES] =
{
	{'c', arg_c_to_node},
	{'s', arg_s_to_node},
	{'p', arg_p_to_node},
	{'d', arg_d_to_node},
	{'i', arg_d_to_node},
	{'o', arg_o_to_node},
	{'u', arg_u_to_node},
	{'x', arg_x_to_node},
	{'X', arg_ucx_to_node},
	{'f', arg_f_to_node},
};

int			ft_putstr_ret(t_node *current)
{
	int		i;
	char	*s;

	i = 0;
	s = current->str;
	if (current->arg == 'c')
	{
		while (s[i])
		{
			if (current->cnull == 1 && s[i] == 'x')
				s[i] = '\0';
			i++;
		}
		write(1, s, i);
	}
	else
	{
		while (s[i])
		{
			i++;
		}
		write(1, s, i);
	}
	return (i);
}

char		*ft_strndup(const char *s, int len)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i] && i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strnew_c(size_t size, char c)
{
	char	*string;
	size_t	i;

	i = 0;
	if (!(string = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		string[i] = c;
		i++;
	}
	string[i] = 0;
	return (string);
}

char		*trim_n_first(int n, char *str)
{
	char	*tmp;

	tmp = ft_strdup(&str[n]);
	free(str);
	str = tmp;
	return (str);
}
