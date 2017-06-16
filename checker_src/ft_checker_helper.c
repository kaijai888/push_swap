/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:21:38 by kzeng             #+#    #+#             */
/*   Updated: 2017/02/02 22:21:39 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_checker_initialize(t_checker_list **list)
{
	(*list)->size = 0;
	(*list)->i = 1;
	(*list)->num = 0;
	(*list)->llen = 0;
	(*list)->rlen = 0;
	(*list)->len = 0;
	(*list)->neg = 0;
	(*list)->flag = -2147483648;
	(*list)->debug = 0;
	(*list)->error = 0;
}

void		ft_checker_find_flag(t_checker_list *list)
{
	int		loops;
	int		i;

	loops = 0;
	while (loops < list->llen)
	{
		i = 0;
		while (i < list->llen)
		{
			if (list->stack[i] == list->flag)
			{
				list->flag++;
				break ;
			}
			i++;
		}
		loops++;
	}
	i = 0;
	while (i < list->llen)
		list->bstack[i++] = list->flag;
}

static int	ft_checker_atoi_helper(t_checker_list *list, char *num, int i)
{
	char	*x;
	int		j;

	x = "2147483648";
	j = i - list->neg;
	if (list->len - list->neg == 10)
	{
		if (num[i] > x[j] && list->neg == 1)
			return (-1);
		else if (list->neg == 0)
		{
			if (i == list->len - 1 && num[i] > '7')
				return (-1);
			else if (num[i] > x[j])
				return (-1);
		}
	}
	return (1);
}

int			ft_checker_atoi(t_checker_list *list, char *num)
{
	int		i;

	list->num = 0;
	list->len = ft_checker_strlen(num);
	list->neg = num[0] == '-' ? 1 : 0;
	i = list->neg;
	if (list->len - list->neg > 10)
		return (-1);
	while (i < list->len)
	{
		if (ft_checker_isdigit(num[i]) == 0)
			return (-1);
		else
			list->num = (list->num * 10) + (num[i] - '0');
		if (ft_checker_atoi_helper(list, num, i) == -1)
			return (-1);
		i++;
	}
	list->num = list->neg == 1 ? list->num *= -1 : list->num;
	return (list->num);
}

void		ft_checker_print(t_checker_list *list)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (list->debug == 0)
		return ;
	ft_checker_printf("a: ");
	while (i < list->llen)
	{
		if (list->stack[i] != list->flag)
			ft_checker_printf("%d ", list->stack[i]);
		i++;
	}
	ft_checker_printf("\nb: ");
	while (j < list->rlen)
	{
		if (list->bstack[j] != list->flag)
			ft_checker_printf("%d ", list->bstack[j]);
		j++;
	}
	ft_checker_printf("\n\n");
}
