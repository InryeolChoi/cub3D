/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_info.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inchoi <inchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:30:22 by inchoi            #+#    #+#             */
/*   Updated: 2023/10/29 13:11:17 by inchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_INFO_H
# define CUB3D_INFO_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH 1400
# define HEIGHT 900
# define PI 3.14
# define VELOCITY 0.1
# define CELLING 1
# define FLOOR 2
# define MINI_SCALE 0.4
# define TILE_SIZE 1

typedef struct s_vec_float
{
	float	x;
	float	y;
	float	dy;
}	t_vec_f;

typedef struct s_vec_int
{
	int	x;
	int	y;
	int	dy;
}	t_vec_i;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_data;

typedef struct s_box
{
	char	*filename;
	int		fd;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_rgb[3];
	int		celling_rgb[3];
	char	total_map[5][5];
	int		mapsize;
	char	*name;

	// mlx용 포인터들
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img_north;
	t_data	img_south;
	t_data	img_east;
	t_data	img_west;

	// 처음 vector : 처음위치, 방향벡터, 카메라평면, 회전각
	t_vec_f	pos;
	t_vec_f	dir;
	t_vec_f	camera;
	float	alpha;

	// raytracting : 실수 거리
	t_vec_f	raydir;
	t_vec_f	sidedist;
	t_vec_f	deltadist;

	// raytracing : 정수 거리
	t_vec_i	map;
	t_vec_i	step;

	// raytracing : 실거리 & 벽
	int		side;
	float	perpwalldist;
	int		line_height;
	int		draw_start;
	int		draw_end;

	// 마우스
	int		before_x;
}	t_box;

typedef enum e_type
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_type;

typedef enum e_event
{
	X_EVENT_KEY_EXIT=17,
	BASIC_KEY=0,
	MOUSE_LEFT_BUTTON=1,
	MOUSE_RIGHT_BUTTON=2,
	ESC_KEY=53,
	LEFT_TURN=123,
	RIGHT_TURN=124,
	FORWARD_MOVE=13,
	BACKWARD_MOVE=1,
	LEFT_MOVE=0,
	RIGHT_MOVE=2
}	t_event;

// casting & drawing
int		drawing(t_box *tools);
void	drawing_background(t_data *camera_image);
void	raycast_vector_init(t_box *tools, float camera_x);
void	raycast_sidedist_init(t_box *tools);
void	raycast_shoot_light(t_box *tools, char total_map[5][5]);
void	raycast_draw_line(t_box *tools, t_data *image, int x);
void	raycast_draw_northsouth(t_box *tools, t_data *camera_image, \
								t_vec_f *texture, int x);
void	raycast_draw_eastwest(t_box *tools, t_data *camera_image, \
								t_vec_f *texture, int x);
void	my_mlx_pixel_put(t_data *image, int x, int y, int color);

// keyhook
int		ft_keyhook(int keycode, t_box *tools);
int		ft_set_mouse(int button, int x, int y, t_box *tools);
void	matrix_product(t_vec_f *vec, float alpha);
void	rotation(t_box *tools, int keycode);
void	move_by_one(t_box *tools, int keycode);
int		finish_cub3d(t_box *tools);

// minimap
void	ft_set_minimap(t_box *tools, t_data *image);
#endif
