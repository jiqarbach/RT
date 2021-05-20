/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 01:02:43 by yataji            #+#    #+#             */
/*   Updated: 2021/04/26 16:23:09 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray	initrayrfl(t_rt *rt, t_ray ray, t_obj *closeobj)
{
	t_ray	ret;
	t_vect	reflect;
	double	dot1;

	ret.org = ray.hit;
	dot1 = dot(closeobj->normal, ray.dir);
	reflect = normalize(moins(ray.dir, multi(closeobj->normal, 2 * dot1)));
	ret.dir = reflect;
	return (ret);
}

t_ray	initrayrfr(t_rt *rt, t_ray ray, t_obj *closeobj)
{
	t_ray	ret;
	double	c1;
	double	c2;
	double	n;

	ret.org = ray.hit;
	n = ray.n1 / closeobj->n2;
	c1 = dot(closeobj->normal, ray.dir);
	c2 = sqrtf(1 - pow(n, 2) * (1 - pow(c1, 2)));
	ret.dir = normalize(plus(multi(ray.dir, n),
				multi(closeobj->normal, n * c1 - c2)));
	return (ret);
}

t_ray	initray(t_cam *cam, int x, int y)
{
	t_ray	ray;
	double	py;
	double	px;

	px = ((2 * ((double)x + 0.5) / MAXWIDTH) - 1) * cam->plnw;
	py = (1 - (2 * ((double)y + 0.5) / MAXHEIGHT)) * cam->plnh;
	ray.org = cam->lokfrm;
	ray.dir = plus(multi(cam->u, px), multi(cam->v, py));
	ray.dir = normalize(plus(ray.dir, cam->w));
	ray.n1 = 1;
	return (ray);
}

void	initcamera(t_cam *cam)
{
	double	dot1;

	cam->w = normalize(moins(cam->lokat, cam->lokfrm));
	dot1 = dot(cam->v, cam->w);
	if (fabs(dot1) == 1)
		cam->v = (t_vect){0, 0, -1 * dot1};
	cam->fov = cam->fov * M_PI / 180.0;
	cam->plnh = tan(cam->fov / 2.0);
	cam->plnw = cam->plnh * (double)MAXWIDTH / MAXHEIGHT;
	cam->u = crosspro(cam->v, cam->w);
	cam->v = crosspro(cam->w, cam->u);
}
