/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:28:15 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/11/19 17:33:04 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	exits(int i)
{
	if (i == 1)
	{
		ft_putendl_fd("+ used incorrectly", 1);
		exit(1);
	}
}
