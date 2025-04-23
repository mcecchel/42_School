/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:16:21 by mcecchel          #+#    #+#             */
/*   Updated: 2025/04/23 14:58:15 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(t_pipex pipex, char *file, int in_or_out)
{
	int	ret_fd;

	if (in_or_out == 0)
		ret_fd = open(file, O_RDONLY);
	if (in_or_out == 1)
		ret_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ret_fd < 0)
	{
		perror("In or Out -file open failed");
		close_fd_pipe(pipex);
		exit(1);
	}
	return (ret_fd);
}

void	child_process(t_pipex pipex, char **av, char **envp)
{
	pipex.envp = envp;
	pipex.fd_in = open_file(pipex, av[1], 0);
	if (pipex.fd_in < 0)
	{
		perror("Infile open failed");
		exit(1);
	}
	dup2(pipex.fd_in, STDIN_FILENO);
	close(pipex.fd_in);
	dup2(pipex.fd_pipe[1], STDOUT_FILENO);
	close_fd_pipe(pipex);
	execute_cmd(pipex, av[2], envp);
}

void	parent_process(t_pipex pipex, char **av, char **envp)
{
	pipex.envp = envp;
	pipex.fd_out = open_file(pipex, av[4], 1);
	if (pipex.fd_out < 0)
	{
		perror("Outfile open failed");
		exit(1);
	}
	dup2(pipex.fd_out, STDOUT_FILENO);
	close(pipex.fd_out);
	dup2(pipex.fd_pipe[0], STDIN_FILENO);
	close_fd_pipe(pipex);
	execute_cmd(pipex, av[3], envp);
	perror("Execve failed");
	exit(1);
}
