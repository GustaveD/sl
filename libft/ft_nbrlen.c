/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:09:28 by jrosamon          #+#    #+#             */
/*   Updated: 2015/12/07 13:11:16 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_nbrlen(int nbr)
{
	unsigned int	len;

	len = (nbr < 0 ) ? 2 : 1;
	while (nbr < -9 || nbr > 9)
	{
		nbr /= 10;
		len ++;
	}	
	return (len);
}
