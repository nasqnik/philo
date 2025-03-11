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

    unlock_forks(philo, first_fork, second_fork);
    return (0);
}