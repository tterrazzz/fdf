/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan <avan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:52:28 by avan              #+#    #+#             */
/*   Updated: 2023/04/28 17:52:29 by avan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_struct_init(t_struct *s)
{
	if (!s)
		return ;
	s->scale = 11.0;
	s->height = 1.0;
	s->angle1 = 0.139;
	s->angle2 = -0.523;
	s->x_mov = 400;
	s->y_mov = 100;
	s->lines = 0;
	s->length = 0;
	s->x = -1;
	s->y = -1;
	s->x1 = 0;
	s->y1 = 0;
	s->x2 = 0;
	s->y2 = 0;
	s->dx = 0;
	s->dy = 0;
	s->p = 0;
	s->x_temp = 0;
	s->y_temp = 0;
	s->verif_x = 0;
	s->lines_malloc = 0;
}
