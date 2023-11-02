/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:29:18 by inchoi            #+#    #+#             */
/*   Updated: 2023/11/02 22:25:04 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*arr;
	int		size;
	int		i;

	size = ft_strlen(src) - 1;
	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = src[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
