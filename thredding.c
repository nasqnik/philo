/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thredding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:45:53 by anikitin          #+#    #+#             */
/*   Updated: 2025/03/11 13:37:25 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int dead(t_info *info)
{
    int res;
    
    res = 0;
    pthread_mutex_lock(&info->mutex_death);
    if (info->dead == 1)
        res = 1;
    else
        res = 0;
    pthread_mutex_unlock(&info->mutex_death);
    return res;
}


void *routine(void *args)
{
    t_philo *philo;
    int first_fork;
    int second_fork;

    philo = (t_philo *)args;
    while (dead(philo->shared_info) == 0)
    {
        lock_order(philo, &first_fork, &second_fork);
        if (check_forks(philo, first_fork, second_fork))
        {
            lock_forks(philo, first_fork, second_fork);
            if (eat(philo))
                return (unlock_forks(philo, first_fork, second_fork), NULL);
            
        }
    }
    return (NULL);
}

void *monitor(void *args)
{
    
}

int start_thredding(t_info *info)
{
    unsigned long long i;

    i = 0;
    while (i < info->num_philo)
    {
        if (pthread_create(&info->philos[i].thread_id, NULL, &routine, &info->philos[i]))
            return (printf("Error: pthread_create failed\n"), 1);
        i++;
    }
    if (info->num_philo > 1)
    {
        if (pthread_create(&info->monitor, NULL, &monitor, info))
            return (printf("Error: pthread_create failed\n"), 1);
        if (pthread_join(info->monitor, NULL))
            return (printf("Error: pthread_join failed\n"), 1);
    }
    i = 0;
    while (i < info->num_philo)
    {
        if (pthread_join(info->philos[i].thread_id, NULL))
            return (printf("Error: pthread_join failed\n"), 1);
        i++;
    }
    return 0;
}
