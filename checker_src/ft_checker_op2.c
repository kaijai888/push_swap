/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_op2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:27:48 by kzeng             #+#    #+#             */
/*   Updated: 2017/02/02 22:27:49 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_op_ra(t_checker_list *list, int j)
{
	int	i;
	int	store;

	i = 0;
	store = list->stack[0];
	while (i < list->llen - 1)
	{
		list->stack[i] = list->stack[i + 1];
		i++;
	}
	if (list->llen > 1)
		list->stack[list->llen - 1] = store;
	if (j == 0)
		ft_checker_print(list);
}

void	ft_op_rb(t_checker_list *list, int j)
{
	int	i;
	int	store;

	i = 0;
	store = list->bstack[0];
	while (i < list->rlen - 1)
	{
		list->bstack[i] = list->bstack[i + 1];
		i++;
	}
	if (list->rlen > 1)
		list->bstack[list->rlen - 1] = store;
	if (j == 0)
		ft_checker_print(list);
}

void	ft_op_rr(t_checker_list *list)
{
	ft_op_ra(list, 1);
	ft_op_rb(list, 1);
	ft_checker_print(list);
}
