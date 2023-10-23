/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:59:23 by inchoi            #+#    #+#             */
/*   Updated: 2023/10/21 13:24:37 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line_bonus.h"

static char	*readline_bonus(int fd, char *buffer, char **backup)
{
	char	*temp;
	int		x;

	x = 1;
	while (x)
	{
		x = read(fd, buffer, BUFFER_SIZE);
		if (x == -1)
			return (NULL);
		if (x == 0)
			break ;
		buffer[x] = '\0';
		temp = backup[fd];
		backup[fd] = ft_strjoin(backup[fd], buffer);
		free(temp);
		if (!backup)
			return (NULL);
		if (ft_strchr(backup[fd], '\n'))
			break ;
	}
	return (backup[fd]);
}

static char	*sepearate_bonus(char *total)
{
	int		i;
	char	*backup;

	i = 0;
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

char	*get_next_line_bonus(int fd)
{
	static char	*backup[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	char		*total;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	total = readline_bonus(fd, buffer, backup);
	if (total == NULL || *total == '\0')
	{
		free(backup[fd]);
		backup[fd] = (char *) NULL;
		return (NULL);
	}
	backup[fd] = sepearate_bonus(total);
	return (total);
}
