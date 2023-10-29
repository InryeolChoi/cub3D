#include "cub3d_info.h"

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
