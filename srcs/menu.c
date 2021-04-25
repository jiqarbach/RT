/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:47:19 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/04/23 16:27:28 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	button_start(t_rt *rt)
{
	SDL_Rect	dest;
	SDL_Texture	*img;

	dest.x = 400;
	dest.y = 760;
	dest.w = 200;
	dest.h = 180;
	img = IMG_LoadTexture(rt->rend, "./texture/menu1.png");
	SDL_RenderCopy(rt->rend, img, NULL, &dest);
	if (inside_rect(rt, dest) == 1)
		rt->menu = 1;
}

void	button_motion(t_rt *rt)
{
	SDL_Rect	dest2;
	SDL_Texture	*img2;

	dest2.x = 100;
	dest2.y = 850;
	dest2.w = 180;
	dest2.h = 100;
	img2 = IMG_LoadTexture(rt->rend, "./texture/motion.jpg");
	SDL_RenderCopy(rt->rend, img2, NULL, &dest2);
	if (inside_rect(rt, dest2) == 1)
		rt->filter_type = 1;
}

void	button_sepia(t_rt *rt)
{
	SDL_Rect	dest3;
	SDL_Texture	*img3;

	dest3.x = 700;
	dest3.y = 850;
	dest3.w = 180;
	dest3.h = 100;
	img3 = IMG_LoadTexture(rt->rend, "./texture/sepia.jpg");
	SDL_RenderCopy(rt->rend, img3, NULL, &dest3);
	if (inside_rect(rt, dest3) == 1)
		rt->filter_type = 2;
}

void	background(t_rt *rt)
{
	SDL_Rect	dest1;
	SDL_Texture	*img1;

	dest1.x = 0;
	dest1.y = 0;
	dest1.w = MAXWIDTH;
	dest1.h = MAXHEIGHT;
	img1 = IMG_LoadTexture(rt->rend, "./texture/blow.jpg");
	SDL_RenderCopy(rt->rend, img1, NULL, &dest1);
}

void	menu(t_rt *rt)
{
	background(rt);
	button_start(rt);
	button_motion(rt);
	button_sepia(rt);
	rt->event.i = 0;
	rt->event.j = 0;
}
