/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:54:45 by anikitin          #+#    #+#             */
/*   Updated: 2025/03/26 16:18:01 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int error(int msg)
{
	char *str;

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

int	main(int argc, char **argv)
{
	t_info	info;

	if (!(argc >= 5 && argc <= 6))
		return (error(1));
	if (check_args(argc, argv))
		return (error(2));
	if (initialize(&info, argc, argv))
		return (1);
	if (start_thredding(&info))
		return (1);
	free_struct(&info, 1);
	return (0);
}
