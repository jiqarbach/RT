/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:18:59 by yataji            #+#    #+#             */
/*   Updated: 2021/04/23 17:30:58 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	ft_matter(int matter)
{
	if (matter == 1)
		return (WATER);
	else if (matter == 2)
		return (DIAMOND);
	else if (matter == 3)
		return (GLASS);
	return (0);
}

int	parse_texture(t_obj *obj, char *str)
{
	obj->texture = ft_strdup(str);
	if (ft_strcmp(obj->texture, ".") != 0)
	{
		obj->surface = IMG_Load(obj->texture);
		if (!obj->surface)
			sdl_error("can't load surface");
	}
	return (1);
}
