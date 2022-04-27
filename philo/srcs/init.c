/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:53:33 by aribesni          #+#    #+#             */
/*   Updated: 2022/01/12 16:01:42 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_init_thread(t_arg *arg)
{
	int			i;
	pthread_t	*thread;
	pthread_t	death;

	i = 0;
	thread = malloc(sizeof(pthread_t) * arg->nb_philo);
	if (!thread)
		return (ft_exit("Thread malloc failed"));
	while (i < arg->nb_philo)
	{
		if (pthread_create(&thread[i], NULL, ft_threads, &arg->philos[i]) != 0)
			return (ft_exit("Thread creation failed"));
		i++;
	}
	if (pthread_create(&death, NULL, ft_is_dead, arg->philos) != 0)
		return (ft_exit("Thread creation failed"));
	if (pthread_join(death, NULL) != 0)
		return (ft_exit("Thread join failed"));
	arg->th_id = thread;
	return (0);
}

int	ft_init_mutex(t_arg *arg)
{
	int				i;
	pthread_mutex_t	*mutex;

	i = 0;
	mutex = malloc(sizeof(pthread_mutex_t) * arg->nb_philo);
	if (!mutex)
		return (ft_exit("Mutex malloc failed"));
	while (i < arg->nb_philo)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&arg->mutex_init, NULL);
	arg->forks = mutex;
	return (0);
}

static int	ft_init_philo_2(t_arg *arg, t_philo *philo, int *i)
{
	philo[*i].philo_id = *i;
	philo[*i].nb_philo = arg->nb_philo;
	philo[*i].nb_meal = 0;
	philo[*i].total_meals = arg->nb_meal;
	philo[*i].tto_eat = arg->tto_eat;
	philo[*i].tto_die = arg->tto_die;
	philo[*i].tto_sleep = arg->tto_sleep;
	philo[*i].prev_meal = ft_get_time();
	philo[*i].life = arg->tto_die;
	philo[*i].stop = 0;
	philo[*i].l_f = &arg->forks[philo[*i].philo_id];
	philo[*i].r_f = &arg->forks[(philo[*i].philo_id + 1) % arg->nb_philo];
	philo[*i].arg = arg;
	return (1);
}

int	ft_init_philo(t_arg *arg)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * arg->nb_philo);
	if (!philo)
		return (ft_exit("Malloc init philo failed"));
	while (i < arg->nb_philo)
	{
		if (!ft_init_philo_2(arg, philo, &i))
			return (0);
		i++;
	}
	arg->philos = philo;
	return (0);
}
