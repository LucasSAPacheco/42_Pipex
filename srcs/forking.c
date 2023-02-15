/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:31:07 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/14 18:14:29 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	process_child(t_data *data, t_file *file)
{
	dup2(file->infile, STD);
	dup2(data->pipe_fd[1], 1);
	close(data->pipe_fd[1]);
	close(data->pipe_fd[0]);
	close(file->infile);
	close(file->outfile);
}

void	process_parent(t_data *data, t_file *file)
{
	dup2(data->pipe_fd[0], 0);
	dup2(file->outfile, 1);
	close(file->infile);
	close(data->pipe_fd[1]);
	close(data->pipe_fd[0]);
	close(file->outfile);
}

int	forking(t_data *data, t_file *file, char **envp)
{
	data->pid = fork();
	if (data->pid == -1)
		perror("Fork failed!");
	if (data->pid == 0)
	{
		process_child(data, file);
		if (!data->error)
			execve(data->true_paths1, data->cmds1, envp);
		free_all(data);
		return (EXIT_FAILURE);
	}
	else
	{
		waitpid(data->pid, NULL, 0);
		process_parent(data, file);
		execve(data->true_paths2, data->cmds2, envp);
		free_all(data);
		return (127);
	}
}
