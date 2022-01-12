/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:35:44 by aribesni          #+#    #+#             */
/*   Updated: 2022/01/12 15:47:37 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long int	ft_atoli(const char *str)
{
	int			j;
	long int	k;

	j = 1;
	k = 0;
	while (*str == ' ' || *str == '\t'
		|| *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			j = -j;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		k = k * 10 + (*str - 48);
		str++;
	}
	return (j * k);
}
