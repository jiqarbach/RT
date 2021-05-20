/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:05:36 by yoelguer          #+#    #+#             */
/*   Updated: 2021/04/26 16:39:55 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_col(t_obj *obj, int bpp, unsigned char *pos)
{
	SDL_Color	rgb;
	int			pix;

	if (bpp == 1)
		pix = *pos;
	else if (bpp == 2)
		pix = *(unsigned short *)pos;
	else if (bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			pix = pos[0] << 16 | pos[1] << 8 | pos[2];
		else
			pix = pos[0] | pos[1] << 8 | pos[2] << 16;
	}
	else if (bpp == 4)
		pix = *(unsigned int *)pos;
	else
		pix = -1;
	SDL_GetRGB(pix, obj->surface->format, &rgb.r, &rgb.g, &rgb.b);
	obj->color.x = rgb.r;
	obj->color.y = rgb.g;
	obj->color.z = rgb.b;
}

void	texture(t_obj *obj, t_vect hit)
{
	int					bpp;
	unsigned char		*pos;
	t_2d_i				size;
	t_2d_i				uv;

	bpp = obj->surface->format->BytesPerPixel;
	size.i = obj->surface->w;
	size.j = obj->surface->h;
	uv = get_uv(obj, size, hit);
	pos = (unsigned char *) obj->surface->pixels + ((int)(uv.j
				+ obj->pos_texture.y) *obj->surface->pitch
			+ (int)(uv.i + obj->pos_texture.x) *bpp);
	get_col(obj, bpp, pos);
}
