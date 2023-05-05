/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_check_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan <avan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:22:44 by avan              #+#    #+#             */
/*   Updated: 2023/05/05 13:22:49 by avan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	ft_comp_set(char *comp)
{
	if (!comp)
		return ;
	comp[0] = '0';
	comp[1] = 'x';
	comp[2] = '\0';
}

static int	ft_hex_prefix_presence(char *str, int *i)
{
	char	comp[3];
	int		check;
	int		j;
	int		k;

	if (!str)
		return (0);
	j = 0;
	k = *i + 1;
	check = 0;
	ft_comp_set(comp);
	while (comp[j] && str[k])
	{
		if (str[k] != comp[j])
			return (0);
		j++;
		k++;
		if (j == 2)
			check = 1;
	}
	if (check == 0)
		return (0);
	*i = k;
	return (1);
}

static int	ft_hex_presence(char *str, int *i)
{
	int	color;

	if (!str)
		return (0);
	color = 0;
	while (str[*i])
	{
		if (str[*i] == ',')
		{
			if (!ft_hex_prefix_presence(str, i))
				return (0);
			break ;
		}
		*i += 1;
	}
	return (1);
}

int	ft_color_check(t_struct *s, char *str)
{
	int	indice;
	int	value;
	int	current_digit;
	int	current_char;

	if (!s || !str)
		return (0);
	indice = 0;
	if (!ft_hex_presence(str, &indice))
		return (0);
	value = 0;
	while (str[indice])
	{
		current_char = ft_toupper(str[indice]);
		if (current_char >= '0' && current_char <= '9')
			current_digit = current_char - '0';
		else if (current_char >= 'A' && current_char <= 'F')
			current_digit = current_char - 'A' + 10;
		else
			return (0);
		value = value * 16 + current_digit;
		indice++;
	}
	return (value);
}
