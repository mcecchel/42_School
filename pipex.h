/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:42:23 by mcecchel          #+#    #+#             */
/*   Updated: 2025/04/22 17:12:30 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <sys/stat.h>

typedef struct s_cmd
{
	char	**cmd1;
	char	**cmd2;
}			t_cmd;

typedef struct s_pipex
{
	int		fd_in;
	int		fd_out;
	int		fd_pipe[2];// Dove fd[0] = lettura, fd[1] = scrittura
	char	**envp;
	int		child_1;
	int		child_2;
	t_cmd	cmd;
}			t_pipex;

// Helper functions
int		find_spaces(char c);
char	*find_env_path(t_pipex pipex);
void	free_split(char **arr);
void	clean_all(t_pipex pipex);

// Command management functions
int		is_valid_command(t_pipex pipex, char *cmd);
char	**get_paths(t_pipex pipex);
char	*search_command(char **paths, char *cmd);
char	*get_cmd_path(t_pipex pipex, char *cmd);
void	execute_cmd(t_pipex pipex, char *av, char **envp);

// Main program functions
int		open_file(t_pipex pipex, char *file, int in_or_out);
// char	*get_cmd_path(t_pipex pipex, char *cmd);
void	child_process(t_pipex pipex, char **av, char **envp);
void	parent_process(t_pipex pipex, char **av, char **envp);

// Close and error functions
void	handle_exec_error(t_pipex pipex, char **command, char *path);
void	close_fd(t_pipex pipex);
void	close_fd_pipe(t_pipex pipex);

void	fork_processes(t_pipex pipex, char **av, char **envp);
int main(int ac, char **av, char **envp);

#endif
