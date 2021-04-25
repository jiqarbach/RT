/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:44:16 by yataji            #+#    #+#             */
/*   Updated: 2019/04/21 17:20:58 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(char const *s, char c, int i)
{
	int		l;

	l = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		l++;
	}
	return (l);
}

static int	delc(char const *s, char c, int l)
{
	while (s[l] == c)
		l++;
	return (l);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		l;

	l = 0;
	i = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_cpt(s, c) + 1));
	if ((!s) || (!tab))
		return (NULL);
	if ((ft_cpt(s, c) + 1) != 1)
	{
		while (s[l] != '\0')
		{
			tab[i] = (char *)malloc(ft_wordlen(s, c, l) + 1);
			j = 0;
			l = delc(s, c, l);
			while (s[l] != c && s[l])
				tab[i][j++] = s[l++];
			tab[i++][j] = '\0';
			l = delc(s, c, l);
		}
	}
	tab[i] = 0;
	return (tab);
}
