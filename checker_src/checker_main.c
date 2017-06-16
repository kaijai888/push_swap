/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:19:01 by kzeng             #+#    #+#             */
/*   Updated: 2017/02/02 22:19:02 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**	• You have to write a program named checker, which will get as an argument
**	the stack a formatted as a list of integers. The first argument should be
**	at the top of the stack (be careful about the order). If no argument is
**	given checker stops and displays nothing.
**	• Checker will then wait and read instructions on the standard input, each
**	instruction will be followed by ’\n’. Once all the instructions have been
**	read, checker will execute them on the stack received as an argument.
**	• If after executing those instructions, stack a is actually sorted and
**	b is empty, then checker must display "OK" followed by a ’\n’ on the
**	standard output. In every other case, checker must display "KO" followed by
**	a ’\n’ on the standard output.
**	• In case of error, you must display Error followed by a ’\n’ on the
**	standard error. Errors include for example: some arguments are not
**	integers, some arguments are bigger than an integer, there are duplicates,
**	an instruction don’t exist and/or is incorrectly formatted.
*/

void	handle_checker_argc(t_checker_list *list, int argc, char **argv)
{
	int				i;

	i = 0;
	while (++i < argc && list->error != 1)
	{
		if (i == 1 && ft_checker_strcmp(argv[1], "-v") == 0)
		{
			list->error = argc == 2 ? 1 : 0;
			list->debug = 1;
		}
		else
			ft_checker_read_input(list, argv[i]);
	}
	i = list->debug;
	list->stack = (int *)malloc(sizeof(int) * list->size);
	list->bstack = (int *)malloc(sizeof(int) * list->size);
	while (++i < argc && list->error != 1)
		ft_checker_store_input(list, argv[i]);
	ft_checker_find_flag(list);
}

int		main(int argc, char **argv)
{
	t_checker_list	*list;

	list = (t_checker_list *)malloc(sizeof(t_checker_list));
	ft_checker_initialize(&list);
	if (argc == 1)
		return (0);
	handle_checker_argc(list, argc, argv);
	ft_checker_check_duplicates(list);
	if (list->error == 0)
		ft_read_line(list);
	if (list->error == 1)
		ft_checker_printf("Error\n");
	else
		ft_checker(list);
	free(list->stack);
	free(list->bstack);
	free(list);
	return (0);
}
