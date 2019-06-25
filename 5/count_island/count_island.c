/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:13:52 by exam              #+#    #+#             */
/*   Updated: 2019/06/25 12:40:44 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * This code did not pass because of a small error
 */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

struct s_node {
	struct s_node	*next;
	char 			*str;
};

typedef struct s_point	t_point;
struct					s_point
{
	int					x;
	int					y;
};

int				ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct s_node	*create_elem(char *str)
{
	struct s_node	*new;

	new = malloc(sizeof(struct s_node));
	new->str = str;
	new->next = 0;
	return (new);
}

void			push_list(struct s_node **head, char *str)
{
	struct s_node	*elem;

	if (!head)
		return ;
	elem = *head;
	if (!elem)
	{
		*head = create_elem(str);
		return ;
	}
	while (elem->next)
		elem = elem->next;
	elem->next = create_elem(str);
}

int				get_line_length(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char			*ft_strdup(char *str)
{
	char	*new;
	int		len;
	int		i;

	len = ft_strlen(str);
	new = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void			ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}


int				get_list_length(struct s_node *head)
{
	struct s_node	*elem;
	int				i;

	i = 0;
	elem = head;
	while (elem)
	{
		i++;
		elem = elem->next;
	}
	return (i);
}

void			ft_strcpy(char *dst, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

void			copy_list_into_array(struct s_node *head, char **arr)
{
	struct s_node	*elem;
	int				i;

	elem = head;
	i = 0;
	while (elem)
	{
		ft_strcpy(arr[i], elem->str);
		elem = elem->next;
		i++;
	}
}

void			print_array(char **str, int height)
{
	int		i;

	i = 0;
	while (i < height)
	{
		ft_putstr(str[i]);
		i++;
	}
}

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

void	flood_fill(char **tab, t_point size, t_point begin, char current_island)
{
	t_point	copy;
	char	target;

	target = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = current_island;
	if (check_top(tab, begin, target))
	{
		copy = begin;
		copy.y -= 1;
		flood_fill(tab, size, copy, current_island);
	}
	if (check_left(tab, begin, target))
	{
		copy = begin;
		copy.x -= 1;
		flood_fill(tab, size, copy, current_island);
	}
	if (check_bottom(tab, begin, size, target))
	{
		copy = begin;
		copy.y += 1;
		flood_fill(tab, size, copy, current_island);
	}
	if (check_right(tab, begin, size, target))
	{
		copy = begin;
		copy.x += 1;
		flood_fill(tab, size, copy, current_island);
	}
}

void			fill_islands(char **arr, int length_tall, int length_width)
{
	t_point	begin;
	t_point	size;
	char	current_island;
	int		i;
	int		j;

	current_island = '0';
	i = 0;
	while (i < length_tall)
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'X')
			{
				begin.x = j;
				begin.y = i;
				size.x = length_width;
				size.y = length_tall;
				flood_fill(arr, size, begin, current_island);
				current_island++;
			}
			j++;
		}
		i++;
	}
}

int				main(int argc, char **argv)
{
	int				fd;
	int				ret;
	int				length_width;
	int				length_tall;
	int				i;
	char			buff[1024];
	char			*new_buff;
	char			**arr;
	struct s_node	*head;

	head = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			write(1, "\n", 1);
			return (0);
		}
		read(fd, buff, 1024);
		length_width = get_line_length(buff) + 1;
		if (length_width == 1)
		{
			write(1, "\n", 1);
			return (0);
		}
		close(fd);
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			write(1, "\n", 1);
			return (0);
		}
		new_buff = malloc(sizeof(char) * length_width + 1);
		while ((ret = read(fd, new_buff, length_width)))
		{
			new_buff[ret] = '\0';
			push_list(&head, ft_strdup(new_buff));
		}
		length_tall = get_list_length(head);
		arr = malloc(sizeof(char *) * (length_tall));
		i = 0;
		while (i < length_tall)
		{
			arr[i] = malloc(sizeof(char) * (length_width));
			i++;
		}
		copy_list_into_array(head, arr);
		fill_islands(arr, length_tall, length_width);
		print_array(arr, length_tall);
	}
	else
		write (1, "\n", 1);
}

