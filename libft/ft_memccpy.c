/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 20:16:12 by yataji            #+#    #+#             */
/*   Updated: 2019/04/18 21:01:00 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			k;
	const char		*s;
	char			*d;
	size_t			l;

	k = (char)c;
	s = (const char *)src;
	d = (char *)dst;
	l = 0;
	while (l < n)
	{
		d[l] = s[l];
		if (s[l] == k)
			return (dst + l + 1);
		l++;
	}
	return (NULL);
}
