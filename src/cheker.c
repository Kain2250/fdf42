/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwing <cwing@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 20:39:33 by cwing             #+#    #+#             */
/*   Updated: 2020/02/09 00:39:34 by cwing            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_iscolor(int c)
{
	if (ft_isdigit(c) || c == 'x' || (c >= 'a' && c <= 'f') ||
		(c >= 'A' && c <= 'F') || c == ',')
		return (1);
	else
		return (0);
}

int			check_line(char *buff)
{
	int		iter;
	int		color_size;

	iter = 0;
	while (buff[iter] != '\0')
	{
		if (ft_isdigit(buff[iter]) || buff[iter] == ' ' || buff[iter] == '-')
			iter++;
		else if (buff[iter++] == ',')
		{
			color_size = 0;
			while (ft_iscolor(buff[iter]) && buff[iter] != '\0')
			{
				color_size++;
				iter++;
			}
			if (color_size != 8)
				return (0);
		}
		else
			return (0);
	}
	return (1);
}
