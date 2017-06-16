/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_op3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:23:34 by kzeng             #+#    #+#             */
/*   Updated: 2017/02/02 17:23:37 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
**	sa : swap a - swap the first 2 elements at the top of stack a.
**		Do nothing if there is only one or no elements).
**	sb : swap b - swap the first 2 elements at the top of stack b.
**		Do nothing if there is only one or no elements).
**	ss : sa and sb at the same time.
**	pa : push a - take the first element at the top of b and put it at the
**			top of a. Do nothing if b is empty.
**	pb : push b - take the first element at the top of a and put it at the
**			top of b. Do nothing if a is empty.
**	ra : rotate a - shift up all elements of stack a by 1. The first element
**			becomes the last one.
**	rb : rotate b - shift up all elements of stack b by 1. The first element
**			becomes the last one.
**	rr : ra and rb at the same time.
**	rra : reverse rotate a - shift down all elements of stack a by 1. The last
** 			element becomes the first one.
**	rrb : reverse rotate b - shift down all elements of stack b by 1. The last
**			element becomes the first one.
**	rrr : rra and rrb at the same time.
*/

void	ft_op_rra(t_push_list *list, int j)
{
	int	i;
	int	store;

	if (j == 0)
		ft_push_printf("rra\n");
	i = list->llen - 1;
	store = list->llen > 1 ? list->stack[list->llen - 1] : list->stack[0];
	while (i > 0)
	{
		list->stack[i] = list->stack[i - 1];
		i--;
	}
	list->stack[0] = store;
	list->steps++;
	if (j == 0)
		ft_push_print(list);
}

void	ft_op_rrb(t_push_list *list, int j)
{
	int	i;
	int	store;

	if (j == 0)
		ft_push_printf("rrb\n");
	i = list->rlen - 1;
	store = list->rlen > 1 ? list->bstack[list->rlen - 1] : list->bstack[0];
	while (i > 0)
	{
		list->bstack[i] = list->bstack[i - 1];
		i--;
	}
	list->bstack[0] = store;
	list->steps++;
	if (j == 0)
		ft_push_print(list);
}

void	ft_op_rrr(t_push_list *list)
{
	ft_push_printf("rrr\n");
	ft_op_rra(list, 1);
	ft_op_rrb(list, 1);
	ft_push_print(list);
	list->steps--;
}
