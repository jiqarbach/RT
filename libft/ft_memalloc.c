/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:53:20 by yataji            #+#    #+#             */
/*   Updated: 2019/04/12 20:04:55 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(size);
	if (str)
	{
		while (i < size)
		{
			str[i] = 0;
			i++;
		}
		return ((void *)str);
	}
	return (NULL);
}
