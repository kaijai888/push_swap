/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_handle_500.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:55:54 by kzeng             #+#    #+#             */
/*   Updated: 2017/02/06 20:55:55 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int		ft_push_min(t_push_list *list)
{
	int	i;
	int	here;
	int	smallest;

	i = -1;
	here = -1;
	while (++i < list->llen)
	{
		if (here == -1 && list->stack[i] != list->flag)
		{
			smallest = list->stack[i];
			here = i;
		}
		else if (here != -1)
		{
			if (list->stack[i] != list->flag && list->stack[i] < smallest)
			{
				smallest = list->stack[i];
				here = i;
			}
		}
	}
	return (here);
}

static	void	ft_push_index(t_push_list *list, int i)
{
	if (list->i <= (list->llen / 2))
	{
		while (i > 0)
		{
			ft_op_ra(list, 0);
			i--;
		}
		ft_op_pb(list);
	}
	else if (list->i > (list->llen / 2))
	{
		i = list->llen - i;
		while (i > 0)
		{
			ft_op_rra(list, 0);
			i--;
		}
		ft_op_pb(list);
	}
}

void			ft_arrange_left_500(t_push_list *list)
{
	int	i;
	int	j;

	i = 0;
	while (list->llen > 2)
	{
		j = ft_push_min(list);
		ft_push_index(list, j);
		i++;
	}
	if (list->llen == 2)
	{
		if (list->stack[0] > list->stack[1])
			ft_op_sa(list, 0);
	}
	while (i > 0)
	{
		ft_op_pa(list);
		i--;
	}
}
