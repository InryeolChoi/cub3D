/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:26:07 by yongjale          #+#    #+#             */
/*   Updated: 2023/11/04 16:41:58 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_info.h"

void	raycast_vector_init(t_box *tools, float camera_x)
{
	tools->raydir.x = tools->dir.x + tools->camera.x * camera_x;
	tools->raydir.y = tools->dir.y + tools->camera.y * camera_x;
	tools->map.x = (int)(tools->pos.x);
	tools->map.y = (int)(tools->pos.y);
	tools->deltadist.x = fabsf(1 / tools->raydir.x);
	tools->deltadist.y = fabsf(1 / tools->raydir.y);
}

void	raycast_sidedist_init(t_box *tools)
{
	if (tools->raydir.x < 0)
	{
		tools->step.x = -1;
		tools->sidedist.x = (tools->pos.x - tools->map.x) * tools->deltadist.x;
	}
	else
	{
		tools->step.x = 1;
		tools->sidedist.x = (tools->map.x + 1.0 - tools->pos.x) \
							* tools->deltadist.x;
	}
	if (tools->raydir.y < 0)
	{
		tools->step.y = -1;
		tools->sidedist.y = (tools->pos.y - tools->map.y) * tools->deltadist.y;
	}
	else
	{
		tools->step.y = 1;
		tools->sidedist.y = (tools->map.y + 1.0 - tools->pos.y) \
							* tools->deltadist.y;
	}
}

void	raycast_shoot_light(t_box *tools, int **total_map)
{
	tools->perpwalldist = 0;
	while (1)
	{
		if (tools->sidedist.x < tools->sidedist.y)
		{
			tools->sidedist.x += tools->deltadist.x;
			tools->map.x += tools->step.x;
			tools->side = 0;
		}
		else
		{
			tools->sidedist.y += tools->deltadist.y;
			tools->map.y += tools->step.y;
			tools->side = 1;
		}
		if (total_map[tools->map.y][tools->map.x] == 1)
			break ;
	}
	if (tools->side == 0)
		tools->perpwalldist = tools->sidedist.x - tools->deltadist.x;
	else
		tools->perpwalldist = tools->sidedist.y - tools->deltadist.y;
}

void	raycast_draw_line(t_box *tools, t_data *camera_image, int x)
{
	tools->line_height = (HEIGHT / tools->perpwalldist) / 2;
	tools->draw_start = HEIGHT / 2 - tools->line_height / 2;
	if (tools->draw_start < 0)
		tools->draw_start = 0;
	tools->draw_end = HEIGHT / 2 + tools->line_height / 2;
	if (tools->draw_end >= HEIGHT)
		tools->draw_end = HEIGHT - 1;
	tools->texture.x = x;
	if (tools->side == 0 && tools->raydir.x < 0)
		ft_draw_line(tools, camera_image, &tools->img_east, x);
	else if (tools->side == 0 && tools->raydir.x > 0)
		ft_draw_line(tools, camera_image, &tools->img_west, x);
	if (tools->side == 1 && tools->raydir.y < 0)
		ft_draw_line(tools, camera_image, &tools->img_north, x);
	else if (tools->side == 1 && tools->raydir.y > 0)
		ft_draw_line(tools, camera_image, &tools->img_south, x);
}
