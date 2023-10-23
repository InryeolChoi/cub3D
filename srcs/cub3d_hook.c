#include "cub3d_info.h"

static void	matrix_product(t_vec_f *vec, float alpha)
{
	float	new_x;
	float	new_y;

	new_x = cos(alpha) * vec->x - sin(alpha) * vec->y;
	new_y = sin(alpha) * vec->x + cos(alpha) * vec->y;
	vec->x = new_x;
	vec->y = new_y;
}

void	rotation(t_box *tools, int keycode)
{
	if (keycode == LEFT_TURN)
		tools->alpha += -(M_PI / 6);
	else if (keycode == RIGHT_TURN)
		tools->alpha += M_PI / 6;
	matrix_product(&(tools->dir), tools->alpha);
	matrix_product(&(tools->camera), tools->alpha);
	printf("alpha = %f\n", tools->alpha);
}

void	move_by_one(t_box *tools, int keycode)
{
	if (keycode == FORWARD_MOVE)
	{
		// if (tools->pos.y - 0.2 > 0)
		// 	tools->pos.y -= 0.2;
		forward_move(tools, 0.2);
	}
	if (keycode == BACKWARD_MOVE)
	{
		// if (tools->pos.y + 0.2 < HEIGHT)
		// 	tools->pos.y += 0.2;
		backword_move(tools, 0.2);
	}
	if (keycode == LEFT_MOVE)
	{
		if (tools->pos.x - 0.2 > 0)
			tools->pos.x -= 0.2;
	}
	if (keycode == RIGHT_MOVE)
	{
		if (tools->pos.x + 0.2 < WIDTH)
			tools->pos.x += 0.2;
	}
}

int	ft_keyhook(int keycode, t_box *tools)
{
	if (keycode == 53)
	{
		mlx_destroy_window(tools->mlx_ptr, tools->win_ptr);
		finish_cub3d(tools);
	}
	else if (keycode == LEFT_TURN || keycode == RIGHT_TURN)
		rotation(tools, keycode);
	else if (keycode == FORWARD_MOVE || keycode == BACKWARD_MOVE ||\
		 keycode == LEFT_MOVE || keycode == RIGHT_MOVE)
		move_by_one(tools, keycode);
	mlx_clear_window(tools->mlx_ptr, tools->win_ptr);
	mlx_loop_hook(tools->mlx_ptr, &drawing, tools);	
	return (0);
}
