/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picked_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:43:17 by lsantana          #+#    #+#             */
/*   Updated: 2022/07/24 01:02:40 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	pointer_to_hex(unsigned long int n, int *count)
{
	*count += 1;
	if (n > 15)
		pointer_to_hex(n / 16, count);
	write(1, &"0123456789abcdef"[n % 16], 1);
}

void	picked_pointer(void *c, int *count)
{
	if ((unsigned long int)c)
	{
		*count += 2;
		write(1, "0x", 2);
		pointer_to_hex((unsigned long int)c, count);
	}
	else
	{
		write(1, "(nil)", 5);
		*count += 5;
	}
}
