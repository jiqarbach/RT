/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:35:11 by yataji            #+#    #+#             */
/*   Updated: 2021/04/24 14:49:25 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_obj	*initobj2(t_obj *new)
{
	new->angle = 0;
	new->refl = 0;
	new->refr = 0;
	new->per_refr = 0;
	new->matter = 0;
	new->neg_obj = 0;
	new->size = 0;
	new->slice = (t_point){0, 0, 0};
	new->texture = ".";
	new->next = NULL;
	return (new);
}

t_obj	*initobj(void)
{
	t_obj		*new;

	new = (t_obj *)malloc(sizeof(t_obj));
	if (!(new))
		return (NULL);
	new->angle = 0;
	new->radius = 0;
	new->v = (t_vect){0, 0, 0};
	new->normal = (t_vect){0, 0, 0};
	new->color = (t_color){0, 0, 0};
	new->center = (t_point){0, 0, 0};
	new->trs = (t_point){0, 0, 0};
	new->pos_texture = (t_point){0, 0, 0};
	new->pos_slice = (t_point){0, 0, 0};
	new->rot = (t_rot){0, 0, 0};
	new = initobj2(new);
	return (new);
}

t_lights	*initlights(void)
{
	t_lights	*new;

	new = (t_lights *)malloc(sizeof(t_lights));
	if (!(new))
		return (NULL);
	new->color = (t_color){0, 0, 0};
	new->pos = (t_point){0, 0, 0};
	new->direction = (t_vect){0, 0, 0};
	new->intensity = 0;
	new->direct = 0;
	new->angle = 0;
	new->next = NULL;
	return (new);
}

t_cam	*initcam(void)
{
	t_cam	*new;

	new = (t_cam *)malloc(sizeof(t_cam));
	if (!(new))
		return (NULL);
	new->lokat = (t_point){0, 0, 0};
	new->lokfrm = (t_point){0, 0, 0};
	new->v = (t_point){0, 1, 0};
	new->u = (t_point){0, 0, 0};
	new->w = (t_point){0, 0, 0};
	new->ambiante = 0;
	new->fov = 0;
	new->plnw = 0;
	new->plnh = 0;
	new->next = NULL;
	return (new);
}
