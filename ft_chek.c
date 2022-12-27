/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chek.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:51:37 by yakhay            #+#    #+#             */
/*   Updated: 2022/12/27 18:52:03 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chek(t_list *khay)
{
	while (khay->next != NULL)
	{
		if (khay->content > khay->next->content)
			return (1);
		khay = khay->next;
	}
	return (0);
}
