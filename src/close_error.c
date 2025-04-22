/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:44:02 by mcecchel          #+#    #+#             */
/*   Updated: 2025/04/22 17:12:06 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_exec_error(t_pipex pipex, char **command, char *path)
{
    free_split(command);
    free(path);
    close_fd_pipe(pipex);
    close_fd(pipex);
    exit(1);
}

void	close_fd(t_pipex pipex)
{
	if (pipex.fd_in > 0)
		close(pipex.fd_in);
	if (pipex.fd_out > 0)
		close(pipex.fd_out);
}

void	close_fd_pipe(t_pipex pipex)
{
	if (pipex.fd_pipe[0] > 0)
		close(pipex.fd_pipe[0]);
	if (pipex.fd_pipe[1] > 0)
		close(pipex.fd_pipe[1]);
}
