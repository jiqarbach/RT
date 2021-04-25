/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 17:08:16 by yataji            #+#    #+#             */
/*   Updated: 2019/04/22 07:09:09 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*lstbcl;

	if (*alst)
	{
		lst = *alst;
		while (lst)
		{
			lstbcl = lst->next;
			del(lst->content, lst->content_size);
			free(lst);
			lst = lstbcl;
		}
		*alst = NULL;
	}
}
