#include "philo.h"

int check_meal_num(t_info *info)
{
    unsigned long long i;

    i = 0;
    while (i < info->num_philo)
    {
        if (info->philos[i].meal_count < (unsigned long long)info->eat_times)
            return (0);
        i++;
    }
    return 1;
}

void    done_meal_num(t_info *info)
{
    pthread_mutex_lock(&info->mutex_death);
    info->dead = 1;
    pthread_mutex_unlock(&info->mutex_death);
    pthread_mutex_unlock(&info->mutex_eat);
}

void philo_death(t_info *info, unsigned long long i)
{
    pthread_mutex_lock(&info->mutex_death);
    info->dead = 1;
    pthread_mutex_unlock(&info->mutex_death);
    printer(info, info->philos[i].id, DEAD);
    pthread_mutex_unlock(&info->mutex_eat);
}

void *monitor(void *args)
{
    t_info *info;
    unsigned long long i;

    info = (t_info *)args;
    while (dead(info) == 0)
    {
        i = 0;
        while (i < info->num_philo)
        {
            pthread_mutex_lock(&info->mutex_eat);
            if (info->eat_times > 0 && check_meal_num(info))
                return (done_meal_num(info), NULL);
            if (current_time() > info->philos[i].last_meal_time + info->time_die)
                return (philo_death(info, i), NULL);
            pthread_mutex_unlock(&info->mutex_eat);
            i++;
        }
    }
    return NULL;
}