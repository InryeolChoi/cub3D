/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:55:59 by yongjale          #+#    #+#             */
/*   Updated: 2023/11/01 13:04:17 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_info.h"
#include "cub3d_parse_util.h"

void	map_parse(t_box *ts, char *fs_line)
{
	// map 파싱 여기서 새로운 gnl 진행 예정
	(void)ts;
	(void)fs_line;
}

static void	rgb_parse(int rgb[3], char *line)
{
	char	**str_rgb;
	int		val;
	int		i;

	str_rgb = ft_split(line, ',');
	i = 0;
	while (i < 3)
	{
		if (str_rgb[i] == NULL)
			usrerr("RGB Values Are Not Enough");
		val = ft_atoi(str_rgb[i]);
		if (val >= 0 && val <= 255)
			rgb[i] = val;
		else
			usrerr("RGB Values Parsed Are Invalid");
		i++;
	}
	if (str_rgb[i] != NULL)
		usrerr("RGB Values Are Exceed");
}

static int	sort_parse(t_box *ts, char *line)
{
	if (line == NULL)
		return (1);
	if (ft_strncmp(line, "NO ", 3) && !sp(line[3]) && !ts->north_texture)
		ts->north_texture = ft_strdup(&line[3]);
	else if (ft_strncmp(line, "SO ", 3) && !sp(line[3]) && !ts->south_texture)
		ts->south_texture = ft_strdup(&line[3]);
	else if (ft_strncmp(line, "WE ", 3) && !sp(line[3]) && !ts->west_texture)
		ts->west_texture = ft_strdup(&line[3]);
	else if (ft_strncmp(line, "EA ", 3) && !sp(line[3]) && !ts->east_texture)
		ts->east_texture = ft_strdup(&line[3]);
	else if (ft_strncmp(line, "F ", 2) && !sp(line[2]) && ts->floor_rgb[0] != -1)
		rgb_parse(ts->floor_rgb, &line[2]);
	else if (ft_strncmp(line, "C ", 2) && !sp(line[2]) && ts->floor_rgb[0] != -1)
		rgb_parse(ts->celling_rgb, &line[2]);
	else if (is_map_line(line))
		map_parse(ts, line);
	else
		usrerr("Invalid File: VALUE DUPLICATED/NONALLOWED OR MAP UNDETECTED");
	return (0);
}

void	parse_tools(t_box *tools, char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		exit(-1);
	}
	tools->fd = fd;
	while (1)
		if (sort_parse(tools, get_next_line(fd)))
			break ;	
}
