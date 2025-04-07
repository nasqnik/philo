/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:59:42 by anikitin          #+#    #+#             */
/*   Updated: 2025/03/26 15:04:37 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_valid_num(char *arg)
{
	int	j;

	j = 0;
	while (arg[j] == ' ' || (arg[j] >= '\t' && arg[j] <= '\r'))
		j++;
	if (!arg[j])
		return (1);
	if (arg[j] == '+')
	{
		j++;
		if (!arg[j] || !(arg[j] >= '0' && arg[j] <= '9'))
			return (1);
	}
	while (arg[j])
	{
		if (!(arg[j] >= '0' && arg[j] <= '9'))
			return (1);
		j++;
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_valid_num(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	error(int msg)
{
	char	*str;

	str = NULL;
	if (msg == 1)
		str = "Error: enter correct amount of arguments";
	else if (msg == 2)
		str = "Error: incorrect argument type";
	else if (msg == 3)
		str = "Error: argument is bigger than an int";
	else if (msg == 4)
		str = "Error: malloc failed";
	else if (msg == 5)
		str = "Error: mutex_init failed";
	else if (msg == 6)
		str = "Error: pthread_create failed";
	else if (msg == 7)
		str = "Error: pthread_join failed";
	if (str != NULL)
		printf("%s\n", str);
	return (1);
}
