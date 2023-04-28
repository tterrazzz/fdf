/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan <avan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:51:11 by avan              #+#    #+#             */
/*   Updated: 2023/04/05 17:52:03 by avan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/fdf.h"

static void	ft_translation(char const *s, int *i)
{
	int	j;

	j = 0;
	while (s[j] && (s[j] == ' ' || s[j] == '\n'))
		j++;
	*i = *i + j - 1;
}

static void	ft_translationdif(char const *s, int *i, int nb)
{
	int	j;

	j = 0;
	(void) nb;
	while (s[j] && s[j] != ' ' && s[j] != '\n')
		j++;
	*i = *i + j - 1;
}

static char	*ft_deploiementmot(char const *strpos, int *i, char **stock)
{
	int		j;
	int		nb;
	char	*str;

	j = 0;
	nb = 0;
	while (strpos[j] && strpos[j] != ' ' && strpos[j] != '\n')
		j++;
	str = ft_substr(strpos, 0, j);
	if (str == NULL)
	{
		while (stock[nb])
			free(stock[nb++]);
		free(stock);
		return (NULL);
	}
	*i = *i + j - 1;
	return (str);
}

char	**ft_split(char const *s, int *nb)
{
	int			i;
	char		**stock;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		if (s[i] == ' ' || s[i] == '\n')
			ft_translation(&s[i], &i);
		else
			ft_translationdif(&s[i], &i, (*nb)++);
	}
	stock = (char **) malloc(sizeof(char *) * ((*nb) + 1));
	if (stock == NULL)
		return (NULL);
	i = -1;
	*nb = 0;
	while (s[++i])
		if (s[i] != ' ' && s[i] != '\n')
			stock[(*nb)++] = ft_deploiementmot(&s[i], &i, stock);
	stock[*nb] = NULL;
	return (stock);
}
