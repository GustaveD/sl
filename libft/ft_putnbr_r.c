/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 16:56:19 by jrosamon          #+#    #+#             */
/*   Updated: 2015/12/19 17:36:01 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_r(int n, int lenght)
{
	char	*res;
	int		i;

	res = ft_itoa(n);
	i = lenght - ft_strlen(res);
	if (i == 0)
		ft_putstr(res);
	else
	{
		while (i > 0)
		{
			ft_putchar(' ');
			i--;
		}
		ft_putstr(res);
	}
}
