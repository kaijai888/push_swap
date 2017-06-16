/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_op3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:27:51 by kzeng             #+#    #+#             */
/*   Updated: 2017/02/02 22:27:52 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_op_rra(t_checker_list *list, int j)
{
	int	i;
	int	store;

	i = list->llen - 1;
	store = list->llen > 1 ? list->stack[list->llen - 1] : list->stack[0];
	while (i > 0)
	{
		list->stack[i] = list->stack[i - 1];
		i--;
	}
	list->stack[0] = store;
	if (j == 0)
		ft_checker_print(list);
}

void	ft_op_rrb(t_checker_list *list, int j)
{
	int	i;
	int	store;

	i = list->rlen - 1;
	store = list->rlen > 1 ? list->bstack[list->rlen - 1] : list->bstack[0];
	while (i > 0)
	{
		list->bstack[i] = list->bstack[i - 1];
		i--;
	}
	list->bstack[0] = store;
	if (j == 0)
		ft_checker_print(list);
}

void	ft_op_rrr(t_checker_list *list)
{
	ft_op_rra(list, 1);
	ft_op_rrb(list, 1);
	ft_checker_print(list);
}
