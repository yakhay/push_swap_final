/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:31:11 by yakhay            #+#    #+#             */
/*   Updated: 2022/12/27 19:19:47 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

int	ft_doub(t_list *a)
{
	int		i;
	int		c;
	t_list	*b;

	b = a;
	while (b)
	{
		c = b->content;
		a = b;
		i = 0;
		while (a)
		{
			if (c == a->content)
			{
				i++;
				if (i == 2)
					return (-1);
			}
			a = a->next;
		}
		b = b->next;
	}
	return (0);
}

int	ft_check_valid(char **str, t_list **a)
{
	int	j;
	int	k;

	j = 0;
	while (str[j] != NULL)
	{
		k = -1;
		while (str[j][++k])
		{
			if (!(str[j][k] >= 48 && str[j][k] <= 57)
				&& (str[j][k] != '-' && str[j][k] != '+'))
			{
				write(2, "Error\n", 6);
				return (-1);
			}
			if ((str[j][k] == '-' || str[j][k] == '+')
				&& !(str[j][k + 1] >= 48 && str[j][k + 1] <= 57))
			{
				write(2, "Error\n", 6);
				return (-1);
			}
		}
		ft_lstadd_back(a, ft_lstnew(ft_atoi(str[j++])));
	}
	return (0);
}

void	ft_read_line(t_list *a)
{
	char	*st;
	t_list	*b;

	b = NULL;
	while (1)
	{
		st = get_next_line(0);
		if (ft_soort(&a, &b, st) == -1)
		{
			if (st)
			{
				write(2, "Error\n", 6);
				free(st);
				return ;
			}
			free(st);
			break ;
		}
		free(st);
	}
	if (!ft_chek(a) && !ft_lstsize(b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	int		i;
	char	**str;
	t_list	*a;

	if (ac == 1)
		return (0);
	i = 1;
	while (i < ac)
	{
		str = ft_split(av[i++], 32);
		if (str[0] == '\0')
		{
			write(2, "Error\n", 6);
			exit (0);
		}
		if (ft_check_valid(str, &a) == -1)
			exit (0);
		ft_free(str);
	}
	if (ft_doub(a) == -1)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	ft_read_line(a);
}
