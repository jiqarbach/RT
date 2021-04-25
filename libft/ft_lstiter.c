/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 19:47:16 by yataji            #+#    #+#             */
/*   Updated: 2019/04/22 07:09:42 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*lstnw;

	if (lst)
	{
		lstnw = lst;
		while (lstnw)
		{
			f(lstnw);
			lstnw = lstnw->next;
		}
	}
}
