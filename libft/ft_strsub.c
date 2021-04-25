/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:34:43 by yataji            #+#    #+#             */
/*   Updated: 2019/04/12 19:53:34 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	size_t			j;

	i = start;
	j = 0;
	str = (char *)malloc(len + 1);
	if (str && s)
	{
		while (s[i] && j < len)
		{
			str[j] = s[i];
			j++;
			i++;
		}
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}
