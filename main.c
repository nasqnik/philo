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
