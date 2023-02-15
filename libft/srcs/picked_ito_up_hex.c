/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picked_ito_up_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:53:45 by lsantana          #+#    #+#             */
/*   Updated: 2022/07/25 18:59:43 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	picked_ito_up_hex(unsigned int n, int *count)
{
	*count += 1;
	if (n > 15)
		picked_ito_up_hex(n / 16, count);
	write(1, &UP_HEX[n % 16], 1);
}
