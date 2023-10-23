#include "cub3d_info.h"

void	my_mlx_pixel_put(t_data *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

int	finish_cub3d(t_box *tools)
{
	free(tools);
	exit(0);
}