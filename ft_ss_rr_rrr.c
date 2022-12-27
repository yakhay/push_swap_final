/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss_rr_rrr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:27:30 by yakhay            #+#    #+#             */
/*   Updated: 2022/12/27 18:57:40 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **a, t_list **b)
{
	sa(a, 3);
	sa(b, 3);
}

void	rr(t_list **a, t_list **b)
{
	ra(a, 3);
	ra(b, 3);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a, 3);
	rra(b, 3);
}

int	ft_strcmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		res;

	res = 0;
	i = 0;
	if (!s1)
		return (-1);
	while (i < n)
	{
		res = s1[i] - s2[i];
		if (res != 0)
			return (res);
		i++;
	}
	return (res);
}

int	ft_soort(t_list **a, t_list **b, char *str)
{
	if (ft_strcmp(str, "sa\n", 3) == 0)
		sa(a, 3);
	else if (ft_strcmp(str, "sb\n", 3) == 0)
		sa(b, 3);
	else if (ft_strcmp(str, "ra\n", 3) == 0)
		ra(a, 3);
	else if (ft_strcmp(str, "rb\n", 3) == 0)
		ra(b, 3);
	else if (ft_strcmp(str, "pa\n", 3) == 0)
		pa(a, b, 3);
	else if (ft_strcmp(str, "pb\n", 3) == 0)
		pa(b, a, 3);
	else if (ft_strcmp(str, "rra\n", 4) == 0)
		rra(a, 3);
	else if (ft_strcmp(str, "rrb\n", 4) == 0)
		rra(b, 3);
	else if (ft_strcmp(str, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strcmp(str, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strcmp(str, "rrr\n", 4) == 0)
		rrr(a, b);
	else
		return (-1);
	return (0);
}
