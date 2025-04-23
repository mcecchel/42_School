/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:44:02 by mcecchel          #+#    #+#             */
/*   Updated: 2025/04/23 15:26:22 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_exec_error(t_pipex pipex, char **command, char *path)
{
	free_split(command);
	free(path);
	close_fd(pipex);
	close_fd_pipe(pipex);
	exit(1);
}

void	close_fd(t_pipex pipex)
{
	if (pipex.fd_in != -1)
		close(pipex.fd_in);
	if (pipex.fd_out != -1)
		close(pipex.fd_out);
	close(0);
	close(1);
}

void	close_fd_pipe(t_pipex pipex)
{
	if (pipex.fd_pipe[0] != -1)
		close(pipex.fd_pipe[0]);
	if (pipex.fd_pipe[1] != -1)
		close(pipex.fd_pipe[1]);
}
