/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan <avan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:58:37 by avan              #+#    #+#             */
/*   Updated: 2023/05/09 15:58:38 by avan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	ft_struct_init_bis(t_struct *s)
{
	if (!s)
		return ;
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

void	ft_map_check_init(t_struct *s)
{
	if (!s)
		return ;
	s->map_check->up_y = 0;
	s->map_check->right_x = SIZE_X;
	s->map_check->down_y = SIZE_Y;
	s->map_check->left_x = 0;
}

void	ft_struct_init(t_struct *s)
{
	if (!s)
		return ;
	s->map_check = (t_map_check *)malloc(sizeof(t_map_check));
	if (!s->map_check)
		return ;
	ft_map_check_init(s);
	s->scale = 11.0;
	s->height = 1.0;
	s->angle1 = 0.139;
	s->angle2 = -0.523;
	s->x_mov = 400;
	s->y_mov = 100;
	s->lines = 0;
	s->length = 0;
	ft_struct_init_bis(s);
}
