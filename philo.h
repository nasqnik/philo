/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:57:30 by anikitin          #+#    #+#             */
/*   Updated: 2025/03/07 14:47:20 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>


typedef struct s_philo t_philo;

typedef struct s_info
{
    unsigned long long	num_philo;
    unsigned long long	time_die;
    unsigned long long	time_eat;
    unsigned long long	time_sleep;
    long long			eat_times;
    int					*forks;
    t_philo				*philos;
    long long			start_time;
	unsigned int		dead;

	pthread_mutex_t 	*mutex_fork;
	pthread_mutex_t		mutex_death;
	pthread_mutex_t		mutex_print;
	pthread_mutex_t		mutex_eat;
	
} t_info;

typedef struct s_philo
{
    int					id;
    int					right_fork;
    int					left_fork;
    long long			last_meal_time;
    int					meal_count;
    t_info				*shared_info; 
    pthread_t           philo_thread;
     
} t_philo;


// utils.c
long long	ft_atoll(const char *str);
int			check_args(int argc, char **argv);
long long	current_time(void);
void		free_struct(t_info *info, int flag);

// init.c
int			initialize(t_info *info, int argc, char **argv);

#endif