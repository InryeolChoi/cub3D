#include "cub3d_info.h"

void	forward_move(t_vec_f *pos, t_vec_f *dir)
{
	float	new_x;
	float	new_y;

	new_x = pos->x + dir->x * VELOCITY;
	new_y = pos->y + dir->y * VELOCITY;
	if (new_x > 0 && new_x < WIDTH)
		pos->x = new_x;
	if (new_y > 0 && new_y < HEIGHT)
		pos->y = new_y;
}

void	backward_move(t_vec_f *pos, t_vec_f *dir)
{
	float	new_x;
	float	new_y;

	new_x = pos->x - dir->x * VELOCITY;
	new_y = pos->y - dir->y * VELOCITY;
	if (new_x > 0 && new_x < WIDTH)
		pos->x = new_x;
	if (new_y > 0 && new_y < HEIGHT)
		pos->y = new_y;
}

// void	left_move(t_vec_f *pos, t_vec_f *bent_dir)
// {
// }

// void	right_move(t_vec_f *pos, t_vec_f *bent_dir)
// {	
// }