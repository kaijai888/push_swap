/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_helper3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:22:58 by kzeng             #+#    #+#             */
/*   Updated: 2017/02/02 22:23:02 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char		*ft_checker_strnew(size_t size)
{
	char		*str;
	size_t		i;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_pow(intmax_t value, int base)
{
	int			pow;

	pow = 0;
	while (value != 0)
	{
		value /= base;
		pow++;
	}
	pow--;
	return (pow);
}

static void	ft_checker_itoa_base(int value, int base)
{
	char		*b;
	char		*nbr;
	int			neg;
	int			p;
	intmax_t	n;

	b = "0123456789ABCDEF";
	neg = value < 0 && base == 10 ? 1 : 0;
	n = value;
	if (value == 0)
	{
		write(1, "0", 1);
		return ;
	}
	p = ft_pow(n, base);
	nbr = (char *)malloc(sizeof(char) * (p + neg + 1 + 1));
	nbr[p + neg + 1] = '\0';
	nbr[0] = neg == 1 && base == 10 ? '-' : ' ';
	while (n != 0)
	{
		nbr[p-- + neg] = n < 0 ? b[n % base * -1] : b[n % base];
		n /= base;
	}
	while (nbr[n] != '\0')
		write(1, &nbr[n++], 1);
}

void		ft_checker_printf(const char *format, ...)
{
	va_list		args;
	int			i;

	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == 'd')
		{
			i++;
			ft_checker_itoa_base(va_arg(args, int), 10);
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(args);
}

void		ft_checker(t_checker_list *list)
{
	int		i;
	int		increasing;

	i = 0;
	increasing = 0;
	while (++i <= list->llen - 1)
	{
		if (list->stack[i] > list->stack[i - 1])
			increasing++;
	}
	if ((increasing == list->llen - 1) && list->rlen == 0)
		ft_checker_printf("OK\n");
	else
		ft_checker_printf("KO\n");
}
