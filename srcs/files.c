/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 06:29:39 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/14 18:26:28 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	open_files(t_file *file, char **argv, int argc, t_data *data)
{
	data->error = 0;
	open_infile(file, argv, data);
	open_outfile(file, argv, argc, data);
}

void	open_infile(t_file *file, char **argv, t_data *data)
{
	file->infile = open(argv[1], O_RDONLY);
	if (file->infile == -1)
	{
		write(2, "bash: ", 6);
		perror(argv[1]);
		data->error = -1;
		file->infile = open("/dev/null", O_RDONLY);
	}
}

void	open_outfile(t_file *file, char **argv, int argc, t_data *data)
{
	file->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (file->outfile == -1)
	{
		write(2, "bash: ", 6);
		perror(argv[4]);
		free_all(data);
		exit (EXIT_FAILURE);
	}
}
