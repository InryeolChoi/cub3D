#include "cub3d_info.h"

void	set_texture_vector(t_box *tools, t_data *image, t_vec_f *texture)
{
	texture->dy = image->height / (float)tools->line_height;
	if (tools->side == 0) // x축에 부딫힘 (남, 북)
	{
		texture->x = tools->pos.y + tools->perpwalldist * tools->raydir.y;
		texture->x -= (int)texture->x;
		texture->x *= (float)image->width;
	}
	if (tools->side == 1) // y축에 부딫힘 (남, 북)
	{
		texture->x = tools->pos.x + tools->perpwalldist * tools->raydir.x;
		texture->x -= (int)texture->x;
		texture->x *= (float)image->width;
	}
}

int	get_color_of_texture(t_data *image, t_vec_f *texture)
{
	char	*dest;
	int		x;
	int		y;

	x = texture->x;
	y = texture->y;
	dest = image->addr + (y * image->line_length + x * (image->bpp / 8));
	return (*(unsigned int *)dest);
}

void	my_mlx_pixel_put(t_data *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

void	raycast_draw_northsouth(t_box *tools, t_data *camera_image, t_vec_f *texture, int x)
{
	int	color;

	if (tools->raydir.y > 0) // 남쪽
	{
		set_texture_vector(tools, &tools->img_south, texture);
		color = get_color_of_texture(&tools->img_south, texture);
		my_mlx_pixel_put(camera_image, x, tools->draw_start, color);
		(texture->y) += (texture->dy);
		if (texture->y >= tools->img_south.height)
			texture->y = tools->img_south.height - 1;
	}
	else if (tools->raydir.y < 0) // 북쪽
	{
		set_texture_vector(tools, &tools->img_north, texture);
		color = get_color_of_texture(&tools->img_north, texture);
		my_mlx_pixel_put(camera_image, x, tools->draw_start, color);
		(texture->y) += (texture->dy);
		if (texture->y >= tools->img_north.height)
			texture->y = tools->img_north.height - 1;
	}
}

void	raycast_draw_eastwest(t_box *tools, t_data *camera_image, t_vec_f *texture, int x)
{
	int	color;

	if (tools->raydir.x < 0) // 동쪽
	{
		set_texture_vector(tools, &tools->img_east, texture);
		color = get_color_of_texture(&tools->img_east, texture);
		my_mlx_pixel_put(camera_image, x, tools->draw_start, color);
		(texture->y) += (texture->dy);
		if (texture->y >= tools->img_east.height)
			texture->y = tools->img_east.height - 1;
	}
	else if (tools->raydir.x > 0) // 서쪽
	{
		set_texture_vector(tools, &tools->img_west, texture);
		color = get_color_of_texture(&tools->img_west, texture);
		my_mlx_pixel_put(camera_image, x, tools->draw_start, color);
		(texture->y) += (texture->dy);
		if (texture->y >= tools->img_west.height)
			texture->y = tools->img_west.height - 1;
	}
}
