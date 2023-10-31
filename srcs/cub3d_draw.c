#include "cub3d_info.h"

void	drawing_init(t_box *tools, t_data *camera_image)
{
	camera_image->img = mlx_new_image(tools->mlx_ptr, WIDTH, HEIGHT);
	camera_image->addr = mlx_get_data_addr(camera_image->img, \
	&camera_image->bpp, &camera_image->line_length, &camera_image->endian);
	tools->img_north.img = mlx_xpm_file_to_image(tools->mlx_ptr, \
	"texture/image1.xpm", &tools->img_north.width, &tools->img_north.height);
	tools->img_south.img = mlx_xpm_file_to_image(tools->mlx_ptr, \
	"texture/image2.xpm", &tools->img_south.width, &tools->img_south.height);
	tools->img_east.img = mlx_xpm_file_to_image(tools->mlx_ptr, \
	"texture/image3.xpm", &tools->img_east.width, &tools->img_east.height);
	tools->img_west.img = mlx_xpm_file_to_image(tools->mlx_ptr, \
	"texture/image4.xpm", &tools->img_west.width, &tools->img_west.height);
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

void	drawing_background(t_data *camera_image)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT / 2)
		{
			my_mlx_pixel_put(camera_image, x, y, 0x0099CCFF);
			y++;
		}
		while (y < HEIGHT)
		{
			my_mlx_pixel_put(camera_image, x, y, 0x00008a12);
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
	drawing_background(&camera_image);
	while (x < WIDTH)
	{
		camera_x = 2 * x / (float)WIDTH - 1;
		raycast_vector_init(tools, camera_x);
		raycast_sidedist_init(tools);
		raycast_shoot_light(tools, tools->total_map);
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

void	minimap_fill(int x, int y, t_data *image, int color)
{
	int	minimap_size;
	int	rec_size;
	int	map_col;
	int	i;
	int	j;

	map_col = 5;
	minimap_size = HEIGHT / 8;
	rec_size = minimap_size / map_col;
	x *= rec_size;
	y *= rec_size;
	i = 0;
	while (i < rec_size && (x + i < HEIGHT))
	{
		j = 0;
		while (j < rec_size && (y + j < WIDTH))
		{
			my_mlx_pixel_put(image, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	ft_set_minimap(t_box *tools, t_data *image)
{
	int	map_x;
	int	map_y;

	map_y = 0;
	while (map_y < 5)
	{
		map_x = 0;
		while (map_x < 5)
		{
			if (tools->total_map[map_y][map_x] == 1)
				minimap_fill(map_x, map_y, image, 0x000000);
			else
				minimap_fill(map_x, map_y, image, 0xFFFFFF);
			map_x++;
		}
		map_y++;
	}
	minimap_fill((int)tools->pos.x, (int)tools->pos.y, image, 0xAAAAAA);
}

