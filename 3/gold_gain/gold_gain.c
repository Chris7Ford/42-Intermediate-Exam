/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_gain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 09:49:22 by exam              #+#    #+#             */
/*   Updated: 2019/06/25 10:36:56 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_max_digit(int a, int b, int c)
{
	if (a >= b && a >= c)
		return (a);
	else if (b >= a && b >= c)
		return (b);
	else
		return (c);
}

void		get_max(int **mine, int i, int j, int *max)
{
	int		add;

	add = get_max_digit(mine[j - 1][i - 1], mine[j][i - 1], mine[j + 1][i - 1]);
	mine[j][i] += add;
	if (mine[j][i] > *max)
		*max = mine[j][i];
}

void		get_max_top_row(int **mine, int i, int j, int *max)
{
	int		add;

	add = get_max_digit(-2137483647, mine[j][i - 1], mine[j + 1][i - 1]);
	mine[j][i] += add;
	if (mine[j][i] > *max)
		*max = mine[j][i];
}

void		get_max_bottom_row(int **mine, int i, int j, int *max)
{
	int		add;

	add = get_max_digit(-2137483647, mine[j][i - 1], mine[j - 1][i - 1]);
	mine[j][i] += add;
	if (mine[j][i] > *max)
		*max = mine[j][i];
}

int		gold_gain(int **mine, int n)
{
	int		i;
	int		j;
	int		max;

	if (n == 0 || mine == 0)
		return (0);
	if (n == 1)
		return (mine[0][0]);
	i = 1;
	max = -2137483647;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (j == 0)
				get_max_top_row(mine, i, j, &max);
			else if (j == n - 1)
				get_max_bottom_row(mine, i, j, &max);
			else
				get_max(mine, i, j, &max);
			j++;
		}
		i++;
	}
	return (max);
}
