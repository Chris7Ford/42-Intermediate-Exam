/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 10:47:48 by chford            #+#    #+#             */
/*   Updated: 2019/06/19 11:14:33 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void          *content;
	struct s_node *next;
};

struct s_stack {
	struct s_node *top;
};

struct s_stack *init(void)
{
	struct s_stack	*new;
	new = malloc(sizeof(struct s_stack));
	new->top = 0;
	return (new);
}

void *pop(struct s_stack *stack)
{
	struct s_node	*elem;
	void			*info;

	if (!(stack) || !(stack->top))
		return (0);
	elem = stack->top;
	info = elem->content;
	stack->top = elem->next;
	free(elem);
	return (info);
}

void push(struct s_stack *stack, void *content)
{
	struct s_node	*new;

	new = malloc(sizeof(struct s_node));
	new->content = content;
	new->next = stack->top;
	stack->top = new;
}

void *peek(struct s_stack *stack)
{
	if (!(stack) || !(stack->top) || !(stack->top->content))
		return (0);
	return (stack->top->content);
}

int isEmpty(struct s_stack *stack)
{
	if (!(stack) || !(stack->top))
		return (1);
	return (0);
}
