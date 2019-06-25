/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 09:27:15 by exam              #+#    #+#             */
/*   Updated: 2019/06/25 09:44:11 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void reverse_tree(struct s_node *root)
{
	struct s_node	*temp;

	if (root == 0)
		return ;
	temp = root->right;
	root->right = root->left;
	root->left = temp;
	if (root->right)
		reverse_tree(root->right);
	if (root->left)
		reverse_tree(root->left);
}
