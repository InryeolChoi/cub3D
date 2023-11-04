/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:00:17 by yongjale          #+#    #+#             */
/*   Updated: 2023/11/04 22:33:20 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_info.h"
#include "cub3d_parse.h"

int	check_av(char *filename)
{
	if (ft_strncmp(filename, ".cub", 4) == 0 && ft_strlen(filename) == 4)
		return (1);
	while (*filename != '.')
		filename++;
	if (*filename)
	{
		if (ft_strncmp(filename, ".cub", 4) == 0 && \
			ft_strlen(filename) == 4 && ft_strlen(filename) == 4)
			return (0);
		else
			return (1);
	}
	else
		return (1);
}

t_box	*set_tools(void)
{
	t_box	*tools;

	tools = malloc(sizeof(t_box));
	if (!tools)
	{
		perror("cub3d");
		exit(1);
	}
	tools->alpha = 0.0;
	tools->mlx_ptr = mlx_init();
	tools->win_ptr = mlx_new_window(tools->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	tools->floor_rgb[0] = -1;
	tools->celling_rgb[0] = -1;
	tools->pos.x = -1;
	tools->north_texture = NULL;
	tools->south_texture = NULL;
	tools->east_texture = NULL;
	tools->west_texture = NULL;
	tools->mouse_on = 0;
	return (tools);
}

void	set_init_colvector(t_box *tools)
{
	if (tools->pos.dir == DIR_NORTH)
	{
		tools->dir.x = 0;
		tools->dir.y = -1;
		tools->camera.x = 0.66;
		tools->camera.y = 0;
	}
	else if (tools->pos.dir == DIR_SOUTH)
	{
		tools->dir.x = 0;
		tools->dir.y = 1;
		tools->camera.x = -0.66;
		tools->camera.y = 0;
	}
	tools->pos.x += 0.5;
	tools->pos.y += 0.5;
}

void	set_init_rowvector(t_box *tools)
{
	if (tools->pos.dir == DIR_EAST)
	{
		tools->dir.x = 1;
		tools->dir.y = 0;
		tools->camera.x = 0;
		tools->camera.y = 0.66;
	}
	else if (tools->pos.dir == DIR_WEST)
	{
		tools->dir.x = -1;
		tools->dir.y = 0;
		tools->camera.x = 0;
		tools->camera.y = -0.66;
	}
	tools->pos.x += 0.5;
	tools->pos.y += 0.5;
}

int	main(int ac, char **av)
{
	t_box	*tools;

	if (ac != 2)
		return (write(2, "wrong argument\n", 16));
	if (check_av(av[1]) == 1)
		return (write(2, "wrong argument\n", 16));
	tools = set_tools();
	parse_tools(tools, av[1]);
	if (tools->pos.dir == DIR_NORTH || tools->pos.dir == DIR_SOUTH)
		set_init_colvector(tools);
	else
		set_init_rowvector(tools);
	mlx_hook(tools->win_ptr, X_EVENT_KEY_PRESS, 1L << 1, &ft_key_press, tools);
	mlx_hook(tools->win_ptr, X_EVENT_KEY_RELEASE, 1L << 0,
		&ft_key_release, tools);
	mlx_hook(tools->win_ptr, X_EVENT_KEY_EXIT, 0, &finish_cub3d, tools);
	mlx_loop_hook(tools->mlx_ptr, &ft_event, tools);
	mlx_loop(tools->mlx_ptr);
}
