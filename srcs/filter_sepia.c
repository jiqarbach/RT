/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_sepia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:06:42 by yoelguer          #+#    #+#             */
/*   Updated: 2021/04/23 16:01:05 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rt.h"

static t_vect	sepia(t_vect c)
{
	t_vect	v;

	v.x = fmin((c.x * .393) + (c.y * .769) + (c.z * .189), 255.0);
	v.y = fmin((c.x * .349) + (c.y * .686) + (c.z * .168), 255.0);
	v.z = fmin((c.x * .272) + (c.y * .534) + (c.z * .131), 255.0);
	return (v);
}

void	filtre_sepia(t_rt *rt)
{
	t_2d_i		loop;
	t_vect		c;

	loop.i = -1;
	while (++loop.i < MAXWIDTH)
	{
		loop.j = -1;
		while (++loop.j < MAXHEIGHT)
		{
			rt->screen[loop.i * MAXWIDTH + loop.j]
				= sepia(rt->screen[loop.i * MAXWIDTH + loop.j]);
			if (SDL_SetRenderDrawColor(rt->rend,
					rt->screen[loop.i * MAXWIDTH + loop.j].x,
					rt->screen[loop.i * MAXWIDTH + loop.j].y,
					rt->screen[loop.i * MAXWIDTH + loop.j].z, 255) != 0)
				sdl_error("Get color failed");
			if (SDL_RenderDrawPoint(rt->rend, loop.i, loop.j) != 0)
				sdl_error("draw point failed");
		}
	}
}
