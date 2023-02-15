/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:54:56 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/14 04:10:42 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_fstrjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		size;
	char	*str;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[j + i] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free((char *)s1);
	return (str);
}

void	free_arrays(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
	array = NULL;
}

void	free_all(t_data *data)
{
	free_arrays(data->cmds1);
	free_arrays(data->cmds2);
	if (data->true_paths1)
		free(data->true_paths1);
	if (data->true_paths2)
		free(data->true_paths2);
	free_arrays(data->paths);
}

void	parsing_cmd(char *str, char quote, char original, char news)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == quote)
		{
			i++;
			while (str[i] != quote)
			{
				if (str[i] == original)
					str[i] = news;
				i++;
			}
		}
		i++;
	}
}
