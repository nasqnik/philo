/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:27:13 by anikitin          #+#    #+#             */
/*   Updated: 2025/03/26 16:44:08 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_forks(t_philo *philo, int first_fork, int second_fork)
{
	int	first;
	int	second;

	pthread_mutex_lock(&philo->shared_info->mutex_fork[first_fork]);
	first = philo->shared_info->fork_last_owner[first_fork];
	pthread_mutex_unlock(&philo->shared_info->mutex_fork[first_fork]);
	pthread_mutex_lock(&philo->shared_info->mutex_fork[second_fork]);
	second = philo->shared_info->fork_last_owner[second_fork];
	pthread_mutex_unlock(&philo->shared_info->mutex_fork[second_fork]);
	if (first != philo->id && second != philo->id)
		return (1);
	return (0);
}

void	lock_forks(t_philo *philo, int first_fork, int second_fork)
{
	pthread_mutex_lock(&philo->shared_info->mutex_fork[first_fork]);
	pthread_mutex_lock(&philo->shared_info->mutex_fork[second_fork]);
}

void	unlock_forks(t_philo *philo, int first_fork, int second_fork)
{
	pthread_mutex_unlock(&philo->shared_info->mutex_fork[first_fork]);
	pthread_mutex_unlock(&philo->shared_info->mutex_fork[second_fork]);
}

void	lock_order(t_philo *philo, int *first_fork, int *second_fork)
{
	if (philo->left_fork < philo->right_fork)
	{
		*first_fork = philo->left_fork;
		*second_fork = philo->right_fork;
	}
	else
	{
		*first_fork = philo->right_fork;
		*second_fork = philo->left_fork;
	}
}
