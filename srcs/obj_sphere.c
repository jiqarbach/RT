/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:49:00 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/04/20 02:20:49 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	ft_sphere(t_rt *rt, char *str)
{
	rt->tmpo = initobj();
	rt->tmpo->type = SPHERE;
	if (stockobj(rt->tmpo, rt->tmpo->type, str, rt->fd) == -1)
		return (-1);
	rt->tmpo->center = plus(rt->tmpo->center, rt->tmpo->trs);
	rt->tmpo->next = rt->obj;
	rt->obj = rt->tmpo;
	return (0);
}
