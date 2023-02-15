/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:40:12 by lsantana          #+#    #+#             */
/*   Updated: 2022/11/17 22:43:06 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_identifier_path(t_data *data, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			data->paths = ft_split(envp[i] + 5, ':');
			break ;
		}
		i++;
	}
}

void	ft_mk_paths(t_data *data, char **true_path, char **cmd)
{
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	while (data->paths[i])
	{
		temp = ft_strjoin(data->paths[i], "/");
		temp = ft_fstrjoin(temp, cmd[0]);
		if (!access(temp, F_OK))
		{
			*true_path = temp;
			return ;
		}
		i++;
		free(temp);
	}
	*true_path = NULL;
}

void	init_cmds(char **argv, t_data *data)
{
	int	i;

	i = 0;
	parsing_cmd(argv[2], '\'', ' ', 1);
	parsing_cmd(argv[3], '\'', ' ', 1);
	data->cmds1 = ft_split(argv[2], ' ');
	data->cmds2 = ft_split(argv[3], ' ');
	while (data->cmds1[i])
	{
		parsing_cmd(data->cmds1[i], '\'', 1, ' ');
		if (data->cmds1[i][0] == '\'')
			data->cmds1[i] = ft_fstrtrim(data->cmds1[i], "'");
		i++;
	}
	i = 0;
	while (data->cmds2[i])
	{
		parsing_cmd(data->cmds2[i], '\'', 1, ' ');
		if (data->cmds2[i][0] == '\'')
			data->cmds2[i] = ft_fstrtrim(data->cmds2[i], "'");
		i++;
	}
}
