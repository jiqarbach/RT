/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathnorm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:26:30 by yataji            #+#    #+#             */
/*   Updated: 2021/04/03 00:34:24 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	max(double v1, double v2)
{
	if (v1 > v2)
		return (v2);
	return (v1);
}

t_color	add_color(t_color c1, t_color c2)
{
	t_color	ret;
	double	tmp;

	tmp = c1.x + c2.x;
	ret.x = max(tmp, 255);
	tmp = c1.y + c2.y;
	ret.y = max(tmp, 255);
	tmp = c1.z + c2.z;
	ret.z = max(tmp, 255);
	return (ret);
}

t_color	multi_tcolor(t_color c1, t_color c2)
{
	t_color	ret;
	double	tmp;

	tmp = c1.x * c2.x;
	ret.x = max(tmp, 255);
	tmp = c1.y * c2.y;
	ret.y = max(tmp, 255);
	tmp = c1.z * c2.z;
	ret.z = max(tmp, 255);
	return (ret);
}

t_color	multi_color(t_color c1, double scal)
{
	t_color	ret;
	double	tmp;

	tmp = c1.x * scal;
	ret.x = max(tmp, 255);
	tmp = c1.y * scal;
	ret.y = max(tmp, 255);
	tmp = c1.z * scal;
	ret.z = max(tmp, 255);
	return (ret);
}

t_vect	multi(t_vect v1, double v2)
{
	t_vect	vctmlt;

	vctmlt.x = v1.x * v2;
	vctmlt.y = v1.y * v2;
	vctmlt.z = v1.z * v2;
	return (vctmlt);
}
