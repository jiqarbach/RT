/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:34:09 by yataji            #+#    #+#             */
/*   Updated: 2021/03/19 16:24:06 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vect	plus(t_vect v1, t_vect v2)
{
	t_vect	vctpls;

	vctpls.x = v1.x + v2.x;
	vctpls.y = v1.y + v2.y;
	vctpls.z = v1.z + v2.z;
	return (vctpls);
}

t_vect	multivect(t_vect v1, t_vect v2)
{
	t_vect	vctvect;

	vctvect.x = v1.x * v2.x;
	vctvect.y = v1.y * v2.y;
	vctvect.z = v1.z * v2.z;
	return (vctvect);
}

double	dot(t_vect a, t_vect b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vect	moins(t_vect v1, t_vect v2)
{
	t_vect	vctmns;

	vctmns.x = v1.x - v2.x;
	vctmns.y = v1.y - v2.y;
	vctmns.z = v1.z - v2.z;
	return (vctmns);
}

t_vect	crosspro(t_vect v1, t_vect v2)
{
	t_vect	ret;

	ret.x = v1.y * v2.z - v2.y * v1.z;
	ret.y = v2.x * v1.z - v1.x * v2.z;
	ret.z = v2.y * v1.x - v1.y * v2.x;
	return (ret);
}
