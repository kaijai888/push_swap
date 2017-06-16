/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_find2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 21:56:19 by kzeng             #+#    #+#             */
/*   Updated: 2017/02/02 21:56:20 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int			ft_find_index(t_push_list *list, int j)
{
	int	i;

	i = 0;
	ft_find_max(list);
	ft_find_min(list);
	while (i < list->rlen)
	{
		if (list->stack[j] > list->bstack[i])
		{
			if (i == 0)
			{
				if (list->rlen == 0 ||
					list->stack[j] < list->bstack[list->rlen - 1] ||
					list->bstack[0] == list->max)
					break ;
			}
			else if ((list->stack[j] < list->bstack[i - 1]) ||
				(list->stack[j] > list->max && list->bstack[i] == list->max))
				break ;
		}
		else if (list->stack[j] < list->min && list->bstack[i] == list->max)
			break ;
		i++;
	}
	return (i);
}

static void	ft_find_steps_helper(t_push_list *list, int j)
{
	int	i;

	i = ft_find_index(list, j);
	list->steps_needed = 0;
	if (i <= (list->rlen / 2))
	{
		if (j <= (list->llen / 2))
			list->steps_needed += MAX(i, j);
		else
		{
			list->steps_needed += i;
			list->steps_needed += MAX(1, list->llen - j);
		}
	}
	else
	{
		if (j > (list->llen / 2))
			list->steps_needed += MAX(MAX(1, list->rlen - i),
				MAX(1, list->llen - j));
		else
		{
			list->steps_needed += j;
			list->steps_needed += MAX(1, list->rlen - i);
		}
	}
}

/*
**	To debug with find steps
**	ft_push_printf("move:%d index[j]:%d to index[i]:%d steps:%d\n",
**	list->stack[j], j, i, list->steps);
*/

void		ft_find_steps(t_push_list *list)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = -1;
	tmp = 5000;
	while (++j < list->llen)
	{
		if (list->stack[j] > list->smallest)
		{
			ft_find_steps_helper(list, j);
			if (list->steps_needed < tmp)
			{
				list->move = j;
				if ((tmp = list->steps_needed) == 0)
					return ;
			}
		}
	}
}
