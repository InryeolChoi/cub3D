#include "cub3d_info.h"

void	forward_move(t_box *tools, t_vec_f *pos, t_vec_f *dir)
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

void	backward_move(t_box *tools, t_vec_f *pos, t_vec_f *dir)
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

void	left_move(t_box *tools, t_vec_f *pos, t_vec_f *dir)
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

void	right_move(t_box *tools, t_vec_f *pos, t_vec_f *dir)
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