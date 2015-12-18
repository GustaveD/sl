/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosamon <jrosamon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:31:41 by jrosamon          #+#    #+#             */
/*   Updated: 2015/12/18 12:38:30 by jrosamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_process(t_list *lst, char *opt)
{
	char	max[5];

	if (O_L)
	{
		get_max(lst, max);
	//	ft_print_totaldir(lst);
	}
	ft_print_info(opt, lst, max);
		if (O_A)
			;
}

void	ft_print_totaldir(t_list *lst)
{
	int	total;

	total = 0;
	while (lst)
	{
		total += ((t_info*)lst->content)->stat->st_blocks;
		lst = lst->next;
	}
	if (total > 0)
	{
		ft_putstr("total ");
		ft_putnbr(total);
		ft_putchar('\n');
	}
}

void	ft_print_type(unsigned char type)
{
	if (type == DT_UNKNOWN || type == DT_REG)
		ft_putchar('-');
	else if (type == DT_FIFO)
		ft_putchar('p');
	else if (type == DT_CHR)
		ft_putchar('c');
	else if (type == DT_DIR)
		ft_putchar('d');
	else if (type == DT_BLK)
		ft_putchar('b');
	else if (type == DT_LNK)
		ft_putchar('l');
	else if (type == DT_SOCK)
		ft_putchar('s');
	else
		ft_putchar('-');
}
