/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:53:49 by yataji            #+#    #+#             */
/*   Updated: 2019/04/12 21:07:43 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (s1 && s2)
	{
		str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (str)
		{
			while (s1[++i])
				str[i] = s1[i];
			while (s2[j])
			{
				str[i] = s2[j];
				i++;
				j++;
			}
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
