/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:20:08 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/04/25 11:15:45 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	ft_lights(t_rt *rt, char *str)
{
	rt->tmpl = initlights();
	if (lights(rt->tmpl, str, rt->fd) == -1)
		return (-1);
	rt->tmpl->next = rt->lights;
	rt->lights = rt->tmpl;
	return (0);
}

int	stocklights2(t_lights *lights, char **value, int ck)
{
	if (ck == 4 && ft_strcmp(value[0], " direction") == 0)
		lights->direction = stk(value);
	else if (ck == 2 && ft_strcmp(value[0], " direct_light") == 0)
		lights->direct = abs(ft_atoi(value[1]));
	else if (ck == 2 && ft_strcmp(value[0], " angle") == 0)
		lights->angle = abs(ft_atoi(value[1]));
	else
	{
		ft_strdel(value);
		return (-1);
	}
	return (1);
}

int	stocklights(t_lights *lights, char *str)
{
	char	**value;
	int		ck;

	value = ft_strsplit(str, ':');
	ck = ft_lendd(value);
	if (ck != 4 && ck != 2)
		return (-1);
	if (ck == 2 && ft_strcmp(value[0], " intensity") == 0)
	{
		lights->intensity = ft_atoi(value[1]);
		if (lights->intensity < 0)
			lights->intensity = 0;
		lights->intensity = max(lights->intensity, 100);
	}
	else if (ck == 4 && ft_strcmp(value[0], " color") == 0)
		lights->color = checkcolorvalue(value);
	else if (ck == 4 && ft_strcmp(value[0], " pos") == 0)
		lights->pos = stk(value);
	else if (stocklights2(lights, value, ck) == -1)
		return (-1);
	return (1);
}

int	lights2(t_lights *lights, int fd, char *str, int check)
{
	if (str && ck(str, " direct_light: ", 15) > 0)
		check = stocklights(lights, str);
	else if (str && ck(str, " direction: ", 12) > 0)
		check = stocklights(lights, str);
	else if (str && ck(str, " angle: ", 8) > 0)
		check = stocklights(lights, str);
	return (check);
}

int	lights(t_lights *lights, char *str, int fd)
{
	int		l;
	int		check;

	l = -1;
	while (++l < 6)
	{
		check = -1;
		if (get_next_line(fd, &str) < 0)
			return (-1);
		check = lights2(lights, fd, str, check);
		if (str && ck(str, " intensity: ", 12) > 0)
			check = stocklights(lights, str);
		else if (str && ck(str, " color: ", 8) > 0)
			check = stocklights(lights, str);
		else if (str && ck(str, " pos: ", 6) > 0)
			check = stocklights(lights, str);
		if (check == -1)
		{
			ft_strdel(&str);
			return (-1);
		}
		ft_strdel(&str);
	}
	return (1);
}
