/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:27:44 by kzeng             #+#    #+#             */
/*   Updated: 2017/02/02 22:27:45 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_op_sa(t_checker_list *list, int j)
{
	int	a;

	if (list->llen < 2)
	{
		if (j == 0)
			ft_checker_print(list);
		return ;
	}
	a = list->stack[0];
	list->stack[0] = list->stack[1];
	list->stack[1] = a;
	if (j == 0)
		ft_checker_print(list);
}

void	ft_op_sb(t_checker_list *list, int j)
{
	int	b;

	if (list->rlen < 2)
	{
		if (j == 0)
			ft_checker_print(list);
		return ;
	}
	b = list->bstack[0];
	list->bstack[0] = list->bstack[1];
	list->bstack[1] = b;
	if (j == 0)
		ft_checker_print(list);
}

void	ft_op_ss(t_checker_list *list)
{
	ft_op_sa(list, 1);
	ft_op_sb(list, 1);
	ft_checker_print(list);
}

void	ft_op_pa(t_checker_list *list)
{
	int	i;
	int	store;

	if (list->rlen == 0)
	{
		ft_checker_print(list);
		return ;
	}
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
	ft_checker_print(list);
}

void	ft_op_pb(t_checker_list *list)
{
	int	i;
	int	store;

	if (list->llen == 0)
	{
		ft_checker_print(list);
		return ;
	}
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
	ft_checker_print(list);
}
