/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:42:37 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/14 05:30:37 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	t_file	file;

	if (argc != 5)
		return (1);
	ft_identifier_path(&data, envp);
	init_cmds(argv, &data);
	ft_mk_paths(&data, &data.true_paths1, data.cmds1);
	ft_mk_paths(&data, &data.true_paths2, data.cmds2);
	open_files(&file, argv, argc, &data);
	if (pipe(data.pipe_fd) == -1)
		perror("Failure to create pipe!");
	data.status = forking(&data, &file, envp);
	return (data.status);
}
