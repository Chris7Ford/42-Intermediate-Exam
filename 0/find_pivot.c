/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 10:53:28 by chford            #+#    #+#             */
/*   Updated: 2019/06/21 11:07:05 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_total(int *arr, int n)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while (i < n)
		sum += arr[i++];
	return (sum);
}

int		find_pivot(int *arr, int n)
{
	int		running;
	int		total;
	int		i;
	i = 0;
	running = 0;
	total = get_total(arr, n);
	while (i < n)
	{
		total -= arr[i];
		if (running == total)
			return (i);
		running += arr[i];
		i++;
	}
	return (-1);
}
