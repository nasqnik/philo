/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:38:03 by anikitin          #+#    #+#             */
/*   Updated: 2025/02/25 13:49:37 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int initialize(t_info *info, int argc, char **argv)
{
    info->num_philo = ft_atoi(argv[1]); // make it into atoll
    info->die_time = ft_atoi(argv[2]);
    info->eat_time = ft_atoi(argv[3]);
    info->sleep_time = ft_atoi(argv[4]);
    
    if (argc == 6)
        info->num_eat_times = ft_atoi(argv[5]);
    else
        info->num_eat_times = -1;
    if (info->num_philo <= 0)
        return (printf("Error: Number of philos cannot be negative or equal to zero\n"), 1);
    else if (info->die_time < 0 || info->eat_time < 0 || info->sleep_time < 0)
        return (printf("Error: The time cannot be a negative number\n"), 1);
    else if (info->num_eat_times != -1 && info->num_eat_times < 0)
        return (printf("The number of times to eat cannot be a negative number\n"), 1);
    return 0;
}