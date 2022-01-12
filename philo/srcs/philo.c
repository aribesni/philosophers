/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:11:25 by aribesni          #+#    #+#             */
/*   Updated: 2022/01/12 15:48:28 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_arg_is_valid(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9' || !ft_atoli(argv[i])
					|| ft_atoli(argv[i]) > 2147483647)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_check_args(t_arg *arg, int argc, char **argv)
{
	if ((argc == 5 || argc == 6) && ft_arg_is_valid(argv))
	{
		arg->nb_philo = ft_atoli(argv[1]);
		arg->tto_die = ft_atoli(argv[2]);
		arg->tto_eat = ft_atoli(argv[3]);
		arg->tto_sleep = ft_atoli(argv[4]);
		arg->dead = 0;
		if (argc == 6)
		{
			arg->nb_meal = ft_atoli(argv[5]);
			if (arg->nb_meal < 1)
				return (0);
		}
		if (argc == 5)
		{
			if (arg->nb_philo < 1 || arg->tto_die < 1
				|| arg->tto_eat < 1 || arg->tto_sleep < 1)
				return (0);
			arg->nb_meal = -1;
		}
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_arg	arg;

	if (!ft_check_args(&arg, argc, argv))
		return (ft_exit("Invalid Argument"));
	ft_init_mutex(&arg);
	ft_init_philo(&arg);
	ft_init_thread(&arg);
	ft_end_process(&arg);
	ft_free(&arg);
	return (0);
}
