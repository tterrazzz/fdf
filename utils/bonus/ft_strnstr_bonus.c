/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan <avan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:01:18 by avan              #+#    #+#             */
/*   Updated: 2023/04/28 18:01:23 by avan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../bonus/fdf_bonus.h"

static int	ft_translation(char *str, char *tosearch)
{
	int	i;

	if (!str || !tosearch)
		return (1);
	i = 0;
	while (tosearch[i])
	{
		if (str[i] != tosearch[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*str;
	char	*tosearch;

	if (!haystack || !needle)
		return (NULL);
	str = (char *) haystack;
	tosearch = (char *) needle;
	if (*needle == 0)
		return (str);
	if (len == 0)
		return (NULL);
	len = len - ft_strlen(tosearch);
	i = 0;
	while (str[i] && i <= len)
	{
		if (ft_translation(&str[i], tosearch))
			return (&str[i]);
		i++;
	}
	return (NULL);
}
