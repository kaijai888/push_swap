/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 17:31:59 by kzeng             #+#    #+#             */
/*   Updated: 2017/02/01 17:32:01 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_find_next_smallest(t_push_list *list)
{
	int	i;
	int	old;
	int	changed;

	i = -1;
	old = list->smallest;
	changed = 0;
	while (++i < list->llen)
	{
		if (changed == 0 && list->stack[i] > old)
		{
			list->smallest = list->stack[i];
			changed = 1;
		}
		else if (list->stack[i] < list->smallest && list->stack[i] > old)
			list->smallest = list->stack[i];
	}
	i = -1;
	if (list->rlen > 0)
	{
		ft_find_min(list);
		if (list->min < list->smallest && list->min > old)
			list->smallest = list->min;
	}
}

void	ft_find_smallest(t_push_list *list)
{
	int	i;

	i = 0;
	if (list->llen > 0)
		list->smallest = list->stack[i];
	while (++i < list->llen)
	{
		if (list->stack[i] < list->smallest && list->stack[i] != list->flag)
			list->smallest = list->stack[i];
	}
	list->stop = list->smallest;
}

void	ft_find_max(t_push_list *list)
{
	int	i;

	i = 0;
	list->max = list->bstack[i];
	while (++i < list->rlen)
	{
		if (list->bstack[i] > list->max)
			list->max = list->bstack[i];
	}
}

void	ft_find_min(t_push_list *list)
{
	int	i;

	i = 0;
	if (list->rlen > 0)
		list->min = list->bstack[i];
	while (++i < list->rlen)
	{
		if (list->bstack[i] < list->min && list->bstack[i] != list->flag)
			list->min = list->bstack[i];
	}
}
