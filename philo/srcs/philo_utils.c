/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:28:46 by aribesni          #+#    #+#             */
/*   Updated: 2022/01/12 15:49:16 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_free(t_arg *arg)
{
	free(arg->th_id);
	free(arg->philos);
	free(arg->forks);
}

void	ft_usleep(long int time)
{
	long int	start_time;

	start_time = ft_get_time();
	while ((ft_get_time()) < time + start_time)
		usleep(time / 10);
}

long int	ft_get_time(void)
{
	long int		ret;
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_exit("Get time failed");
	ret = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ret);
}

int	ft_exit(char *error)
{
	printf("%s\n", error);
	return (1);
}
