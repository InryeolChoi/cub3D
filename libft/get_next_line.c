/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:38:28 by inchoi            #+#    #+#             */
/*   Updated: 2023/10/21 13:24:47 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static char	*read_line(int fd, char *buffer, char *backup, int x)
{
	char	*temp;

	while (x)
	{
		x = read(fd, buffer, BUFFER_SIZE);
		if (x == -1)
			return (NULL);
		if (x == 0)
			break ;
		buffer[x] = '\0';
		if (backup == NULL)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		free(temp);
		if (!backup)
			return (NULL);
		if (ft_strchr(backup, '\n'))
			break ;
	}
	return (backup);
}

static char	*sepearate(char *total, int i)
{
	char	*backup;

	while (total[i] && total[i] != '\n')
		i++;
	if (total[i] == '\0' || total[i + 1] == '\0')
		return (NULL);
	backup = ft_strdup(total + i + 1);
	if (backup == NULL)
		return (NULL);
	total[i + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		buffer[BUFFER_SIZE + 1];
	char		*total;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	total = read_line(fd, buffer, backup, 1);
	if (total == NULL || *total == '\0')
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = sepearate(total, 0);
	return (total);
}
