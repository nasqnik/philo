/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:57:30 by anikitin          #+#    #+#             */
/*   Updated: 2025/02/26 12:48:16 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>


typedef struct s_info
{
    unsigned long long num_philo;
    unsigned long long time_die;
    unsigned long long time_eat;
    unsigned long long time_sleep;
    long long eat_times;
    int *forks;
    
} t_info;

// utils.c
long long ft_atoll(const char *str);
int check_args(int argc, char **argv);

// init.c
int initialize(t_info *info, int argc, char **argv);

#endif