/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:04:59 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/14 18:23:42 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./libft/ft_printf.h"

typedef struct p_data {
	char			**cmds1;
	char			**cmds2;
	char			**paths;
	char			*true_paths1;
	char			*true_paths2;
	int				pipe_fd[2];
	pid_t			pid;
	int				error;
	int				status;
}	t_data;

typedef struct p_file {
	int		infile;
	int		outfile;
}	t_file;

void	ft_identifier_path(t_data *data, char **envp);
char	*ft_fstrjoin(char const *s1, char const *s2);
void	ft_mk_paths(t_data *data, char **true_path, char **cmd);
void	ft_mk_cmds(char *argv, t_data *data);
void	init_cmds(char **argv, t_data *data);
void	open_files(t_file *file, char **argv, int argc, t_data *data);
void	free_all(t_data *data);
void	free_arrays(char **array);
void	parsing_cmd(char *str, char quote, char original, char news);
void	open_infile(t_file *file, char **argv, t_data *data);
void	open_outfile(t_file *file, char **argv, int argc, t_data *data);
char	*ft_fstrtrim(char const *s1, char const *set);
void	process_child(t_data *data, t_file *file);
void	process_parent(t_data *data, t_file *file);
int		forking(t_data *data, t_file *file, char **envp);

#endif