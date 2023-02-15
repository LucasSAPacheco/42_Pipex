/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picked_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:29:25 by lsantana          #+#    #+#             */
/*   Updated: 2022/07/24 01:02:50 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	picked_str(char *str, int *count)
{
	if (str == NULL)
	{
		str = ft_strdup("(null)");
		*count += ft_strlen(str);
		ft_putstr_fd(str, 1);
		free(str);
	}
	else
	{
		*count += ft_strlen(str);
		ft_putstr_fd(str, 1);
	}
}
