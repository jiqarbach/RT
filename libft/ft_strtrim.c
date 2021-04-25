/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:13:37 by yataji            #+#    #+#             */
/*   Updated: 2019/04/13 16:21:16 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		l;

	i = 0;
	l = 0;
	if (s != NULL)
	{
		j = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && (j > i))
			j--;
		str = (char *)malloc(sizeof(char) * (j - i + 2));
		if (str)
		{
			while (i <= j && s[i])
				str[l++] = s[i++];
			str[l] = '\0';
			return (str);
		}
		return (NULL);
	}
	return (NULL);
}
