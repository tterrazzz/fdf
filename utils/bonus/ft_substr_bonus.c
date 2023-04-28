/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan <avan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:01:26 by avan              #+#    #+#             */
/*   Updated: 2023/04/28 18:01:31 by avan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../bonus/fdf_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (start >= l)
		return (ft_strdup(""));
	l = l - start + 1;
	if (l > len)
		l = len + 1;
	str = malloc(sizeof(char) * l);
	if (!str)
		return (str);
	l = ft_strlcpy(str, &s[start], l);
	return (str);
}
