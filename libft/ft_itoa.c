/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:47:12 by jrosamon          #+#    #+#             */
/*   Updated: 2015/11/17 17:25:08 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbdiv(int n)
{
	int	cb;

	cb = 1;
	while (n > 9)
	{
		n /= 10;
		cb++;
	}
	return (cb);
}

char		*ft_itoa(int n)
{
	char	*ns;

	ns = ft_strnew(ft_nbdiv(n));
	if (n >= 0 && ns)
	{
		*--ns = '0' + (n % 10);
		n /= 10;
		while (n != 0)
		{
			*--ns = '0' + (n % 10);
			n /= 10;
		}
	}
	else if (ns)
	{
		*--ns = '0' - (n % 10);
		n /= 10;
		while (n != 0)
		{
			*--ns = '0' - (n % 10);
			n /= 10;
		}
		*--ns = '-';
	}
	return (ns);
}
