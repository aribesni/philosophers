/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:20:22 by aribesni          #+#    #+#             */
/*   Updated: 2022/01/12 15:49:53 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_end_process(t_arg *arg)
{
	int	nb_ph;

	nb_ph = arg->nb_philo;
	while (nb_ph--)
		pthread_join(arg->th_id[nb_ph], NULL);
	nb_ph = arg->nb_philo;
	while (nb_ph--)
	{
		pthread_mutex_unlock(&arg->forks[nb_ph]);
		pthread_mutex_destroy(&arg->forks[nb_ph]);
	}
	pthread_mutex_unlock(&(*arg).mutex_init);
	pthread_mutex_destroy(&(*arg).mutex_init);
}

void	*ft_threads(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	philo->start = ft_get_time();
	philo->prev_meal = ft_get_time();
	if (philo->philo_id % 2 == 0)
		ft_usleep(philo->tto_eat / 10);
	while (!philo->arg->dead)
	{
		if (!ft_forks(philo) || !ft_eating(philo)
			|| !ft_sleeping(philo) || !ft_thinking(philo))
			return (NULL);
	}
	return (NULL);
}
