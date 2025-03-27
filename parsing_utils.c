/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:59:42 by anikitin          #+#    #+#             */
/*   Updated: 2025/03/26 15:04:37 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int is_valid_num(char *arg)
{
    int j;
    
    j = 0;
	while (arg[j] == ' ' || (arg[j] >= '\t' && arg[j] <= '\r'))
	    j++;
	if (!arg[j])
		return (1);
	if (arg[j] == '+')
	{
		j++;
		if (!arg[j] || !(arg[j] >= '0' && arg[j] <= '9'))
    		return (1);
	} 
	while (arg[j])
	{
		if (!(arg[j] >= '0' && arg[j] <= '9'))
			return (1);
		j++;
	}
    return (0);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_valid_num(argv[i]))
            return (1);
		i++;
	}
	return (0);
}