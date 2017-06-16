/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:43:32 by kzeng             #+#    #+#             */
/*   Updated: 2017/01/24 15:43:33 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define MAX(x, y) (x > y ? x : y)
# define MIN(x, y) (x > y ? y : x)
# define BUFF_SIZE 16
# define MAX_FD 4096
# define MALLOC_CHECK(x) if (x == NULL) {return (-1);}
# define READ_CHECK(x) if (x == -1) {free(buf); return (-1);}

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_checker_list
{
	int			size;
	int			i;
	int			num;
	int			*stack;
	int			*bstack;
	int			llen;
	int			rlen;
	int			len;
	int			neg;
	int			flag;
	int			debug;
	int			error;
}				t_checker_list;
/*
**	ft_checker_helper.c
*/
void			ft_checker_initialize(t_checker_list **list);
void			ft_checker_find_flag(t_checker_list *list);
int				ft_checker_atoi(t_checker_list *list, char *num);
void			ft_checker_print(t_checker_list *list);
/*
**	ft_checker_helper2.c
*/
int				ft_checker_isdigit(int c);
int				ft_checker_strcmp(char *s1, char *s2);
char			*ft_checker_strcpy(char *dst, char *src);
char			*ft_checker_strdup(const char *s1);
size_t			ft_checker_strlen(const char *str);
/*
**	ft_checker_helper3.c
*/
char			*ft_checker_strnew(size_t size);
void			ft_checker_printf(const char *format, ...);
void			ft_checker(t_checker_list *list);
/*
**	ft_checker_helper4.c
*/
char			**ft_checker_strsplit(char const *s, char c);
char			*ft_checker_strsub(char *s, unsigned int start, size_t len);
char			*ft_checker_strncat(char *s1, char *s2, size_t n);
/*
**	ft_checker_input_check.c
*/
void			ft_checker_read_input(t_checker_list *list, char *str);
void			ft_checker_store_input(t_checker_list *list, char *str);
void			ft_checker_check_duplicates(t_checker_list *list);
void			ft_read_line(t_checker_list *list);
int				ft_handle_line(char *line, t_checker_list *list);
/*
**	get_next_line.c
*/
int				get_next_line(const int fd, char **line);
/*
**	ft_checker_op.c
*/
void			ft_op_sa(t_checker_list *list, int j);
void			ft_op_sb(t_checker_list *list, int j);
void			ft_op_ss(t_checker_list *list);
void			ft_op_pa(t_checker_list *list);
void			ft_op_pb(t_checker_list *list);
/*
**	ft_checker_op2.c
*/
void			ft_op_ra(t_checker_list *list, int j);
void			ft_op_rb(t_checker_list *list, int j);
void			ft_op_rr(t_checker_list *list);
/*
**	ft_checker_op3.c
*/
void			ft_op_rra(t_checker_list *list, int j);
void			ft_op_rrb(t_checker_list *list, int j);
void			ft_op_rrr(t_checker_list *list);

#endif
