/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:57:30 by anikitin          #+#    #+#             */
/*   Updated: 2025/02/25 13:49:18 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <limits.h>

// #include <stdlib.h>
// #include <unistd.h>

typedef struct s_info
{
    long num_philo;
    long die_time;
    long eat_time;
    long sleep_time;
    long num_eat_times;
    
} t_info;

long	ft_atoi(const char *str);
int check_args(int argc, char **argv);
int initialize(t_info *info, int argc, char **argv);

#endif