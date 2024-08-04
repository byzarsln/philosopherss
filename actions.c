/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyza <beyza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:28:59 by beyarsla          #+#    #+#             */
/*   Updated: 2024/08/04 16:11:11 by beyza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	ft_print(philo, "is thinking");
}

void	sleeping(t_philo *philo)
{
	ft_print(philo, "is sleeping");
	ft_usleep(philo->t_data->time_to_sleep);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	ft_print(philo, "has taking a fork");
	pthread_mutex_lock(philo->r_fork);
	ft_print(philo, "has taking a fork");
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->time_of_last_meal = get_current_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	ft_print(philo, "is eating");
	ft_usleep(philo->t_data->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
