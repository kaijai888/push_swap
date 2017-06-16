/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:35:06 by kzeng             #+#    #+#             */
/*   Updated: 2017/02/02 17:35:07 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_right_rrr2(t_push_list *list)
{
	while (list->j > 0)
	{
		ft_op_rra(list, 0);
		list->j--;
		list->steps_needed--;
	}
	while (list->i > 0)
	{
		ft_op_rrb(list, 0);
		list->i--;
		list->steps_needed--;
	}
	ft_op_pb(list);
}

void		ft_right_rrr(t_push_list *list)
{
	list->j = MAX(1, list->llen - list->j);
	if (list->i > (list->rlen / 2))
	{
		list->i = MAX(1, list->rlen - list->i);
		while (list->j > 0 && list->i > 0)
		{
			ft_op_rrr(list);
			list->j--;
			list->i--;
			list->steps_needed -= 2;
		}
	}
	else
	{
		while (list->i > 0)
		{
			ft_op_rb(list, 0);
			list->i--;
			list->steps_needed--;
		}
	}
	ft_right_rrr2(list);
}

static void	ft_right_rr2(t_push_list *list)
{
	while (list->j > 0)
	{
		ft_op_ra(list, 0);
		list->j--;
		list->steps_needed--;
	}
	while (list->i > 0)
	{
		ft_op_rb(list, 0);
		list->i--;
		list->steps_needed--;
	}
	ft_op_pb(list);
}

void		ft_right_rr(t_push_list *list)
{
	if (list->i <= (list->rlen / 2))
	{
		while (list->j > 0 && list->i > 0)
		{
			ft_op_rr(list);
			list->j--;
			list->i--;
			list->steps_needed -= 2;
		}
	}
	else
	{
		list->i = MAX(1, list->rlen - list->i);
		while (list->i > 0)
		{
			ft_op_rrb(list, 0);
			list->i--;
			list->steps_needed--;
		}
	}
	ft_right_rr2(list);
}

void		ft_sort_right(t_push_list *list)
{
	int	x;

	x = list->size >= 500 ? 7 : 0;
	while (list->llen > 3 + x)
	{
		if (list->stack[0] == list->smallest && list->smallest_counter < 3 + x)
		{
			list->smallest_counter++;
			ft_op_ra(list, 0);
			if (list->smallest_counter < (3 + x))
				ft_find_next_smallest(list);
		}
		else
		{
			ft_find_steps(list);
			if (list->steps + list->steps_needed + 550 > 5300)
				break ;
			list->j = list->move;
			list->i = ft_find_index(list, list->j);
			if (list->j <= (list->llen / 2))
				ft_right_rr(list);
			else
				ft_right_rrr(list);
		}
	}
}
