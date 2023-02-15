/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picked_ito_low_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 01:53:21 by lsantana          #+#    #+#             */
/*   Updated: 2022/09/10 20:37:05 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	picked_ito_low_hex(unsigned int n, int *count)
{
	*count += 1;
	if (n > 15)
		picked_ito_low_hex(n / 16, count);
	write(1, &LOW_HEX[n % 16], 1);
}
