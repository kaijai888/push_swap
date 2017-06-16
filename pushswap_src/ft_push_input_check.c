/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_input_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 17:33:53 by kzeng             #+#    #+#             */
/*   Updated: 2017/02/01 17:33:54 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_push_read_input(t_push_list *list, char *str)
{
	char	**fresh;
	int		j;

	j = 0;
	fresh = ft_push_strsplit(str, ' ');
	while (fresh[j] != 0 && list->error != 1)
	{
		if (ft_push_atoi(list, fresh[j]) == -1 && list->num != -1)
			list->error = 1;
		else
			list->size++;
		j++;
	}
}

void	ft_push_store_input(t_push_list *list, char *str)
{
	char	**fresh;
	int		j;

	j = 0;
	fresh = ft_push_strsplit(str, ' ');
	while (fresh[j] != 0 && list->error != 1)
	{
		if (ft_push_atoi(list, fresh[j]) == -1 && list->num != -1)
			list->error = 1;
		else
			list->stack[list->llen++] = list->num;
		j++;
	}
}

int		ft_push_check_duplicates(t_push_list *list)
{
	int	i;
	int	loop;
	int	num;

	loop = 0;
	while (loop < list->llen)
	{
		i = loop;
		num = list->stack[i];
		while (++i < list->llen)
		{
			if (num == list->stack[i])
				return (1);
		}
		loop++;
	}
	return (0);
}

int		ft_sorted(t_push_list *list)
{
	int	i;
	int	increasing;

	i = 0;
	increasing = 0;
	while (++i <= list->llen - 1)
	{
		if (list->stack[i] > list->stack[i - 1])
			increasing++;
	}
	if ((increasing == list->llen - 1) && list->rlen == 0)
	{
		ft_push_print(list);
		return (1);
	}
	return (0);
}
