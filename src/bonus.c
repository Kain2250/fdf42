/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 23:24:54 by bdrinkin          #+#    #+#             */
/*   Updated: 2020/02/11 00:05:05 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_change_color1(double proc)
{
	if (proc < 0.1)
		return (A_PIX);
	else if (proc < 0.2)
		return (B_PIX);
	else if (proc < 0.3)
		return (C_PIX);
	else if (proc < 0.4)
		return (D_PIX);
	else if (proc < 0.5)
		return (E_PIX);
	else if (proc < 0.6)
		return (F_PIX);
	else if (proc < 0.65)
		return (G_PIX);
	else if (proc < 0.7)
		return (H_PIX);
	return (0);
}

int	ft_change_color2(double proc)
{
	if (proc < 0.8)
		return (I_PIX);
	else if (proc < 0.9)
		return (J_PIX);
	else if (proc < 1)
		return (K_PIX);
	else if (proc < 1.5)
		return (L_PIX);
	else if (proc < 2)
		return (M_PIX);
	return (0);
}
