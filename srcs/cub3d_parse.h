/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:56:28 by yongjale          #+#    #+#             */
/*   Updated: 2023/11/01 13:01:31 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSE
# define CUB3D_PARSE

# include "cub3d_info.h"
# include "get_next_line.h"
# include "errno.h"

void	parse_tools(t_box *tools, char *av);

#endif