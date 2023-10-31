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

void	move_by_one(t_box *tools)
{
	if (tools->forward_move == 1)
		forward_move(tools, &tools->pos, &tools->dir);
	if (tools->backward_move == 1)
		backward_move(tools, &tools->pos, &tools->dir);
	if (tools->left_move == 1)
		left_move(tools, &tools->pos, &tools->dir);
	if (tools->right_move == 1)
		right_move(tools, &tools->pos, &tools->dir);
}
