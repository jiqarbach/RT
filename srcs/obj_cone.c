/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:23:37 by yataji            #+#    #+#             */
/*   Updated: 2021/04/20 02:14:32 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	ft_cone(t_rt *rt, char *str)
{
	rt->tmpo = initobj();
	rt->tmpo->type = CONE;
	if (stockobj(rt->tmpo, rt->tmpo->type, str, rt->fd) == -1)
		return (-1);
	rt->tmpo->center = plus(rt->tmpo->center, rt->tmpo->trs);
	rt->tmpo->next = rt->obj;
	rt->obj = rt->tmpo;
	return (0);
}
