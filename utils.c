/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:05:30 by anikitin          #+#    #+#             */
/*   Updated: 2025/03/14 14:51:04 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long ft_atoll(const char *str)
{
	long long	nb;
	int			i;

	nb = 0;
	i = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	while (str[i])
		i++;
	if (i > 9)
		return (LLONG_MAX);
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb);
}

int check_args(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = 0;
        if (!argv[i][j])
            return 1;
        while (argv[i][j])
        {
            if (!(argv[i][j] >= '0' && argv[i][j] <= '9')) // plus is fine
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}


unsigned long long current_time(void)
{
    struct timeval time;
    
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void free_struct(t_info *info, int flag)
{
    unsigned long long i;
    
    if (info->forks)
        free(info->forks);
    if (info->philos)
        free(info->philos);
    i = 0;
    if (flag)
    {
        while (i < info->num_philo)
        {
            pthread_mutex_destroy(&info->mutex_fork[i]);
            i++;
        }
        pthread_mutex_destroy(&info->mutex_death);
        pthread_mutex_destroy(&info->mutex_eat);
        pthread_mutex_destroy(&info->mutex_print);
        free(info->mutex_fork);
    }
}

int printer(t_info *info, int id, int status)
{
    pthread_mutex_lock(&info->mutex_print);
    if (status == DEAD)
        printf("%llu %i died\n", current_time() - info->start_time, id);
    if (dead(info) == 1)
        return (pthread_mutex_unlock(&info->mutex_print), 1);
    else
    {
        printf("%llu %i ", current_time() - info->start_time, id);
        if (status == FORK)
            printf("has taken a fork\n");
        else if (status == EAT)
            printf("is eating\n");
        else if (status == SLEEP)
            printf("is sleeping\n");
        else if (status == THINK)
            printf("is thinking\n");
    }
    pthread_mutex_unlock(&info->mutex_print);
    return (0);
}