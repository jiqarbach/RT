/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 01:46:17 by yataji            #+#    #+#             */
/*   Updated: 2019/04/22 07:08:39 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list)
	{
		if (content != 0)
		{
			list->content = ft_memalloc(content_size + 1);
			if (!(list->content))
				return (NULL);
			ft_strncpy(list->content, (void *)content, content_size);
			list->content_size = content_size;
		}
		else
		{
			list->content = 0;
			list->content_size = 0;
		}
		list->next = NULL;
		return (list);
	}
	return (NULL);
}
