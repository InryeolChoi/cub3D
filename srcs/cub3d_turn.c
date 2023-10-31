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

void	rotation(t_box *tools)
{
	if (tools->left_turn == 1)
		tools->alpha = -(M_PI / 36);
	else if (tools->right_turn == 1)
		tools->alpha = M_PI / 36;
	matrix_product(&(tools->dir), tools->alpha);
	matrix_product(&(tools->camera), tools->alpha);
}

int ft_move_mouse(int x, int y, t_box *tools)
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