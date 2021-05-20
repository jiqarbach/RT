/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:20:08 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/04/26 16:32:56 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	putimage(t_rt *rt, t_color *col, t_var *v)
{
	if (SDL_SetRenderDrawColor(rt->rend, col->x, col->y, col->z, 255) != 0)
		sdl_error("Get color failed");
	if (SDL_RenderDrawPoint(rt->rend, v->y, v->x) != 0)
		sdl_error("draw point failed");
	rt->screen[v->y * MAXWIDTH + v->x] = *col;
}

void	sdl_error(char *message)
{
	SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
	SDL_Quit();
	exit(-1);
}

void	init_sdl(t_rt *rt)
{
	rt->win = NULL;
	rt->rend = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) != 0
		&& IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0)
		sdl_error("initialisation SDL");
	rt->win = SDL_CreateWindow("RT", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, MAXWIDTH, MAXHEIGHT, SDL_WINDOW_SHOWN);
	if (!rt->win)
		sdl_error("Creation window");
	rt->rend = SDL_CreateRenderer(rt->win, -1, SDL_RENDERER_ACCELERATED
			| SDL_RENDERER_PRESENTVSYNC);
	if (!rt->rend)
		sdl_error("Creation render");
}

void	loop2(t_rt *rt, SDL_Event event)
{
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_r)
	{
		rt->menu = 1;
		rt->filter_type = 0;
		SDL_RenderClear(rt->rend);
		draw(*rt);
	}
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_m)
	{
		rt->menu = 0;
		SDL_RenderClear(rt->rend);
		draw(*rt);
	}
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button
		== SDL_BUTTON_LEFT)
	{
		SDL_GetMouseState(&(rt->event.i), &(rt->event.j));
		SDL_RenderClear(rt->rend);
		draw(*rt);
	}
}

void	loop(t_rt *rt)
{
	SDL_bool	prog_launched;
	SDL_Event	event;

	SDL_RenderPresent(rt->rend);
	prog_launched = SDL_TRUE;
	while (prog_launched)
	{
		while (SDL_PollEvent(&event))
		{
			if ((event.type == SDL_KEYDOWN && event.key.keysym.sym
					== SDLK_ESCAPE) || event.type == SDL_QUIT)
			{
				ft_free(&rt->obj, &rt->lights, &rt->cam);
				prog_launched = SDL_FALSE;
				exit(1);
			}
			loop2(rt, event);
		}
	}
	SDL_DestroyRenderer(rt->rend);
	SDL_DestroyWindow(rt->win);
	SDL_Quit();
}
