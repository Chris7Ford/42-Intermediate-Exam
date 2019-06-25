/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 10:01:52 by chford            #+#    #+#             */
/*   Updated: 2019/06/19 10:36:15 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	int		*temp;
	int		len_temp;
	int		first;
	int		i;
	int		j;

	if (na == 0 || nb == 0 || a == NULL || b == NULL)
		return ;
	if (nb > na)
	{
		len_temp = na;
		na = nb;
		nb = len_temp;
		temp = a;
		a = b;
		b = temp;
	}
	i = 0;
	j = 0;
	first = 1;
	while (i < na)
	{
		while (j < nb && a[i] > b[j])
			j++;
		if (a[i] == b[j])
		{
			if (!first)
				printf(" ");
			printf("%d", a[i]);
			first = 0;
		}
		i++;
	}
	printf("\n");
}
