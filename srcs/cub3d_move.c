#include "cub3d_info.h"

static void	forward_move(t_box *tools, t_vec_f *pos, t_vec_f *dir)
{
	float	new_x;
	float	new_y;

	new_x = pos->x + dir->x * VELOCITY;
	new_y = pos->y + dir->y * VELOCITY;
	if (tools->total_map[(int)pos->y][(int)new_x] == 0)
		pos->x = new_x;
	if (tools->total_map[(int)new_y][(int)pos->x] == 0)
		pos->y = new_y;
}

static void	backward_move(t_box *tools, t_vec_f *pos, t_vec_f *dir)
{
	float	new_x;
	float	new_y;

	new_x = pos->x - dir->x * VELOCITY;
	new_y = pos->y - dir->y * VELOCITY;
	if (tools->total_map[(int)pos->y][(int)new_x] == 0)
		pos->x = new_x;
	if (tools->total_map[(int)new_y][(int)pos->x] == 0)
		pos->y = new_y;
}

static void	left_move(t_box *tools, t_vec_f *pos, t_vec_f *dir)
{
	float	new_x;
	float	new_y;

	new_x = pos->x + dir->y * VELOCITY;
	new_y = pos->y - dir->x * VELOCITY;
	if (tools->total_map[(int)pos->y][(int)new_x] == 0)
		pos->x = new_x;
	if (tools->total_map[(int)new_y][(int)pos->x] == 0)
		pos->y = new_y;
}

static void	right_move(t_box *tools, t_vec_f *pos, t_vec_f *dir)
{
	float	new_x;
	float	new_y;

	new_x = pos->x - dir->y * VELOCITY;
	new_y = pos->y + dir->x * VELOCITY;
	if (tools->total_map[(int)pos->y][(int)new_x] == 0)
		pos->x = new_x;
	if (tools->total_map[(int)new_y][(int)pos->x] == 0)
		pos->y = new_y;
}

void	move_by_one(t_box *tools, int keycode)
{
	if (keycode == FORWARD_MOVE)
		forward_move(tools, &tools->pos, &tools->dir);
	if (keycode == BACKWARD_MOVE)
		backward_move(tools, &tools->pos, &tools->dir);
	if (keycode == LEFT_MOVE)
		left_move(tools, &tools->pos, &tools->dir);
	if (keycode == RIGHT_MOVE)
		right_move(tools, &tools->pos, &tools->dir);
}
