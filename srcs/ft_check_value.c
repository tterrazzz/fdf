/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan <avan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:43:40 by avan              #+#    #+#             */
/*   Updated: 2023/05/09 15:31:56 by avan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_big_or_lowest(t_struct *s, int y, int x)
{
	if (!s)
		return ;
	if (y < s->map_check->up_y)
		s->map_check->up_y = y;
	if (y > s->map_check->down_y)
		s->map_check->down_y = y;
	if (x > s->map_check->right_x)
		s->map_check->right_x = x;
	if (x < s->map_check->left_x)
		s->map_check->left_x = x;
}

int	ft_check_value(t_struct *s)
{
	if (!s)
		return (1);
	if (s->map_check->up_y < 0 || s->map_check->down_y > SIZE_Y
		|| s->map_check->right_x > SIZE_X || s->map_check->left_x < 0)
	{
		s->scale -= 0.5;
		ft_map_check_init(s);
		return (2);
	}
	return (0);
}
