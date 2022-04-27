/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:12:01 by aribesni          #+#    #+#             */
/*   Updated: 2022/01/12 15:42:21 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				nb_meal;
	int				nb_philo;
	int				philo_id;
	int				stop;
	int				total_meals;
	int				tto_die;
	int				tto_eat;
	int				tto_sleep;
	time_t			life;
	time_t			prev_meal;
	time_t			start;
	pthread_mutex_t	print_status;
	pthread_mutex_t	*l_f;
	pthread_mutex_t	*r_f;
	struct s_arg	*arg;
}					t_philo;

typedef struct s_arg
{
	int				dead;
	int				nb_meal;
	int				nb_philo;
	int				tto_die;
	int				tto_eat;
	int				tto_sleep;
	pthread_t		*th_id;
	pthread_mutex_t	mutex_init;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_arg;

void				ft_end_process(t_arg *arg);
void				ft_free(t_arg *arg);
void				ft_putstr_fd(char *s, int fd);
void				ft_usleep(long int time);
void				*ft_threads(void *args);
void				*ft_is_dead(void *args);
int					ft_count_meals(t_philo *philo);
int					ft_eating(t_philo *philo);
int					ft_exit(char *error);
int					ft_forks(t_philo *philo);
int					ft_init_mutex(t_arg *arg);
int					ft_init_philo(t_arg *arg);
int					ft_init_thread(t_arg *arg);
int					ft_sleeping(t_philo *philo);
int					ft_thinking(t_philo *philo);
long int			ft_atoli(const char *str);
long int			ft_get_time(void);

#endif
