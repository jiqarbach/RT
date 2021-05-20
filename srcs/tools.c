/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:44:50 by yataji            #+#    #+#             */
/*   Updated: 2021/04/26 16:44:35 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	checkt(t_math calc)
{
	double	t1;
	double	t2;

	if (calc.delta < 0)
		return (-1);
	else if (calc.delta == 0)
		return (-calc.b / (2 * calc.a));
	t1 = (-calc.b - sqrtf(calc.delta)) / (2 * calc.a);
	t2 = (-calc.b + sqrtf(calc.delta)) / (2 * calc.a);
	if (t1 < t2 && t1 > 0.0001)
		return (t1);
	else if (t2 > 0.0001)
		return (t2);
	return (-1);
}

t_sol	check_min_max(t_math math)
{
	t_sol	sol;
	double	temp;

	if (math.delta < 0)
		return ((t_sol){-1., -1.});
	sol.tmin = (-1 * math.b - sqrt(math.delta)) / (2 * math.a);
	sol.tmax = (-1 * math.b + sqrt(math.delta)) / (2 * math.a);
	if (sol.tmin < 0 && sol.tmax < 0)
		return ((t_sol){-1., -1.});
	else if (sol.tmin > 0 && sol.tmax < 0)
		sol.tmax = -1;
	else if ((sol.tmax > 0 && sol.tmin < 0))
	{
		sol.tmin = sol.tmax;
		sol.tmax = -1;
	}
	else
	{
		temp = fmin(sol.tmin, sol.tmax);
		sol.tmax = fmax(sol.tmin, sol.tmax);
		sol.tmin = temp;
	}
	return (sol);
}

double	intersect(t_obj **object, t_ray ray)
{
	if ((*object)->type == CYLINDER)
		return (cyldintr(object, ray));
	else if ((*object)->type == SPHERE)
		return (sphrintr(object, ray));
	else if ((*object)->type == CONE)
		return (coneintr(object, ray));
	else if ((*object)->type == PLANE)
		return (planiter(object, ray));
	else if ((*object)->type == PARAPLOID)
		return (parapinter(object, ray));
	return (-1);
}

t_vect	normalize(t_vect v2)
{
	double	v;
	t_vect	v1;

	v = sqrtf((v2.x * v2.x) + (v2.y * v2.y) + (v2.z * v2.z));
	v1.x = v2.x / v;
	v1.y = v2.y / v;
	v1.z = v2.z / v;
	return (v1);
}

void	setnormal(t_obj *close, t_ray *ray, double t)
{
	if (close->type == SPHERE)
		close->normal = normsphr(ray, close, t);
	else if (close->type == CYLINDER)
		close->normal = normcyld(ray, close, t);
	else if (close->type == CONE)
		close->normal = normcone(ray, close, t);
	else if (close->type == PLANE)
		ray->hit = plus(ray->org, multi(ray->dir, t));
}
