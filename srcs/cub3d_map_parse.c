/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:11:05 by yongjale          #+#    #+#             */
/*   Updated: 2023/11/04 17:00:49 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parse_util.h"
#include "cub3d_info.h"

static void	line_parse(t_box *ts, char *fs_line)
{
	t_map	*cur_list;

	ts->map_list = (t_map *)malloc(sizeof(t_map));
	cur_list = ts->map_list;
	cur_list->line = fs_line;
	while (1)
	{
		cur_list->next = (t_map *)malloc(sizeof(t_map));
		cur_list = cur_list->next;
		cur_list->line = get_next_line(ts->fd);
		if (cur_list->line == NULL)
		{
			if (cur_list->line)
				free(cur_list->line);
			cur_list->line = NULL;
			cur_list->next = NULL;
			break ;
		}
	}
}

static void	size_parse(t_box *ts)
{
	t_map	*cur_list;
	int		cnt;

	cnt = 0;
	cur_list = ts->map_list;
	ts->map_width = 0;
	ts->map_height = 0;
	while (cur_list)
	{
		if (!cur_list->line)
			break ;
		if (ft_strlen(cur_list->line) > (size_t)ts->map_width)
			ts->map_width = ft_strlen(cur_list->line);
		cur_list = cur_list->next;
		cnt++;
	}
	ts->map_height = cnt;
}

static void	assign_parse(t_box *ts)
{
	t_map	*cur_list;
	size_t	i;
	size_t	j;

	ts->arr_map = (int **)malloc(sizeof(int *) * ts->map_height);
	i = 0;
	cur_list = ts->map_list;
	while (i < ts->map_height)
	{
		ts->arr_map[i] = (int *)malloc(sizeof(int) * ts->map_width);
		j = 0;
		while (j < ts->map_width)
		{
			if (j < ft_strlen(cur_list->line))
				ts->arr_map[i][j] = get_map_element(cur_list->line[j]);
			else
				ts->arr_map[i][j] = -1;
			if (ts->arr_map[i][j] == 99)
				usrerr("Map Element Invalid");
			j++;
		}
		cur_list = cur_list->next;
		i++;
	}
}

static void	pos_parse(t_box *ts)
{
	size_t	i;
	size_t	j;
	int		flag;
	int		val;

	flag = 0;
	i = 0;
	while (i < ts->map_height)
	{
		j = 0;
		while (j < ts->map_width)
		{
			val = ts->arr_map[i][j];
			if (val == 2 || val == 3 || val == 4 || val == 5)
			{
				if (flag++)
					usrerr("More Than One Start Position");
				ts->pos.y = i;
				ts->pos.x = j;
				ts->pos.dir = ts->arr_map[i][j];
			}
			j++;
		}
		i++;
	}
}

static void	map_check(t_box *ts)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < ts->map_height)
	{
		j = 0;
		while (j < ts->map_width)
		{
			if (isnot_wall(ts->arr_map[i][j]) && is_border(ts, i, j))
				usrerr("Not Surrounded By Wall");
			j++;
		}
		i++;
	}
}

void	map_parse(t_box *ts, char *fs_line)
{
	line_parse(ts, fs_line);
	size_parse(ts);
	assign_parse(ts);
	pos_parse(ts);
	map_check(ts);
}
