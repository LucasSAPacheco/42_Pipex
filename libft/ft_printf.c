/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:17:03 by lsantana          #+#    #+#             */
/*   Updated: 2022/09/10 20:22:13 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	percent_exception(char str, int *count)
{
	if (str)
	{
		*count += 2;
		write(1, "%", 1);
		write(1, &str, 1);
	}
	else
		*count = -1;
}

static void	check_specifier(const char *str, va_list list, int *count)
{
	if (*str == 'c')
		picked_char(va_arg(list, int), count);
	else if (*str == 's')
		picked_str(va_arg(list, char *), count);
	else if (*str == 'X')
		picked_ito_up_hex(va_arg(list, int), count);
	else if (*str == 'x')
		picked_ito_low_hex(va_arg(list, int), count);
	else if (*str == 'i' || *str == 'd')
		picked_i_or_d(va_arg(list, int), count);
	else if (*str == 'u')
		picked_u(va_arg(list, unsigned int), count);
	else if (*str == 'p')
		picked_pointer(va_arg(list, void *), count);
	else if (*str == '%')
		picked_char('%', count);
	else
		percent_exception(*str, count);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		count;

	count = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			check_specifier(str, list, &count);
		}
		else
		{
			write(1, str, 1);
			count++;
		}
		if (*str)
			str++;
	}
	va_end(list);
	return (count);
}
