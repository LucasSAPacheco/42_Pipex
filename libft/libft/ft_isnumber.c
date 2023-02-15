/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:15:35 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/14 04:06:28 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(const char *s)
{
	int	verify;

	verify = 0;
	if (s[ft_strlen(s) - 1] == '.')
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	if (*s == '.')
		return (0);
	while (*s)
	{
		if (*s == '.')
			verify++;
		if (verify > 1)
			return (0);
		if (!ft_isdigit(*s) && *s != '.' && *s)
			return (0);
		s++;
	}
	return (1);
}
