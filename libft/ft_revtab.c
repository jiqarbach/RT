/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 00:36:36 by yataji            #+#    #+#             */
/*   Updated: 2019/04/19 02:36:59 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revtab(char *tab)
{
	char	*rvtb;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (tab)
	{
		i = ft_strlen(tab) - 1;
		rvtb = malloc(ft_strlen(tab) + 1);
		if (rvtb)
		{
			while (tab[j])
				rvtb[j++] = tab[i--];
			rvtb[j] = '\0';
		}
		return (rvtb);
	}
	return (NULL);
}
