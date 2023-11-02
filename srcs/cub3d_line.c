/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:25:53 by yongjale          #+#    #+#             */
/*   Updated: 2023/11/02 22:25:53 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_info.h"

void	set_texture_vector(t_box *tools, t_data *image, t_vec_f *texture)
{
	texture->dy = (float)image->height / (float)tools->line_height;
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

void	ft_draw_line(t_box *tools, t_data *camera_image, \
					t_data *wall_image, int x)
{
	int color;

	set_texture_vector(tools, wall_image, &tools->texture);
	tools->texture.y = (tools->draw_start - HEIGHT / 2 + \
				tools->line_height / 2) * tools->texture.dy;
	while (tools->draw_start <= tools->draw_end)
	{
		color = get_color_of_texture(wall_image, &tools->texture);
		my_mlx_pixel_put(camera_image, x, tools->draw_start, color);
		(tools->texture.y) += (tools->texture.dy);
		if (tools->texture.y >= wall_image->height)
			tools->texture.y = wall_image->height - 1;
		(tools->draw_start)++;
	}
}
