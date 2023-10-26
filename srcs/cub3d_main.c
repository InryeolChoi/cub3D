#include "cub3d_info.h"

int	check_av(char *filename)
{
	if (ft_strncmp(filename, ".cub", 4) == 0 && ft_strlen(filename) == 4)
		return (1);
	while (*filename != '.')
		filename++;
	if (*filename)
	{
		if (ft_strncmp(filename, ".cub", 4) == 0)
			return (0);
		else
			return (1);
	}
	else
		return (1);
}

t_box	*set_tools(char map_x[5][5])
{
	t_box *tools;

	tools = malloc(sizeof(t_box));
	if (!tools)
	{
		perror("cub3d");
		exit(1);
	}
	tools->alpha = 0.0;
	tools->mlx_ptr = mlx_init();
	tools->win_ptr = mlx_new_window(tools->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			tools->total_map[i][j] = map_x[i][j];
	}
	return (tools);
}

void	set_init_vector(t_box *tools)
{
	// 실험 : 북쪽
	tools->dir.x = 0;
	tools->dir.y = -1;
	tools->camera.x = 0.66;
	tools->camera.y = 0;
	// 한 방향 설정할 때마다 dir & plane 같이 설정
	// 동, 서, 남, 북

	// pos 설정
	tools->pos.x = 3.5;
	tools->pos.y = 3.8;
	// 실제 설정 시 주어진 좌표에 0.5씩 더해야 함.
	// tools->pos.x = (주어진 값) + 0.5;
	// tools->pos.y = (주어진 값) + 0.5;
}

int	main(int ac, char **av)
{
	t_box	*tools;

	char total_map[5][5] = {
		{1, 1, 1, 1, 1},
		{1, 0, 0, 1, 1},
		{1, 1, 0, 0, 1},
		{1, 0, 1, 0, 1},
		{1, 1, 1, 1, 1}
	};

	if (ac != 2)
		return (write(2, "wrong argument\n", 16));
	if (check_av(av[1]) == 1)
		return (write(2, "wrong argument\n", 16));
	// tools 할당
	tools = set_tools(total_map);
	// tools 파싱
	// 처음 방향
	set_init_vector(tools);
	mlx_hook(tools->win_ptr, 2, 2, &ft_keyhook, tools);
	mlx_hook(tools->win_ptr, X_EVENT_KEY_EXIT, 0, &finish_cub3d, tools);
	mlx_loop_hook(tools->mlx_ptr, &drawing, tools);
	mlx_loop(tools->mlx_ptr);
}
