/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan <avan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:35:38 by avan              #+#    #+#             */
/*   Updated: 2023/04/28 18:35:39 by avan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../bonus/fdf_bonus.h"

int	ft_atoi(const char *str)
{
	int		nb;
	int		signe;
	char	*s;

	if (!str)
		return (0);
	nb = 0;
	signe = 1;
	s = (char *) str;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			signe = -signe;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		nb = nb * 10 + (*s - 48);
		s++;
	}
	return (nb * signe);
}
