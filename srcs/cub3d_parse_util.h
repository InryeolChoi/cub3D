/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_util.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:30:44 by yongjale          #+#    #+#             */
/*   Updated: 2023/11/04 15:50:55 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSE_UTIL_H
# define CUB3D_PARSE_UTIL_H

# include "cub3d_info.h"

int	is_map_line(char *line);
int	get_map_element(char c);
int	is_border(t_box *ts, size_t i, size_t j);

#endif