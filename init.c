/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:38:03 by anikitin          #+#    #+#             */
/*   Updated: 2025/02/26 12:50:15 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void initialize_forks(t_info *info)
{
    unsigned long long i;
    
    i = 0;
    while (i < info->num_philo)
    {
        if (i == 0 || i == info->num_philo - 1)
            info->forks[i] = info->num_philo;
        else if (i % 2 == 0)
            info->forks[i] = i + 2;
        else 
            info->forks[i] = i + 1;
        i++;
    }
}
int initialize(t_info *info, int argc, char **argv)
{
    info->num_philo = ft_atoll(argv[1]);
    info->time_die = ft_atoll(argv[2]);
    info->time_eat = ft_atoll(argv[3]);
    info->time_sleep = ft_atoll(argv[4]);
    info->eat_times = -1;
    if (argc == 6)
        info->eat_times = ft_atoll(argv[5]);
    if (info->num_philo >= INT_MAX || info->time_die >= INT_MAX || info->time_eat >= INT_MAX
        || info->time_sleep >= INT_MAX || (argc == 6 && info->eat_times >= INT_MAX))
        return (printf("Error: argument is bigger than an int\n"), 1); // check the INT_MAX
    if (argc == 6 && info->eat_times == 0)
        return 0;
    info->forks = malloc(sizeof(int) * info->num_philo);
    if (!info->forks)
        return (printf("Error: malloc failed in initialize\n"), 1);
    initialize_forks(info);
    for (unsigned long long i = 0; i < info->num_philo; i++)
        printf("philo %llu fork: %i\n", i + 1, info->forks[i]);    

    return 0;
}