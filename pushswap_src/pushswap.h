/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:23:43 by kzeng             #+#    #+#             */
/*   Updated: 2017/01/04 15:23:44 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# define MAX(x, y) (x > y ? x : y)
# define MIN(x, y) (x > y ? y : x)

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_push_list
{
	int			size;
	int			steps;
	int			i;
	int			j;
	int			num;
	int			smallest;
	int			smallest_counter;
	int			max;
	int			min;
	int			*stack;
	int			*bstack;
	int			llen;
	int			rlen;
	int			len;
	int			neg;
	int			flag;
	int			move;
	int			steps_needed;
	int			stop;
	int			debug;
	int			error;
}				t_push_list;

/*
**	ft_push_find.c
*/
void			ft_find_next_smallest(t_push_list *list);
void			ft_find_smallest(t_push_list *list);
void			ft_find_max(t_push_list *list);
void			ft_find_min(t_push_list *list);
/*
**	ft_push_find2.c
*/
int				ft_find_index(t_push_list *list, int j);
void			ft_find_steps(t_push_list *list);
/*
**	ft_push_helper.c
*/
void			ft_push_initialize(t_push_list **list);
void			ft_find_flag(t_push_list *list);
void			ft_push_print(t_push_list *list);
int				ft_push_atoi(t_push_list *list, char *num);
/*
**	ft_push_helper2.c
*/
int				ft_push_strcmp(char *s1, char *s2);
int				ft_push_strlen(const char *str);
char			**ft_push_strsplit(char const *s, char c);
/*
**	ft_push_helper3.c
*/
int				ft_push_isdigit(int c);
/*
**	ft_push_input_check.c
*/
void			ft_push_read_input(t_push_list *list, char *str);
void			ft_push_store_input(t_push_list *list, char *str);
int				ft_push_check_duplicates(t_push_list *list);
int				ft_sorted(t_push_list *list);
/*
**	ft_push_printf.c
*/
void			ft_push_itoa_base(int value, int base);
void			ft_push_printf(const char *format, ...);
/*
**	ft_push_right.c
*/
void			ft_right_rrr(t_push_list *list);
void			ft_right_rr(t_push_list *list);
void			ft_sort_right(t_push_list *list);
/*
**	ft_push_handle_500.c
*/
void			ft_arrange_left_500(t_push_list *list);
/*
**	ft_push_swap.c
*/
void			ft_arrange_left(t_push_list *list);
void			ft_sort_left(t_push_list *list);
void			ft_arrange_right(t_push_list *list);
void			ft_merge(t_push_list *list);
void			ft_push_swap(t_push_list *list);
/*
**	ft_swap_op.c
*/
void			ft_op_sa(t_push_list *list, int j);
void			ft_op_sb(t_push_list *list, int j);
void			ft_op_ss(t_push_list *list);
void			ft_op_pa(t_push_list *list);
void			ft_op_pb(t_push_list *list);
/*
**	ft_swap_op2.c
*/
void			ft_op_ra(t_push_list *list, int j);
void			ft_op_rb(t_push_list *list, int j);
void			ft_op_rr(t_push_list *list);
/*
**	ft_swap_op3.c
*/
void			ft_op_rra(t_push_list *list, int j);
void			ft_op_rrb(t_push_list *list, int j);
void			ft_op_rrr(t_push_list *list);

#endif
