/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picked_i_or_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 02:34:16 by lsantana          #+#    #+#             */
/*   Updated: 2022/07/24 01:02:10 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	picked_i_or_d(int n, int *count)
{
	char	*new_str;

	new_str = ft_itoa(n);
	ft_putstr_fd(new_str, 1);
	*count += ft_strlen(new_str);
	free(new_str);
}
