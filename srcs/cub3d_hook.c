#include "cub3d_info.h"

int	finish_cub3d(t_box *tools)
{
	free(tools);
	exit(0);
}

int	ft_set_mouse(t_box *tools)
{
	if (tools->mouse_on == 0)
	{
		mlx_mouse_get_pos(tools->win_ptr, &tools->mouse.x, &tools->mouse.y);
		mlx_mouse_move(tools->win_ptr, WIDTH / 2, HEIGHT / 2);
		tools->mouse_on = 1;
	}
	else
		tools->mouse_on = 0;
	return (0);
}

int	ft_key_press(int keycode, t_box *tools)
{
	if (keycode == 53)
	{
		mlx_destroy_window(tools->mlx_ptr, tools->win_ptr);
		finish_cub3d(tools);
	}
	if (keycode == LEFT_TURN)
		tools->left_turn = 1;
	else if (keycode == RIGHT_TURN)
		tools->right_turn = 1;
	if (keycode == FORWARD_MOVE)
		tools->forward_move = 1;
	else if (keycode == BACKWARD_MOVE)
		tools->backward_move = 1;
	if (keycode == LEFT_MOVE)
		tools->left_move = 1;
	else if (keycode == RIGHT_MOVE)
		tools->right_move = 1;
	if (keycode == MOUSE)
		ft_set_mouse(tools);
	ft_event(tools);
	return (0);
}

int	ft_key_release(int keycode, t_box *tools)
{
	if (keycode == LEFT_TURN)
		tools->left_turn = 0;
	else if (keycode == RIGHT_TURN)
		tools->right_turn = 0;
	if (keycode == FORWARD_MOVE)
		tools->forward_move = 0;
	else if (keycode == BACKWARD_MOVE)
		tools->backward_move = 0;
	if (keycode == LEFT_MOVE)
		tools->left_move = 0;
	else if (keycode == RIGHT_MOVE)
		tools->right_move = 0;
	return (0);
}

int	ft_event(t_box *tools)
{
	t_vec_f	new;

	new.x = 0;
	new.y = 0;
	if (tools->left_turn == 1 || tools->right_turn == 1)
		rotation(tools);
	if (tools->forward_move == 1 || tools->backward_move == 1 || \
			tools->left_move == 1 || tools->right_move == 1)
		ft_move_key(tools, &tools->pos, &tools->dir, &new);
	mlx_mouse_get_pos(tools->win_ptr, &tools->mouse.x, &tools->mouse.y);
	ft_move_mouse(tools->mouse.x, tools->mouse.y, tools);
	drawing(tools);
	return (0);
}
