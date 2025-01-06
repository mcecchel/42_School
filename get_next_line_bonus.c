/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcecchel <mcecchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:54:40 by mcecchel          #+#    #+#             */
/*   Updated: 2024/12/10 14:33:37 by mcecchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*------------------------------------------------------------------------------
Per gestire più file descriptor contemporaneamente vado a creare un array di
buffer, uno per ogni fd. In questo modo ogni fd avrà il proprio buffer per
memorizzare i dati letti dal file.
------------------------------------------------------------------------------*/
#include "get_next_line_bonus.h"

static ssize_t	bytes_reader(int fd, void *buf, size_t count)
{
	ssize_t	read_bytes;

	read_bytes = read(fd, buf, count);
	if (read_bytes < 0)
		return (-1);
	if (read_bytes == 0)
		return (0);
	return (read_bytes);
}

static char	*join_and_free(char *line, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(line, buffer);
	if (tmp == NULL)
		return (free(line), NULL);
	free(line);
	return (tmp);
}

static char	*extract_line(char *line, char *buffer)
{
	char	*newline_char;
	size_t	line_len;
	char	*tmp;
	char	*joined_line;

	newline_char = ft_strchr(buffer, '\n');
	if (newline_char == NULL)
		return (ft_strjoin(line, buffer));
	line_len = newline_char - buffer + 1;
	tmp = malloc(sizeof(char) * (line_len + 1));
	if (tmp == NULL)
		return (free(line), NULL);
	ft_strncpy(tmp, buffer, line_len);
	tmp[line_len] = '\0';
	ft_memmove(buffer, &buffer[line_len], BUFFER_SIZE - line_len);
	buffer[BUFFER_SIZE - line_len] = '\0';
	joined_line = ft_strjoin(line, tmp);
	free(tmp);
	if (joined_line == NULL)
		return (free(line), NULL);
	free(line);
	return (joined_line);
}

static char	*read_until_needed(int fd, char *line, char *buffer)
{
	ssize_t		read_bytes;

	read_bytes = BUFFER_SIZE;
	while (read_bytes == BUFFER_SIZE)
	{
		read_bytes = bytes_reader(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			break ;
		buffer[read_bytes] = '\0';
		if (read_bytes == 0)
			break ;
		if (ft_strchr(buffer, '\n') == NULL)
		{
			line = join_and_free(line, buffer);
			buffer[0] = '\0';
			if (line == NULL)
				return (NULL);
		}
		else
			return (extract_line(line, buffer));
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[FD_MAX][BUFFER_SIZE + 1] = {0};
	char		*line;
	size_t		buffer_len;

	line = NULL;
	buffer_len = 0;
	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	while (buffer[fd][buffer_len] != '\0')
		buffer_len++;
	if (buffer_len > 0)
	{
		line = extract_line(line, buffer[fd]);
		if (ft_strchr(line, '\n') != NULL)
			return (line);
		if (line == NULL)
			return (NULL);
	}
	line = read_until_needed(fd, line, buffer[fd]);
	return (line);
}

/* int	main(int argc, char **argv)
{
	int		fd1;
    int		fd2;
    int		fd3;
	char	*line1;
	char	*line2;
	char	*line3;

	if (argc != 4)
	{
		write(2, "File utilizzati: ./a.out file1 file2 file3\n", 43);
		return (1);
	}
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	fd3 = open(argv[3], O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		write(2, "Errore nell'apertura dei file\n", 30);
		return (1);
	}
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);
	while (line1 != NULL || line2 != NULL || line3 != NULL)
	{
		if (line1 != NULL)
			printf("fd1: %s", line1);
		if (line2 != NULL)
			printf("fd2: %s", line2);
		if (line3 != NULL)
			printf("fd3: %s", line3);
		free (line1);
		free (line2);
		free (line3);
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);
	}
	close (fd1);
	close (fd2);
	close (fd3);
	return (0);
} */