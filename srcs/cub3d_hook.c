#include "cub3d_info.h"

void	matrix_product(t_vec_f *vec, float alpha)
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
		tools->alpha = -(M_PI / 36);
	else if (keycode == RIGHT_TURN)
		tools->alpha = M_PI / 36;
	matrix_product(&(tools->dir), tools->alpha);
	matrix_product(&(tools->camera), tools->alpha);
}

int	finish_cub3d(t_box *tools)
{
	free(tools);
	exit(0);
}

int	ft_keyhook(int keycode, t_box *tools)
{
	if (keycode == 53)
	{
		mlx_destroy_window(tools->mlx_ptr, tools->win_ptr);
		finish_cub3d(tools);
	}
	if (keycode == LEFT_TURN || keycode == RIGHT_TURN || \
		keycode == FORWARD_MOVE || keycode == BACKWARD_MOVE || \
		keycode == LEFT_MOVE || keycode == RIGHT_MOVE)
	{
		if (keycode == LEFT_TURN || keycode == RIGHT_TURN)
			rotation(tools, keycode);
		if (keycode == FORWARD_MOVE || keycode == BACKWARD_MOVE ||\
		 	keycode == LEFT_MOVE || keycode == RIGHT_MOVE)
			move_by_one(tools, keycode);
	}
	return (0);
}

int	ft_set_mouse(int button, int x, int y, t_box *tools)
{
	if (0 < x && x < WIDTH && 0 < y && y < HEIGHT)
	{
		if (button == MOUSE_LEFT_BUTTON)
			tools->alpha = -(M_PI / 36);
		if (button == MOUSE_RIGHT_BUTTON)
			tools->alpha = (M_PI / 36);
		matrix_product(&(tools->dir), tools->alpha);
		matrix_product(&(tools->camera), tools->alpha);
	}
	return (0);
}
