/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:38:03 by anikitin          #+#    #+#             */
/*   Updated: 2025/03/10 13:32:17 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int initialize_mutexes(t_info *info)
{
    unsigned long long i;
    // do we need to initialize mutex before destroying it actually?
    
    i = 0;
    info->mutex_fork = malloc(sizeof(pthread_mutex_t) * info->num_philo);
    if (!info->mutex_fork)
        return (1);
    while (i < info->num_philo)
    {
        if (pthread_mutex_init(&info->mutex_fork[i], NULL)) // why NULL?
            return (1);
        i++;
    }
    if (pthread_mutex_init(&info->mutex_death, NULL) ||
        pthread_mutex_init(&info->mutex_print, NULL) ||
        pthread_mutex_init(&info->mutex_eat, NULL))
        return (1);
    return (0);
}

int initialize_forks(t_info *info)
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
    return 0;
}

int initialize_philos(t_info *info)
{
    unsigned long long i;

    i = 0;
    info->philos = malloc(sizeof(t_philo) * info->num_philo);
    if (!info->philos)
        return (printf("Error: malloc failed\n"), 1);
    info->start_time = current_time();
    while (i < info->num_philo)
    {
        info->philos[i].id = i + 1;
        info->philos[i].left_fork = i;
        info->philos[i].right_fork = (i + 1) % info->num_philo;
        info->philos[i].last_meal_time = info->start_time;
        info->philos[i].meal_count = 0;
        info->philos[i].shared_info = info;
        i++;
    }
    
    return 0;
}


int initialize_info(t_info *info, int argc, char **argv)
{
    info->num_philo = ft_atoll(argv[1]);
    info->time_die = ft_atoll(argv[2]);
    info->time_eat = ft_atoll(argv[3]);
    info->time_sleep = ft_atoll(argv[4]);
    info->eat_times = -1;
    info->dead = 0;
    info->philos = NULL;
    info->forks = NULL;
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
    return 0;
}


int initialize(t_info *info, int argc, char **argv)
{
    if (initialize_info(info, argc, argv))
        return 1;
    if (info->eat_times == 0)
        return 0;
    initialize_forks(info);
    if (initialize_philos(info))
        return (free_struct(info, 0), 1);
    if (initialize_mutexes(info))
        return (free_struct(info, 0), printf("Error: Mutex init failed\n"), 1);
        
    // printf("start time: %lld\n", info->start_time);
    // for (unsigned long long i = 0; i < info->num_philo; i++)
    // {
    //     printf("philo %u fork: %i\n", info->philos[i].id, info->forks[i]);
    //     printf("left_fork: %i right_fork: %i\n", info->philos[i].left_fork, info->philos[i].right_fork);
    // }
    return 0;
}