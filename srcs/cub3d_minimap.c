/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:34:05 by inchoi            #+#    #+#             */
/*   Updated: 2023/11/04 15:49:11 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_info.h"

void	minimap_fill(t_vec_i map, t_vec_i total, t_data *image, int color)
{
	int	minimap_size;
	int	rec_size;
	int	map_col;
	int	i;
	int	j;

	map_col = total.y;
	minimap_size = HEIGHT / 8;
	rec_size = minimap_size / map_col;
	map.x *= rec_size;
	map.y *= rec_size;
	i = 0;
	while (i < rec_size && (map.x + i < HEIGHT))
	{
		j = 0;
		while (j < rec_size && (map.y + j < WIDTH))
		{
			my_mlx_pixel_put(image, map.x + i, map.y + j, color);
			j++;
		}
		i++;
	}
}

void	ft_set_minimap(t_box *tools, t_data *image)
{
	t_vec_i	map;
	t_vec_i pos;
	t_vec_i total;

	total.y = (int)tools->map_height;
	total.x = (int)tools->map_width;
	map.y = 0;
	while (map.y < total.y)
	{
		map.x = 0;
		while (map.x < total.x)
		{
			if (tools->arr_map[map.y][map.x] == 1)
				minimap_fill(map, total, image, 0x000000);
			else if (tools->arr_map[map.y][map.x] == -1)
				minimap_fill(map, total, image, 0xA0A0A0);
			else
				minimap_fill(map, total, image, 0xFFFFFF);
			(map.x)++;
		}
		(map.y)++;
	}
	pos.x = (int)tools->pos.x;
	pos.y = (int)tools->pos.y;
	minimap_fill(pos, total, image, 0xff0000);
}
