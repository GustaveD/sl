/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:46:37 by jrosamon          #+#    #+#             */
/*   Updated: 2015/12/07 15:51:17 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_power(int nbr, int power)
{
	int		result;

	if (power < 0)
		return (0);
	result = 1;
	while (power > 0)
	{
		result *= nbr;
		power--;
	}
	return (result);
}

int			ft_power_rec(int nbr, int power)
{
	int		result;

	if (power < 0 )
		return (0);
	result = 1;
	return (ft_power_rec(nbr, power - 1));
}
