/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 19:53:15 by yataji            #+#    #+#             */
/*   Updated: 2019/04/22 07:10:39 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst1;
	t_list	*tmp;

	if (lst)
	{
		lst1 = f(lst);
		lst = lst->next;
		tmp = lst1;
		while (lst)
		{
			lst1->next = f(lst);
			lst1 = lst1->next;
			lst = lst->next;
		}
		lst1->next = NULL;
		return (tmp);
	}
	return (NULL);
}
