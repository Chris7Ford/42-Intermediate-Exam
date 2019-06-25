/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 11:18:24 by chford            #+#    #+#             */
/*   Updated: 2019/06/21 11:48:37 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int           value;
	struct s_node **nodes;
};

int		height_tree(struct s_node *root)
{
	int		current;
	int		height;
	int		i;

	current = 0;
	height = 0;
	i = 0;
	while (root && root->nodes && root->nodes[i])
	{
		current = height_tree(root->nodes[i]) + 1;
		if (height <= current)
			height = current;
		i++;
	}
	return (height);
}
