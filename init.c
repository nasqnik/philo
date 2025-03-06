/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:38:03 by anikitin          #+#    #+#             */
/*   Updated: 2025/03/06 16:51:13 by anikitin         ###   ########.fr       */
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

int initialize_philos(t_info *info)
{
    unsigned long long i;
    struct timeval time;

    i = 0;
    info->philos = malloc(sizeof(t_philo) * info->num_philo);
    if (!info->philos)
        return (free(info->forks), 1);
    while (i < info->num_philo)
    {
        info->philos[i].id = i + 1;
        info->philos[i].left_fork = i;
        info->philos[i].right_fork = (i + 1) % info->num_philo;

        info->philos[i].shared_info = info;
        i++;
    }
    
    return 0;
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
        return (printf("Error: malloc failed\n"), 1);
    initialize_forks(info);
    if (initialize_philos(info))
        return (printf("Error: malloc failed\n"), 1);;
    for (unsigned long long i = 0; i < info->num_philo; i++)
    {
        printf("philo %u fork: %i\n", info->philos[i].id, info->forks[i]);
        printf("left_fork: %i right_fork: %i\n", info->philos[i].left_fork, info->philos[i].right_fork);
    }

    return 0;
}