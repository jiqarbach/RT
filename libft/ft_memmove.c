/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 01:28:21 by yataji            #+#    #+#             */
/*   Updated: 2019/04/04 22:28:17 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d1;

	if (src < dst)
	{
		d1 = (char *)malloc(sizeof(char) * (len));
		if (d1)
		{
			ft_memcpy((void *)d1, src, len);
			ft_memcpy(dst, (void *)d1, len);
			free(d1);
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
