/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:56:28 by yongjale          #+#    #+#             */
/*   Updated: 2023/11/04 22:43:06 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSE_H
# define CUB3D_PARSE_H

# include "cub3d_info.h"
# include "get_next_line.h"
# include "errno.h"

void	parse_tools(t_box *tools, char *av);
void	line_parse(t_box *ts, char *fs_line);
void	size_parse(t_box *ts);
void	assign_parse(t_box *ts);
void	pos_parse(t_box *ts);
void	map_check(t_box *ts);

#endif