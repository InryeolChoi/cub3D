/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:37:53 by inchoi            #+#    #+#             */
/*   Updated: 2023/11/04 16:37:54 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_info.h"

static void	move_pos(t_box *tools, t_vec_f *pos, t_vec_f *new)
{
	if (tools->arr_map[(int)pos->y][(int)new->x] != 1)
		pos->x = new->x;
	if (tools->arr_map[(int)new->y][(int)pos->x] != 1)
		pos->y = new->y;
}

void	ft_move_key(t_box *tools, t_vec_f *pos, t_vec_f *dir, t_vec_f *new)
{
	if (tools->forward_move == 1)
	{
		new->x = pos->x + dir->x * VELOCITY;
		new->y = pos->y + dir->y * VELOCITY;
	}
	else if (tools->backward_move == 1)
	{
		new->x = pos->x - dir->x * VELOCITY;
		new->y = pos->y - dir->y * VELOCITY;
	}
	else if (tools->left_move == 1)
	{
		new->x = pos->x + dir->y * VELOCITY;
		new->y = pos->y - dir->x * VELOCITY;
	}
	else if (tools->right_move == 1)
	{
		new->x = pos->x - dir->y * VELOCITY;
		new->y = pos->y + dir->x * VELOCITY;
	}
	move_pos(tools, pos, new);
}

void	matrix_product(t_vec_f *vec, float alpha)
{
	float	new_x;
	float	new_y;

	new_x = cos(alpha) * vec->x - sin(alpha) * vec->y;
	new_y = sin(alpha) * vec->x + cos(alpha) * vec->y;
	vec->x = new_x;
	vec->y = new_y;
}

void	rotation(t_box *tools)
{
	if (tools->left_turn == 1)
		tools->alpha = -(M_PI / 36);
	else if (tools->right_turn == 1)
		tools->alpha = (M_PI / 36);
	matrix_product(&(tools->dir), tools->alpha);
	matrix_product(&(tools->camera), tools->alpha);
}

int	ft_move_mouse(int x, int y, t_box *tools)
{
	if (tools->mouse_on == 1 && \
		HEIGHT / 2 - 150 < y && y < HEIGHT / 2 + 150)
	{
		if (0 <= x && x <= 150)
			tools->alpha = -(M_PI / 72);
		else if (WIDTH - 150 <= x && x <= WIDTH)
			tools->alpha = (M_PI / 72);
		else
			tools->alpha = 0;
		matrix_product(&(tools->dir), tools->alpha);
		matrix_product(&(tools->camera), tools->alpha);
	}
	else
		return (0);
	return (0);
}
