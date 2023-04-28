/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan <avan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:52:03 by avan              #+#    #+#             */
/*   Updated: 2023/04/28 17:52:04 by avan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	ft_a_to_b_pts_drawing(t_struct *s, int *y, int *x)
{
	if (!s || !y || !x)
		return ;
	if (*y > 0)
	{
		*y -= 1;
		s->x2 = s->map[*y][*x].iso_x;
		s->y2 = s->map[*y][*x].iso_y;
		ft_bresenham_line(s, s->map[*y][*x].color);
		*y += 1;
	}
	*x += 1;
	s->x2 = s->map[*y][*x].iso_x;
	s->y2 = s->map[*y][*x].iso_y;
	ft_bresenham_line(s, s->map[*y][*x].color);
	if (*x == s->length - 1 && *y > 0)
	{
		s->x1 = s->x2;
		s->y1 = s->y2;
		*y -= 1;
		s->x2 = s->map[*y][*x].iso_x;
		s->y2 = s->map[*y][*x].iso_y;
		ft_bresenham_line(s, s->map[*y][*x].color);
		*y += 1;
	}
}

static void	ft_iso_map_display(t_struct *s)
{
	int	x;
	int	y;

	if (!s)
		return ;
	x = 0;
	y = s->lines - 1;
	while (y >= 0)
	{
		while (x < s->length - 1)
		{
			s->x1 = s->map[y][x].iso_x;
			s->y1 = s->map[y][x].iso_y;
			ft_a_to_b_pts_drawing(s, &y, &x);
		}
		x = 0;
		y--;
	}
}

void	ft_calculation(t_struct *s)
{
	int	x;
	int	y;

	if (!s)
		return ;
	x = 0;
	y = 0;
	while (y < s->lines)
	{
		while (x < s->length)
		{
			s->map[y][x].iso_x = ((x - y) * cos(s->angle1) * s->scale)
				+ s->x_mov;
			s->map[y][x].iso_y = ((-(s->map[y][x].z * s->height) + (y + x)
						* cos(s->angle2)) * s->scale) + s->y_mov;
			x += 1;
		}
		x = 0;
		y += 1;
	}
	ft_iso_map_display(s);
}
