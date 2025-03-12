/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:33:33 by anikitin          #+#    #+#             */
/*   Updated: 2025/03/11 13:56:49 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_usleep(unsigned long long time, t_philo *philo)
{
    unsigned long long start;

    start = current_time();
    while (current_time() < (start + time))
    {
        if (dead(philo->shared_info))
            return 1;
        usleep(500);
    }
    return 0;
}

int think(t_philo *philo)
{
    if (printer(philo->shared_info, philo->id, THINK) == 1)
        return (1);
    return 0;
}

int p_sleep(t_philo *philo)
{
    if (printer(philo->shared_info, philo->id, SLEEP) == 1)
        return (1);
    if (ft_usleep(philo->shared_info->time_sleep, philo) == 1)
        return (1);
    return (0);
}

int eat(t_philo *philo)
{
    int first_fork;
    int second_fork;

    lock_order(philo, &first_fork, &second_fork);
    if (printer(philo->shared_info, philo->id, FORK) == 1)
        return (1);
    if (printer(philo->shared_info, philo->id, FORK) == 1)
        return (1);
    if (printer(philo->shared_info, philo->id, EAT) == 1)
        return (1);
    if (ft_usleep(philo->shared_info->time_eat, philo) == 1)
        return (1);
    pthread_mutex_lock(&philo->shared_info->mutex_eat);
    philo->last_meal_time = current_time();
    philo->meal_count++;
    pthread_mutex_unlock(&philo->shared_info->mutex_eat);
    philo->shared_info->forks[philo->left_fork] = philo->id;
    philo->shared_info->forks[philo->left_fork] = philo->id;
    unlock_forks(philo, first_fork, second_fork);
    return (0);
}