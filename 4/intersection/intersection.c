/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:44:41 by exam              #+#    #+#             */
/*   Updated: 2019/06/25 10:49:06 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	void *content;
	struct s_node *next;
};

void *intersection(struct s_node *lst1, struct s_node *lst2)
{
	struct s_node	*elem1;
	struct s_node	*elem2;

	if (!lst1 || !lst2)
		return (0);
	elem1 = lst1;

	while (elem1)
	{
		elem2 = lst2;
		while (elem2)
		{
			if (elem1 == elem2)
				return (elem1);
			elem2 = elem2->next;
		}
		elem1 = elem1->next;
	}
	return (0);
}
