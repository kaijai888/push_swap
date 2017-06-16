/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_input_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:46:21 by kzeng             #+#    #+#             */
/*   Updated: 2017/02/02 22:46:22 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_checker_read_input(t_checker_list *list, char *str)
{
	char	**fresh;
	int		j;

	j = 0;
	fresh = ft_checker_strsplit(str, ' ');
	while (fresh[j] != 0 && list->error != 1)
	{
		if (ft_checker_atoi(list, fresh[j]) == -1 && list->num != -1)
			list->error = 1;
		else
			list->size++;
		free(fresh[j]);
		j++;
	}
	free(fresh);
}

void	ft_checker_store_input(t_checker_list *list, char *str)
{
	char	**fresh;
	int		j;

	j = 0;
	fresh = ft_checker_strsplit(str, ' ');
	while (fresh[j] != 0 && list->error != 1)
	{
		if (ft_checker_atoi(list, fresh[j]) == -1 && list->num != -1)
			list->error = 1;
		else
			list->stack[list->llen++] = list->num;
		free(fresh[j]);
		j++;
	}
	free(fresh);
}

void	ft_checker_check_duplicates(t_checker_list *list)
{
	int		i;
	int		loop;
	int		num;

	loop = 0;
	while (loop < list->llen)
	{
		i = loop;
		num = list->stack[i];
		while (++i < list->llen)
		{
			if (num == list->stack[i])
			{
				list->error = 1;
				return ;
			}
		}
		loop++;
	}
}

void	ft_read_line(t_checker_list *list)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_handle_line(line, list) == -1)
		{
			free(line);
			list->error = 1;
			return ;
		}
		free(line);
	}
}

int		ft_handle_line(char *line, t_checker_list *list)
{
	if (ft_checker_strcmp(line, "sa") == 0)
		ft_op_sa(list, 0);
	else if (ft_checker_strcmp(line, "sb") == 0)
		ft_op_sb(list, 0);
	else if (ft_checker_strcmp(line, "ss") == 0)
		ft_op_ss(list);
	else if (ft_checker_strcmp(line, "pa") == 0)
		ft_op_pa(list);
	else if (ft_checker_strcmp(line, "pb") == 0)
		ft_op_pb(list);
	else if (ft_checker_strcmp(line, "ra") == 0)
		ft_op_ra(list, 0);
	else if (ft_checker_strcmp(line, "rb") == 0)
		ft_op_rb(list, 0);
	else if (ft_checker_strcmp(line, "rr") == 0)
		ft_op_rr(list);
	else if (ft_checker_strcmp(line, "rra") == 0)
		ft_op_rra(list, 0);
	else if (ft_checker_strcmp(line, "rrb") == 0)
		ft_op_rrb(list, 0);
	else if (ft_checker_strcmp(line, "rrr") == 0)
		ft_op_rrr(list);
	else
		return (-1);
	return (1);
}
