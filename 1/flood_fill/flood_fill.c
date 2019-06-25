/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 09:10:00 by exam              #+#    #+#             */
/*   Updated: 2019/06/25 09:22:04 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

int		check_top(char **tab, t_point begin, char target)
{
	if (begin.y > 0 && tab[begin.y - 1][begin.x] == target)
		return (1);
	return (0);
}

int		check_left(char **tab, t_point begin, char target)
{
	if (begin.x > 0 && tab[begin.y][begin.x - 1] == target)
		return (1);
	return (0);
}

int		check_bottom(char **tab, t_point begin, t_point size, char target)
{
	if (begin.y < size.y - 1 && tab[begin.y + 1][begin.x] == target)
		return (1);
	return (0);
}

int		check_right(char **tab, t_point begin, t_point size, char target)
{
	if (begin.x < size.x - 1 && tab[begin.y][begin.x + 1] == target)
		return (1);
	return (0);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	t_point	copy;
	char	target;

	target = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
	if (check_top(tab, begin, target))
	{
		copy = begin;
		copy.y -= 1;
		flood_fill(tab, size, copy);
	}
	if (check_left(tab, begin, target))
	{
		copy = begin;
		copy.x -= 1;
		flood_fill(tab, size, copy);
	}
	if (check_bottom(tab, begin, size, target))
	{
		copy = begin;
		copy.y += 1;
		flood_fill(tab, size, copy);
	}
	if (check_right(tab, begin, size, target))
	{
		copy = begin;
		copy.x += 1;
		flood_fill(tab, size, copy);
	}
}
