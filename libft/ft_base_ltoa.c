/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_ltoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:13:20 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/11/13 16:43:54 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_base_ltoa(long long n, int base, char *chararr)
{
	long long	nb;
	char		*res;
	int			chars;

	nb = (long long)n;
	chars = ft_longlong_numbercount(n, base);
	if (!(res = (char*)malloc(sizeof(char) * (chars + 1))))
		return (NULL);
	if (nb < 0)
	{
		nb = nb * -1;
		res[0] = '-';
	}
	res[chars] = '\0';
	chars--;
	while (nb > (base - 1))
	{
		res[chars] = chararr[nb % base];
		nb = nb / (long long)base;
		chars--;
	}
	res[chars] = chararr[nb % base];
	return (res);
}
