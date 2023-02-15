/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picked_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 02:53:30 by lsantana          #+#    #+#             */
/*   Updated: 2022/07/24 01:03:05 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_check_size_u(unsigned int n)
{
	unsigned int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_uitoa(unsigned int n)
{
	char				*new_str;
	unsigned int		i;

	i = ft_check_size_u(n);
	new_str = (char *)malloc(sizeof(char) * ft_check_size_u(n) + 1);
	if (!new_str)
		return (NULL);
	new_str[i] = 0;
	while (n > 9)
	{
		new_str[--i] = ((n % 10) + '0');
		n /= 10;
	}
	if (n <= 9)
		new_str[i - 1] = n + '0';
	return (new_str);
}

void	picked_u(unsigned int n, int *count)
{
	char	*new_str;

	new_str = ft_uitoa(n);
	*count += ft_strlen(new_str);
	ft_putstr_fd(new_str, 1);
	free(new_str);
}
