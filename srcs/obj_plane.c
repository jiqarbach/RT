/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:22:27 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/04/20 01:48:14 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	ft_plane(t_rt *rt, char *str)
{
	rt->tmpo = initobj();
	rt->tmpo->type = PLANE;
	if (stockobj(rt->tmpo, rt->tmpo->type, str, rt->fd) == -1)
		return (-1);
	rt->tmpo->center = plus(rt->tmpo->center, rt->tmpo->trs);
	rt->tmpo->next = rt->obj;
	rt->obj = rt->tmpo;
	return (0);
}
