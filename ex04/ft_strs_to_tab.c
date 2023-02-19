/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmirzaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:22:19 by mmirzaie          #+#    #+#             */
/*   Updated: 2023/02/14 15:28:19 by mmirzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		size;
	int		i;
	char	*dup;

	size = ft_strlen(src) + 1;
	if (size == 0)
		return (0);
	dup = malloc(sizeof(char) * size);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*array;

	array = malloc((ac + 1) * sizeof(t_stock_str));
	if (!array)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		array[i].size = ft_strlen(av[i]);
		array[i].str = av[i];
		array[i].copy = ft_strdup(av[i]);
		i++;
	}
	array[i].str = 0;
	array[i].copy = 0;
	return (array);
}
/*
int	main(int ac, char **av)
{
	t_stock_str *array;
	array = ft_strs_to_tab(ac, av);

	int i = 0;
	while (i < ac && array)
	{
		printf("\nstring: %s\n", array[i].str);
		printf("string length: %d\n", array[i].size);
		printf("string cpy: %s\n", array[i].copy);
		i++;
	}
	free(array);
	return (0);
}*/