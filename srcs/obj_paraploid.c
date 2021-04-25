/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_paraploid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:09:26 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/04/23 17:11:46 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	ft_paraploid(t_rt *rt, char *str)
{
	rt->tmpo = initobj();
	rt->tmpo->type = PARAPLOID;
	if (stockobj(rt->tmpo, rt->tmpo->type, str, rt->fd) == -1)
		return (-1);
	rt->tmpo->center = plus(rt->tmpo->center, rt->tmpo->trs);
	rt->tmpo->next = rt->obj;
	rt->obj = rt->tmpo;
	return (0);
}
