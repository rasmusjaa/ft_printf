/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:14:48 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/11/11 13:15:07 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_pow(int n, int pow)
{
	int		i;
	float	total;

	i = 1;
	total = n;
	while (i < pow)
	{
		total = total * n;
		i++;
	}
	return (total);
}
