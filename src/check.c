/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:20:27 by hbalasan          #+#    #+#             */
/*   Updated: 2023/05/22 20:07:16 by hbalasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	twin_check(int *arr, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] == arr[i])
			{
				free(arr);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	get_split_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_arg(char *arg)
{
	int		i;
	int		j;
	char	**str;

	str = ft_split(arg, ' ');
	i = -1;
	while (str[++i])
	{
		j = 0;
		if ((str[i][j] == '+' || str[i][j] == '-') && str[i][j + 1])
			j++;
		while (str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
			{
				ft_free(str);
				return (-1);
			}
			j++;
		}
	}
	ft_free(str);
	if (i == 0)
		exit(0);
	return (i);
}

int	check_if_sorted(int *arr, int arg_count)
{
	int	i;

	i = 0;
	while (i + 1 < arg_count)
	{
		if (arr[i] < arr[i + 1])
			i++;
		else
			return (0);
	}
	free(arr);
	return (-1);
}
