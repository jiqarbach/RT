/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refl_refr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:24:15 by yataji            #+#    #+#             */
/*   Updated: 2021/04/26 16:35:15 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_var	reflection2(t_rt *rt, t_obj **closenew, t_ray ray, t_obj *close)
{
	double	t;
	t_var	v;

	v.near = -1;
	while (rt->tmpo)
	{
		if (rt->tmpo != close && !rt->tmpo->neg_obj)
		{
			t = intersect(&rt->tmpo, ray) + 0.0001;
			if ((t < v.near && t > 0) || (t > v.near && v.near < 0))
			{
				*closenew = rt->tmpo;
				v.near = t;
			}
		}
		rt->tmpo = rt->tmpo->next;
	}
	return (v);
}

t_color	refl_refrshad(t_rt *rt, t_obj *close, t_lights *l, t_ray rayor)
{
	t_color	c;

	c = diffuspclr(rt->ray, close, rt->tmpl);
	if (close->refl)
		c = add_color(reflection(rt, close, rt->tmpl, rt->ray), c);
	if (close->refr)
		c = add_color(refraction(rt, close, rt->tmpl, rt->ray), c);
	return (c);
}

t_color	reflection(t_rt *rt, t_obj *close, t_lights *l, t_ray rayor)
{
	t_obj	*closenew;
	t_ray	ray;
	t_var	v;

	rt->tmpo = rt->obj;
	if (!close || !close->refl || rt->maxrfl++ >= MAXRF)
		return ((t_color){0, 0, 0});
	if (close->refl)
		ray = initrayrfl(rt, rayor, close);
	closenew = NULL;
	v = reflection2(rt, &closenew, ray, close);
	ray.hit = plus(ray.org, multi(ray.dir, v.near));
	if (closenew && ft_strcmp(closenew->texture, ".") != 0)
		texture(closenew, ray.hit);
	if (!closenew)
		return ((t_color){0, 0, 0});
	if (closenew->refl)
		reflection(rt, closenew, l, ray);
	setnormal(closenew, &ray, v.near);
	return (refl_refrshad(rt, closenew, l, ray));
}

t_var	refraction2(t_rt *rt, t_obj **closenew, t_ray ray, t_obj *close)
{
	double	t;
	t_var	v;

	v.near = -1;
	while (rt->tmpo)
	{
		if (rt->tmpo != close && !rt->tmpo->neg_obj)
		{
			t = intersect(&rt->tmpo, ray) + 0.0001;
			if ((t < v.near && t > 0) || (t > v.near && v.near < 0))
			{
				*closenew = rt->tmpo;
				v.near = t;
			}
		}
		rt->tmpo = rt->tmpo->next;
	}
	return (v);
}

t_color	refraction(t_rt *rt, t_obj *close, t_lights *l, t_ray rayor)
{
	t_obj	*closenew;
	t_ray	ray;
	t_var	v;

	rt->tmpo = rt->obj;
	if (!close || !close->refr || rt->maxrfr++ >= MAXRF)
		return ((t_color){0, 0, 0});
	if (close->refr)
		ray = initrayrfr(rt, rayor, close);
	closenew = NULL;
	v = refraction2(rt, &closenew, ray, close);
	ray.hit = plus(ray.org, multi(ray.dir, v.near));
	if (closenew && ft_strcmp(closenew->texture, ".") != 0)
		texture(closenew, ray.hit);
	if (!closenew)
		return ((t_color){0, 0, 0});
	if (closenew->refr)
		refraction(rt, closenew, l, ray);
	setnormal(closenew, &ray, v.near);
	return (refl_refrshad(rt, closenew, l, ray));
}
