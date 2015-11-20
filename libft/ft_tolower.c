/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:05:43 by jrosamon          #+#    #+#             */
/*   Updated: 2014/11/07 16:57:44 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return ('a' + c - 'A');
	else
		return (c);
}
