/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thredding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:45:53 by anikitin          #+#    #+#             */
/*   Updated: 2025/03/26 16:19:46 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead(t_info *info)
{
	int	res;

	res = 0;
	pthread_mutex_lock(&info->mutex_death);
	if (info->dead == 1)
		res = 1;
	else
		res = 0;
	pthread_mutex_unlock(&info->mutex_death);
	return (res);
}

void	one_philo_routine(t_philo *philo)
{
	ft_usleep(philo->shared_info->time_die, philo);
	philo->shared_info->dead = 1;
	printer(philo->shared_info, philo->id, DEAD);
}

void	*routine(void *args)
{
	t_philo	*philo;
	int		first_fork;
	int		second_fork;

	philo = (t_philo *)args;
	if (philo->shared_info->num_philo == 1)
	{
		one_philo_routine(philo);
		return (NULL);
	}
	while (dead(philo->shared_info) == 0)
	{
		lock_order(philo, &first_fork, &second_fork);
		if (check_forks(philo, first_fork, second_fork))
		{
			lock_forks(philo, first_fork, second_fork);
			if (eat(philo))
				return (unlock_forks(philo, first_fork, second_fork), NULL);
			if (p_sleep(philo) == 1)
				return (NULL);
			if (think(philo) == 1)
				return (NULL);
		}
	}
	return (NULL);
}

int	start_thredding(t_info *info)
{
	unsigned long long	i;

	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_create(&info->philos[i].thread_id, NULL,
				&routine, &info->philos[i]))
			return (error(6));
		i++;
	}
	if (info->num_philo > 1)
	{
		if (pthread_create(&info->monitor, NULL, &monitor, info))
			return (error(6));
		if (pthread_join(info->monitor, NULL))
			return (error(7));
	}
	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_join(info->philos[i].thread_id, NULL))
			return (error(7));
		i++;
	}
	return (0);
}
