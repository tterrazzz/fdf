/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan <avan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:01:50 by avan              #+#    #+#             */
/*   Updated: 2023/04/28 18:01:51 by avan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char **s1, char **s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	len = 0;
	if (s1)
		len = ft_strlen(*s1);
	len += ft_strlen(*s2);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && s1 && *s1 && s1[0][i] != '\0')
	{
		str[i] = s1[0][i];
		i++;
	}
	j = 0;
	while (i < len && s2 && *s2 && s2[0][j] != '\0')
		str[i++] = s2[0][j++];
	str[i] = '\0';
	free(*s1);
	free(*s2);
	return (str);
}

int	ft_strchr_int(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char) c)
	{
		if (!s[i])
			return (0);
		i++;
	}
	return (i + 1);
}
/*
size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}*/
