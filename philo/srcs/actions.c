/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:15:00 by aribesni          #+#    #+#             */
/*   Updated: 2022/01/12 16:39:26 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_forks_else(t_philo *philo)
{
	pthread_mutex_lock(philo->l_f);
	pthread_mutex_lock(philo->r_f);
	pthread_mutex_lock(&philo->print_status);
	if (philo->stop != 1)
	{
		printf("%ldms Philo %d has taken a fork\n",
			ft_get_time() - philo->start, philo->philo_id + 1);
		printf("%ldms Philo %d has taken a fork\n",
			ft_get_time() - philo->start, philo->philo_id + 1);
	}
	pthread_mutex_unlock(&philo->print_status);
}

int	ft_forks(t_philo *philo)
{
	if (philo->arg->dead || philo->stop || ft_count_meals(philo))
		return (0);
	if (philo->philo_id + 1 != philo->nb_philo)
	{
		pthread_mutex_lock(philo->r_f);
		pthread_mutex_lock(philo->l_f);
		pthread_mutex_lock(&philo->print_status);
		if (philo->stop != 1)
		{
			printf("%ldms Philo %d has taken a fork\n",
				ft_get_time() - philo->start, philo->philo_id + 1);
			printf("%ldms Philo %d has taken a fork\n",
				ft_get_time() - philo->start, philo->philo_id + 1);
		}
		pthread_mutex_unlock(&philo->print_status);
	}
	else
		ft_forks_else(philo);
	return (1);
}

int	ft_eating(t_philo *philo)
{
	if (philo->arg->dead || philo->stop || ft_count_meals(philo))
		return (0);
	pthread_mutex_lock(&philo->print_status);
	printf("%ldms Philo %d is eating\n",
		ft_get_time() - philo->start, philo->philo_id + 1);
	pthread_mutex_unlock(&philo->print_status);
	philo->nb_meal++;
	philo->prev_meal = ft_get_time();
	ft_usleep(philo->tto_eat);
	pthread_mutex_unlock(philo->l_f);
	pthread_mutex_unlock(philo->r_f);
	return (1);
}

int	ft_sleeping(t_philo *philo)
{
	if (philo->arg->dead || philo->stop || ft_count_meals(philo))
		return (0);
	pthread_mutex_lock(&philo->print_status);
	printf("%ldms Philo %d is sleeping\n",
		ft_get_time() - philo->start, philo->philo_id + 1);
	pthread_mutex_unlock(&philo->print_status);
	ft_usleep(philo->tto_sleep);
	return (1);
}

int	ft_thinking(t_philo *philo)
{
	if (philo->arg->dead || philo->stop || ft_count_meals(philo))
		return (0);
	pthread_mutex_lock(&philo->print_status);
	printf("%ldms Philo %d is thinking\n",
		ft_get_time() - philo->start, philo->philo_id + 1);
	pthread_mutex_unlock(&philo->print_status);
	return (1);
}
