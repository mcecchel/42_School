/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:53:49 by mcecchel          #+#    #+#             */
/*   Updated: 2025/04/23 15:11:42 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_processes(t_pipex pipex, char **av, char **envp)
{
	pipex.child_1 = fork();
	if (pipex.child_1 < 0)
	{
		perror("Fork failed");
		exit(1);
	}
	if (pipex.child_1 == 0)
		child_process(pipex, av, envp);
	pipex.child_2 = fork();
	if (pipex.child_2 < 0)
	{
		perror("Fork failed");
		exit(1);
	}
	if (pipex.child_2 == 0)
		parent_process(pipex, av, envp);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	int		status;

	pipex = (t_pipex){0};
	if (ac != 5)
	{
		perror("Error: Wrong number of arguments");
		exit(1);
	}
	if (pipe(pipex.fd_pipe) == -1)
	{
		perror("Pipe failed");
		close_fd_pipe(pipex);
		exit (1);
	}
	fork_processes(pipex, av, envp);
	close_fd_pipe(pipex);
	close_fd(pipex);
	waitpid(pipex.child_1, NULL, 0);
	waitpid(pipex.child_2, &status, 0);
	clean_all(pipex);
	return (0);
}
