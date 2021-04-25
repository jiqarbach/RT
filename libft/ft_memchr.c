/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 23:10:46 by yataji            #+#    #+#             */
/*   Updated: 2019/04/04 01:48:44 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	t;
	size_t	i;

	i = 0;
	str = (char *)s;
	t = (char)c;
	while (i < n)
	{
		if (str[i] == t)
			return (str + i);
		i++;
	}
	return (NULL);
}
