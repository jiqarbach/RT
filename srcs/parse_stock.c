/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:18:12 by yataji            #+#    #+#             */
/*   Updated: 2021/04/26 10:51:26 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_varpars	initvarpars(int id)
{
	t_varpars	p;

	p.i = -1;
	p.j = 0;
	if (id == SPHERE)
		p.l = 13;
	else if (id == PLANE)
		p.l = 15;
	else if (id == CONE || id == CYLINDER)
		p.l = 16;
	else if (id == PARAPLOID)
		p.l = 6;
	return (p);
}

int	stockobj4(t_obj *obj, t_varpars p, char *s)
{
	if (p.c == 4 && ck(s, " center: ", 9) > 0
		&& !ft_strcmp(p.value[0], " center"))
		obj->center = stk(p.value);
	else if (obj->type != SPHERE && p.c == 4
		&& ck(s, " axis: ", 7) > 0 && !ft_strcmp(p.value[0], " axis"))
		obj->v = stk(p.value);
	else if (p.c == 4 && ck(s, " rot: ", 6) > 0
		&& !ft_strcmp(p.value[0], " rot"))
		obj->rot = stk(p.value);
	else if (p.c == 4 && ck(s, " trs: ", 6) > 0
		&& !ft_strcmp(p.value[0], " trs"))
		obj->trs = stk(p.value);
	else if (p.c == 4 && ck(s, " color: ", 8) > 0
		&& !ft_strcmp(p.value[0], " color"))
		obj->color = checkcolorvalue(p.value);
	else
	{
		ft_strdel(&s);
		ft_strdel(p.value);
		return (-1);
	}
	ft_strdel(p.value);
	ft_strdel(&s);
	return (1);
}

int	stockobj3(t_obj *obj, t_varpars p, char *s)
{
	if ((obj->type == SPHERE || obj->type == CYLINDER) && p.c == 2
		&& ck(s, " radius: ", 9) > 0 && !ft_strcmp(p.value[0], " radius"))
		obj->radius = abs(ft_atoi(p.value[1]));
	else if (obj->type != PARAPLOID && p.c == 2
		&& ck(s, " matter: ", 9) > 0 && !ft_strcmp(p.value[0], " matter"))
	{
		obj->matter = abs(ft_atoi(p.value[1]));
		obj->n2 = ft_matter(obj->matter);
	}
	else if (obj->type != PARAPLOID && p.c == 2
		&& ck(s, " perrfr: ", 9) > 0 && !ft_strcmp(p.value[0], " perrfr"))
		obj->per_refr = fabs(ft_atof(p.value[1]));
	else if (obj->type != PARAPLOID && p.c == 2
		&& ck(s, " neg_obj: ", 10) > 0 && !ft_strcmp(p.value[0], " neg_obj"))
		obj->neg_obj = abs(ft_atoi(p.value[1]));
	else if (obj->type != PARAPLOID && p.c == 4
		&& ck(s, " poslice: ", 10) > 0 && !ft_strcmp(p.value[0], " poslice"))
		obj->pos_slice = stk(p.value);
	else if (obj->type != PARAPLOID && p.c == 4
		&& ck(s, " postext: ", 10) > 0 && !ft_strcmp(p.value[0], " postext"))
		obj->pos_texture = stk(p.value);
	else if (stockobj4(obj, p, s) == -1)
		return (-1);
	return (1);
}

int	stockobj2(t_obj *obj, t_varpars p, char *s)
{
	if (obj->type != PARAPLOID && obj->type != SPHERE && p.c == 2
		&& ck(s, " size: ", 7) && !ft_strcmp(p.value[0], " size"))
		obj->size = abs(ft_atoi(p.value[1]));
	else if (obj->type != PARAPLOID && p.c == 2
		&& !ft_strcmp(p.value[0], " texture"))
	{
		p.value[1] = ft_strtrim(p.value[1]);
		if (!parse_texture(obj, p.value[1]))
			return (-1);
	}
	else if (obj->type != PARAPLOID && p.c == 4
		&& ck(s, " slice: ", 8) > 0 && !ft_strcmp(p.value[0], " slice"))
		obj->slice = stk(p.value);
	else if (obj->type != PARAPLOID && p.c == 2 && ck(s, " refl: ", 7) > 0
		&& !ft_strcmp(p.value[0], " refl"))
		obj->refl = abs(ft_atoi(p.value[1]));
	else if (obj->type != PARAPLOID && p.c == 2 && ck(s, " refr: ", 7) > 0
		&& !ft_strcmp(p.value[0], " refr"))
		obj->refr = abs(ft_atoi(p.value[1]));
	else if ((obj->type == PARAPLOID || obj->type == CONE) && p.c == 2
		&& ck(s, " angle: ", 8) > 0 && !ft_strcmp(p.value[0], " angle"))
		obj->angle = abs(ft_atoi(p.value[1]));
	else if (stockobj3(obj, p, s) == -1)
		return (-1);
	return (1);
}

int	stockobj(t_obj *obj, int id, char *s, int fd)
{
	t_varpars	p;

	p = initvarpars(id);
	while (++p.i < p.l)
	{
		if (get_next_line(fd, &s) < 0)
			return (-1);
		if (!s)
			return (-1);
		p.value = ft_strsplit(s, ':');
		p.c = ft_lendd(p.value);
		if (p.c != 2 && p.c != 4)
			return (-1);
		if (stockobj2(obj, p, s) == -1)
			return (-1);
	}
	if (obj->matter && obj->type != PARAPLOID)
		if (!obj->refr)
			return (-1);
	if (obj->refr && obj->type != PARAPLOID)
		if (!obj->matter)
			return (-1);
	return (1);
}
