/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:19:37 by yongjale          #+#    #+#             */
/*   Updated: 2023/11/04 16:39:42 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_info.h"

static void	drawing_data_addr(t_box *tools)
{
	tools->img_north.addr = mlx_get_data_addr(tools->img_north.img, \
						&tools->img_north.bpp, &tools->img_north.line_length, \
						&tools->img_north.endian);
	tools->img_south.addr = mlx_get_data_addr(tools->img_south.img, \
						&tools->img_south.bpp, &tools->img_south.line_length, \
						&tools->img_south.endian);
	tools->img_east.addr = mlx_get_data_addr(tools->img_east.img, \
						&tools->img_east.bpp, &tools->img_east.line_length, \
						&tools->img_east.endian);
	tools->img_west.addr = mlx_get_data_addr(tools->img_west.img, \
						&tools->img_west.bpp, &tools->img_west.line_length, \
						&tools->img_west.endian);
}

void	drawing_init(t_box *tools, t_data *camera_image)
{
	camera_image->img = mlx_new_image(tools->mlx_ptr, WIDTH, HEIGHT);
	camera_image->addr = mlx_get_data_addr(camera_image->img, \
	&camera_image->bpp, &camera_image->line_length, &camera_image->endian);
	tools->img_north.img = mlx_xpm_file_to_image(tools->mlx_ptr, \
	tools->north_texture, &tools->img_north.width, &tools->img_north.height);
	tools->img_south.img = mlx_xpm_file_to_image(tools->mlx_ptr, \
	tools->south_texture, &tools->img_south.width, &tools->img_south.height);
	tools->img_east.img = mlx_xpm_file_to_image(tools->mlx_ptr, \
	tools->east_texture, &tools->img_east.width, &tools->img_east.height);
	tools->img_west.img = mlx_xpm_file_to_image(tools->mlx_ptr, \
	tools->west_texture, &tools->img_west.width, &tools->img_west.height);
	if ((tools->img_north.img && tools->img_south.img && \
		tools->img_east.img && tools->img_west.img) == 0)
		usrerr("Invalid Image Directory");
	drawing_data_addr(tools);
}

int	get_background_color(t_box *tools, int type)
{
	int	color;

	color = 0;
	if (type == CELLING)
	{
		color = tools->celling_rgb[0];
		color = (color << 8) + tools->celling_rgb[1];
		color = (color << 8) + tools->celling_rgb[2];
	}
	else if (type == FLOOR)
	{
		color = tools->floor_rgb[0];
		color = (color << 8) + tools->floor_rgb[1];
		color = (color << 8) + tools->floor_rgb[2];
	}
	return (color);
}

void	drawing_background(t_box *tools, t_data *camera_image)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT / 2)
		{
			color = get_background_color(tools, CELLING);
			my_mlx_pixel_put(camera_image, x, y, color);
			y++;
		}
		while (y < HEIGHT)
		{
			color = get_background_color(tools, FLOOR);
			my_mlx_pixel_put(camera_image, x, y, color);
			y++;
		}
		x++;
	}
}

int	drawing(t_box *tools)
{
	int		x;
	float	camera_x;
	t_data	camera_image;

	x = 0;
	camera_x = 0;
	drawing_init(tools, &camera_image);
	drawing_background(tools, &camera_image);
	while (x < WIDTH)
	{
		camera_x = 2 * x / (float)WIDTH - 1;
		raycast_vector_init(tools, camera_x);
		raycast_sidedist_init(tools);
		raycast_shoot_light(tools, tools->arr_map);
		raycast_draw_line(tools, &camera_image, x);
		x++;
	}
	mlx_clear_window(tools->mlx_ptr, tools->win_ptr);
	ft_set_minimap(tools, &camera_image);
	mlx_put_image_to_window(tools->mlx_ptr, tools->win_ptr, \
							camera_image.img, 0, 0);
	mlx_destroy_image(tools->mlx_ptr, camera_image.img);
	return (0);
}
