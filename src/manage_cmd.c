/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:33:47 by mcecchel          #+#    #+#             */
/*   Updated: 2025/04/23 15:25:31 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_valid_command(t_pipex pipex, char *cmd)
{
	if (cmd == NULL || *cmd == '\0' || find_spaces(*cmd) == 1)
	{
		perror("Error: Invalid command");
		if (pipex.fd_in != -1)
			close(pipex.fd_in);
		if (pipex.fd_out != -1)
			close(pipex.fd_out);
		return (0);
	}
	return (1);
}

char	**get_paths(t_pipex pipex)
{
	char	*path_env;
	char	**paths;

	path_env = find_env_path(pipex);
	if (!path_env)
	{
		perror("Error: Failed to find path");
		return (NULL);
	}
	paths = ft_split(path_env, ':');
	if (!paths)
		perror("Error: Failed to split path");
	return (paths);
}

char	*search_command(char **paths, char *cmd)
{
	char	*temp;
	char	*full_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			free_split(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(t_pipex pipex, char *cmd)
{
	char	**paths;
	char	*full_path;

	if (!is_valid_command(pipex, cmd))
		return (NULL);
	if (access(cmd, F_OK | X_OK) == 0 && ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	paths = get_paths(pipex);
	if (!paths)
		return (NULL);
	full_path = search_command(paths, cmd);
	return (full_path);
}

void	execute_cmd(t_pipex pipex, char *av, char **envp)
{
	char	**command;
	char	*path;

	pipex.envp = envp;
	command = ft_split(av, ' ');
	if (!command)
	{
		perror("Command not found");
		close_fd(pipex);
		exit(1);
	}
	path = get_cmd_path(pipex, command[0]);
	if (!path)
	{
		free_split(command);
		close_fd(pipex);
		exit(1);
	}
	execve(path, command, envp);
	perror("Execve failed");
	handle_exec_error(pipex, command, path);
}
