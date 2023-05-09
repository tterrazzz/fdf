/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham_line_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan <avan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:36:54 by avan              #+#    #+#             */
/*   Updated: 2023/05/09 15:36:59 by avan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	ft_dx_bigger_crementation(t_struct *s, int direction)
{
	if (!s)
		return ;
	if (direction >= 0)
		s->y_temp += 1;
	else
		s->y_temp -= 1;
}

static void	ft_dx_bigger(t_struct *s, int color)
{
	(void) color;
	if (!s)
		return ;
	s->x_temp = s->x1;
	s->y_temp = s->y1;
	if (s->y2 < s->y1)
		s->dy = s->y1 - s->y2;
	else
		s->dy = s->y2 - s->y1;
	s->dx = s->x2 - s->x1;
	s->p = 2 * s->dy - s->dx;
	while (s->x_temp <= s->x2 && s->x_temp < 1920)
	{
		ft_mlx_pixel_put(s, s->x_temp, s->y_temp, color);
		s->x_temp += 1;
		if (s->p < 0)
			s->p += 2 * s->dy;
		else
		{
			s->p += 2 * (s->dy - s->dx);
			ft_dx_bigger_crementation(s, s->y2 - s->y1);
		}
	}
}

static void	ft_acute_up(t_struct *s, int color)
{
	(void) color;
	if (!s)
		return ;
	while (s->y_temp > s->y2 && s->y_temp < 1080)
	{
		ft_mlx_pixel_put(s, s->x_temp, s->y_temp, color);
		s->y_temp -= 1;
		if (s->p < 0)
			s->p += 2 * s->dx;
		else
		{
			s->p += 2 * (s->dx - s->dy);
			s->x_temp += 1;
		}
	}
}

static void	ft_dy_bigger(t_struct *s, int color)
{
	(void) color;
	if (!s)
		return ;
	s->x_temp = s->x1;
	s->y_temp = s->y1;
	s->dx = s->x2 - s->x1;
	if (s->y2 < s->y1)
		s->dy = s->y1 - s->y2;
	else
		s->dy = s->y2 - s->y1;
	s->p = 2 * s->dx - s->dy;
	if (s->y_temp > s->y2)
		ft_acute_up(s, color);
	while (s->y_temp <= s->y2 && s->y_temp < 1080)
	{
		ft_mlx_pixel_put(s, s->x_temp, s->y_temp, color);
		s->y_temp += 1;
		if (s->p < 0)
			s->p += 2 * s->dx;
		else
		{
			s->p += 2 * (s->dx - s->dy);
			s->x_temp += 1;
		}
	}
}

void	ft_bresenham_line(t_struct *s, int color)
{
	int	unsign_x;
	int	unsign_y;

	if (!s)
		return ;
	unsign_x = s->x2 - s->x1;
	unsign_y = s->y2 - s->y1;
	if (unsign_x < 0)
		unsign_x *= -1;
	if (unsign_y < 0)
		unsign_y *= -1;
	if (unsign_x < unsign_y)
		ft_dy_bigger(s, color);
	else
		ft_dx_bigger(s, color);
}
