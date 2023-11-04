/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:30:30 by yongjale          #+#    #+#             */
/*   Updated: 2023/11/04 17:03:39 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parse_util.h"

int	get_map_element(char c)
{
	if (c == '0')
		return (0);
	else if (c == '1')
		return (1);
	else if (c == 'N')
		return (2);
	else if (c == 'S')
		return (3);
	else if (c == 'E')
		return (4);
	else if (c == 'W')
		return (5);
	else if (c == ' ' || c == '\n')
		return (-1);
	return (99);
}

int	is_map_line(char *line)
{
	while (*line)
	{
		if (*line != '0' && *line != '1'
			&& *line != 'N' && *line != 'S' && *line != 'E' && *line != 'W')
			return (0);
		line++;
	}
	return (1);
}

int	isnot_wall(int val)
{
	if (val == 0 || val == 2 || val == 3 || val == 4 || val ==5)
		return (1);
	return (0);
}

int	is_border(t_box *ts, size_t i, size_t j)
{
	if (i == 0 || i == ts->map_height - 1  || j == 0 || j == ts->map_width - 1)
		return (1);
	if (ts->arr_map[i - 1][j - 1] == -1 ||
		ts->arr_map[i - 1][j] == -1 ||
		ts->arr_map[i - 1][j + 1] == -1 ||
		ts->arr_map[i][j - 1] == -1 ||
		ts->arr_map[i][j + 1] == -1 ||
		ts->arr_map[i + 1][j - 1] == -1 ||
		ts->arr_map[i + 1][j] == -1 ||
		ts->arr_map[i + 1][j] == -1)
		return (1);
	return (0);
}
