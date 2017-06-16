/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:21:26 by kzeng             #+#    #+#             */
/*   Updated: 2017/02/02 17:21:27 by kzeng            ###   ########.fr       */
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

void	ft_op_sa(t_push_list *list, int j)
{
	int	a;

	if (j == 0)
		ft_push_printf("sa\n");
	list->steps++;
	if (list->llen < 2)
	{
		ft_push_print(list);
		return ;
	}
	a = list->stack[0];
	list->stack[0] = list->stack[1];
	list->stack[1] = a;
	if (j == 0)
		ft_push_print(list);
}

void	ft_op_sb(t_push_list *list, int j)
{
	int	b;

	if (j == 0)
		ft_push_printf("sb\n");
	list->steps++;
	if (list->rlen < 2)
	{
		ft_push_print(list);
		return ;
	}
	b = list->bstack[0];
	list->bstack[0] = list->bstack[1];
	list->bstack[1] = b;
	if (j == 0)
		ft_push_print(list);
}

void	ft_op_ss(t_push_list *list)
{
	ft_push_printf("ss\n");
	ft_op_sa(list, 1);
	ft_op_sb(list, 1);
	ft_push_print(list);
	list->steps--;
}

void	ft_op_pa(t_push_list *list)
{
	int	i;
	int	store;

	ft_push_printf("pa\n");
	i = list->llen;
	store = list->bstack[0];
	list->bstack[0] = list->flag;
	ft_op_rb(list, 1);
	while (i > 0)
	{
		list->stack[i] = list->stack[i - 1];
		i--;
	}
	list->stack[0] = store;
	list->llen++;
	list->rlen--;
	ft_push_print(list);
}

void	ft_op_pb(t_push_list *list)
{
	int	i;
	int	store;

	ft_push_printf("pb\n");
	i = list->rlen;
	store = list->stack[0];
	list->stack[0] = list->flag;
	ft_op_ra(list, 1);
	while (i > 0)
	{
		list->bstack[i] = list->bstack[i - 1];
		i--;
	}
	list->bstack[0] = store;
	list->llen--;
	list->rlen++;
	ft_push_print(list);
}
