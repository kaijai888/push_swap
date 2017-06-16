/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 21:49:23 by kzeng             #+#    #+#             */
/*   Updated: 2017/02/02 21:49:25 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	• You have to write a program named push_swap which will receive as an
**	argument the stack a formatted as a list of integers. The first argument
**	should be at the top of the stack (be careful about the order).
**	• The program must display the smallest list of instructions possible to
**	sort the stack a, the smallest number being at the top.
**	• Instructions must be separaed by a ’\n’ and nothing else.
**	• The goal is to sort the stack with the minimum number of operations.
**	During defence we’ll compare the number of instructions your program found
**	with a maximum number of operation tolerated. If your program either
**	displays a list too big or if the list isn’t sorted properly, you’ll get
**	no points.
**	• In case of error, you must display Error followed by a ’\n’ on the
**	standard error. Errors include for example: some arguments aren’t integers,
**	some arguments are bigger than an integer, and/or there are duplicates.
*/

/*
**	#define ANSI_COLOR_RED     "\x1b[31m"
**	#define ANSI_COLOR_GREEN   "\x1b[32m"
**	#define ANSI_COLOR_YELLOW  "\x1b[33m"
**	#define ANSI_COLOR_BLUE    "\x1b[34m"
**	#define ANSI_COLOR_MAGENTA "\x1b[35m"
**	#define ANSI_COLOR_CYAN    "\x1b[36m"
**	#define ANSI_COLOR_RESET   "\x1b[0m"
*/

#include "pushswap.h"

void	ft_arrange_left(t_push_list *list)
{
	if (list->llen == 2 && list->stack[0] != list->stop)
		ft_op_sa(list, 0);
	else if (list->llen == 3)
	{
		if (list->stack[0] == list->stop && list->stack[1] > list->stack[2])
		{
			ft_op_rra(list, 0);
			ft_op_sa(list, 0);
		}
		else if (list->stack[1] == list->stop)
		{
			if (list->stack[0] < list->stack[2])
				ft_op_sa(list, 0);
			else
				ft_op_ra(list, 0);
		}
		else if (list->stack[2] == list->stop)
		{
			if (list->stack[0] > list->stack[1])
				ft_op_sa(list, 0);
			ft_op_rra(list, 0);
		}
	}
}

void	ft_sort_left(t_push_list *list)
{
	int	i;

	i = -1;
	while (++i < list->llen)
	{
		if (list->stack[i] == list->stop)
			break ;
	}
	if (i <= (list->llen / 2))
	{
		while (i > 0)
		{
			ft_op_ra(list, 0);
			i--;
		}
	}
	else if (i > (list->llen / 2))
	{
		i = list->llen - i;
		while (i > 0)
		{
			ft_op_rra(list, 0);
			i--;
		}
	}
}

void	ft_arrange_right(t_push_list *list)
{
	int	i;

	i = 0;
	ft_find_max(list);
	if (list->bstack[0] != list->max)
	{
		i = 0;
		while (list->bstack[i] != list->max)
			i++;
		if (i <= (list->rlen / 2))
		{
			while (list->bstack[0] != list->max)
				ft_op_rb(list, 0);
		}
		else if (i > (list->rlen / 2))
		{
			while (list->bstack[0] != list->max)
				ft_op_rrb(list, 0);
		}
	}
}

void	ft_merge(t_push_list *list)
{
	int	i;
	int	j;
	int	once;

	ft_arrange_right(list);
	i = list->rlen;
	j = -1;
	once = list->llen - 1;
	while (i > 0)
	{
		if (list->stack[list->llen - 1] > list->bstack[0] && once > 0)
		{
			ft_op_rra(list, 0);
			once--;
		}
		else
		{
			ft_op_pa(list);
			i--;
		}
	}
	ft_sort_left(list);
}

void	ft_push_swap(t_push_list *list)
{
	list->i = 0;
	if (ft_sorted(list) == 1)
		return ;
	ft_find_flag(list);
	ft_find_smallest(list);
	if (list->debug == 1)
		ft_push_printf("Start:\n");
	ft_push_print(list);
	ft_sort_right(list);
	if (list->size >= 500)
		ft_arrange_left_500(list);
	else
		ft_arrange_left(list);
	ft_merge(list);
	if (list->debug == 1)
		ft_push_printf("Done: Steps=%d\n", list->steps);
}
