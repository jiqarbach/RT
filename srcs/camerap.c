/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:20:09 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/04/09 18:41:42 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	ft_cam(t_rt *rt, char *str)
{
	rt->ck = 1;
	rt->tmpc = initcam();
	if (camera(rt->tmpc, str, rt->fd) == -1)
		return (-1);
	rt->tmpc->next = rt->cam;
	rt->cam = rt->tmpc;
	return (0);
}

int	stockcamera(t_cam *cam, char *str)
{
	char	**value;
	int		ck;

	value = ft_strsplit(str, ':');
	ck = ft_lendd(value);
	if (ck != 4 && ck != 2)
		return (-1);
	if (ck == 4 && ft_strcmp(value[0], " lokat") == 0)
		cam->lokat = stk(value);
	else if (ck == 4 && ft_strcmp(value[0], " lokfrm") == 0)
		cam->lokfrm = stk(value);
	else if (ck == 2 && ft_strcmp(value[0], " fov") == 0)
		cam->fov = abs(ft_atoi(value[1]));
	else if (ck == 2 && ft_strcmp(value[0], " ambiante") == 0)
		cam->ambiante = fabs(ft_atof(value[1]));
	else
	{
		ft_strdel(value);
		return (-1);
	}
	return (1);
}

int	camera(t_cam *cam, char *str, int fd)
{
	int		l;
	int		check;

	l = -1;
	while (++l < 4)
	{
		check = -1;
		if (get_next_line(fd, &str) < 0)
			return (-1);
		if (str && ck(str, " lokat: ", 8) > 0)
			check = stockcamera(cam, str);
		else if (str && ck(str, " lokfrm: ", 9) > 0)
			check = stockcamera(cam, str);
		else if (str && ck(str, " fov: ", 6) > 0)
			check = stockcamera(cam, str);
		else if (str && ck(str, " ambiante: ", 11) > 0)
			check = stockcamera(cam, str);
		if (check == -1)
			return (-1);
		ft_strdel(&str);
	}
	initcamera(cam);
	return (1);
}
