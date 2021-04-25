/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_mb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:06:35 by yoelguer          #+#    #+#             */
/*   Updated: 2021/04/23 15:56:29 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rt.h"

static void	mb_loop(t_rt *rt, t_2d_i *loop, t_2d_i *filter, t_vect *c)
{
	t_2d_i	img;

	img.j = (int)(loop->j - 9 / 2 + filter->j + MAXWIDTH) % MAXWIDTH;
	img.i = (int)(loop->i - 9 / 2 + filter->i + MAXHEIGHT) % MAXHEIGHT;
	c->x += rt->screen[img.i * MAXWIDTH + img.j].x;
	c->y += rt->screen[img.i * MAXWIDTH + img.j].y;
	c->z += rt->screen[img.i * MAXWIDTH + img.j].z;
}

int	set_render_draw_color(t_rt *rt, t_vect c)
{
	if (SDL_SetRenderDrawColor(rt->rend,
			fmin(255., (int)(c.x / 9.0)), fmin(255., (int)(c.y / 9.0)),
		fmin(255., (int)(c.z / 9.0)), 255) != 0)
		return (-1);
	return (0);
}

void	filter_mb(t_rt *rt)
{
	t_2d_i		loop;
	t_2d_i		filter;
	t_vect		c;

	loop.i = -1;
	while (++loop.i < MAXWIDTH)
	{
		loop.j = -1;
		while (++loop.j < MAXHEIGHT)
		{
			c = (t_vect){0.0, 0.0, 0.0};
			filter.i = -1;
			while (++filter.i < 9)
			{
				filter.j = -1;
				while (++filter.j < 9)
					mb_loop(rt, &loop, &filter, &c);
				if (set_render_draw_color(rt, c) != 0)
					sdl_error("Get color failed");
				if (SDL_RenderDrawPoint(rt->rend, loop.i, loop.j) != 0)
					sdl_error("draw point failed");
			}
		}
	}
}
