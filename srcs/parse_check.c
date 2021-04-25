/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:25:19 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/04/25 11:23:22 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	ck2(char *s, int i)
{
	if ((s[i] == ':' && s[i + 1] == ':')
		|| (s[i] == ':' && s[i + 1] == '\0')
		|| (s[i] == ':' && s[i + 1] == ' ')
		|| (s[i] == ' ' && s[i + 1] == '\0'))
		return (-1);
	return (1);
}

int	ck(char *s, char *check, int l)
{
	int		i;

	if (s[0] != ' ' || ft_strncmp(s, check, l) != 0)
		return (-1);
	i = l - 1;
	if ((s[l] < '0' || s[l] > '9') && s[l] != '-' && s[l] != '+')
		return (-1);
	while (s[i])
	{
		if (s[i] == '.')
			i++;
		if (ck2(s, i) == -1)
			return (-1);
		else if (s[i] == ':' || s[i] == '-' || s[i] == '+' || s[i] == ' ')
		{
			if (s[i] == ':' && s[i + 1] == ':')
				return (-1);
		}
		else if (ft_isdigit(s[i]) == 0)
			return (-1);
		i++;
	}
	return (1);
}
