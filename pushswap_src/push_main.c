/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 21:52:05 by kzeng             #+#    #+#             */
/*   Updated: 2017/02/02 21:52:06 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	handle_push_argc(t_push_list *list, int argc, char **argv)
{
	int			i;

	i = 0;
	while (++i < argc && list->error != 1)
	{
		if (i == 1 && ft_push_strcmp(argv[i], "-v") == 0)
		{
			list->error = argc == 2 ? 1 : 0;
			list->debug = 1;
		}
		else
			ft_push_read_input(list, argv[i]);
	}
	i = list->debug;
	list->stack = (int *)malloc(sizeof(int) * list->size);
	list->bstack = (int *)malloc(sizeof(int) * list->size);
	while (++i < argc && list->error != 1)
		ft_push_store_input(list, argv[i]);
}

int		main(int argc, char **argv)
{
	t_push_list	*list;

	list = (t_push_list *)malloc(sizeof(t_push_list));
	ft_push_initialize(&list);
	handle_push_argc(list, argc, argv);
	if (ft_push_check_duplicates(list) == 1)
		list->error = 1;
	if (list->error == 1)
		ft_push_printf("Error\n");
	else
		ft_push_swap(list);
	free(list->stack);
	free(list->bstack);
	free(list);
	return (0);
}
