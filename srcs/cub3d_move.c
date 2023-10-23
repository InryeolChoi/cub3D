#include "cub3d_info.h"

void	forward_move(t_box *tools, float move)
{
	float dx;
	float dy;

	dx = move / sin(tools->alpha);
	dy = move /	cos(tools->alpha);

	if (dx == INFINITY)
		dx = 0;
	if (dy == INFINITY)
		dy = 0;
	printf("dx : %f\n", dx);
	printf("dy : %f\n\n", dy);
	if (tools->pos.x - dx > 0 && tools->pos.x - dx < WIDTH)
		tools->pos.x -= dx;
	if (tools->pos.y - dy > 0 && tools->pos.y - dy < HEIGHT)
		tools->pos.y -= dy;
}

void	backword_move(t_box *tools, float move)
{
	float dx;
	float dy;

	dx = move / sin(tools->alpha);
	dy = move / cos(tools->alpha);

	if (tools->pos.x + dx > 0 && tools->pos.x + dx < WIDTH)
		tools->pos.x += dx;
	if (tools->pos.y + dy > 0 && tools->pos.y + dy < HEIGHT)
		tools->pos.y += dy;
}