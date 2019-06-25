/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asdf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:52:30 by chford            #+#    #+#             */
/*   Updated: 2019/06/20 11:09:43 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
}
void ft_putstr(char *str)
{
	int i;
	if (!str)
		return ;
	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}
int		ft_strlen(char *str)
{
	int i;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
char	*ft_strnew(int len)
{
	char	*res;
	int		i;
	i = -1;
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (++i <= len)
		res[i] = '\0';
	return (res);
}
int		appeared(char *sample, char *real)
{
	int		i;
	int		max;
	max = ft_strlen(real);
	i = -1;
	while (sample[++i]) //iterate through the proposed solution
	{
		if (i > max)  //if the length of the proposed solution is greater than the length of the haystack, we know the substring is not inside.
			return (0);
		if (sample[i] != real[i]) //
			return (0);
	}
	return (1);
}
int		is_included(char *sample, char *real)
{
	int i;
	i = -1;
	while (real[++i])
	{
		if (appeared(sample, &real[i])) //in this function, we are only looking for an exisiting substring match.
			return (1);
	}
	return (0);
}
int		is_included_in_all(char *str, char **strs)
{
	int i;
	i = -1;
	while (strs[++i]) //iterate through argv
	{
		if (!(is_included(str, strs[i])))
			return (0);
	}
	return (1);
}
char	*ft_strdup(char *str)
{
	int 	len;
	char	*res;
	int		i;
	len = ft_strlen(str);
	if (!(res = ft_strnew(len)))
		return (NULL);
	i = -1;
	while (str[++i])
		res[i] = str[i];
	return (res);
}
void	str_maxlenoc(char **strs)
{
	int		maxlen;
	char	*tmp;
	char	*res;
	int		start_index;
	int		curr_index;
	maxlen = ft_strlen(strs[0]);
	//get the length of the first string;
	start_index = -1;
	//starting the index at -1 (Wants to increment before)
	res = NULL;
	//set res (Our solution?) to NULL
	while (++start_index < maxlen) //maxlen is the length of the first string, so we are iterating through the first string
	{
		if (!(tmp = ft_strnew(maxlen)))
			return ; //Making a new string the same length as the length of the first string. Doing this for each iteration too?
		curr_index = 0; //Setting current index to 0
		while (strs[0][start_index + curr_index]) //adding the indices together. I imagine this is to remember where we started so we can get different substrings
		{
			tmp[curr_index] = strs[0][start_index + curr_index]; //copying the current index into the current index of the proposed solution, one char at a time.
			if (is_included_in_all(tmp, strs) && ft_strlen(res) < ft_strlen(tmp)) //Checkint to see if the current substring is in all params AND if its longer than the current best solution
			{
				if (res) //If we already have a best solution, free it because we have a new best solution
					free(res);
				if (!(res = ft_strdup(tmp))) //duplicate the new solution and store it into res
					return ;
			}
			curr_index++; //move current index over one to see if we can make it longer.
		}
		free(tmp);
	}
	if (res)
		ft_putstr(res); //After attempting all substrings, print the solution if we have one.
}
int		main(int ac, char **av)
{
	if (ac > 1)
	{
		str_maxlenoc(++av);
	}
	ft_putchar('\n');
	return (0);
}
