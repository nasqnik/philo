/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:54:45 by anikitin          #+#    #+#             */
/*   Updated: 2025/02/25 14:47:24 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int main(int argc, char **argv)
{
    t_info info;
    
    if (!(argc >= 5 && argc <= 6))
        return (printf("Error: enter correct amount of arguments\n"), 1);
    if (check_args(argc, argv))
        return (printf("Error: the arguments should have numeric format and can't be negative\n"), 1);
    if (initialize(&info, argc, argv))
        return 1;    
}