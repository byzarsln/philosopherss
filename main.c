/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:29:34 by beyarsla          #+#    #+#             */
/*   Updated: 2024/08/03 17:34:27 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	argv_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (EXIT_FAILURE);
			j++;
		}
		j = 0;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (((argc < 5 || argc > 6) || argv_check(argv)) && printf("%s", ERR_ARG))
		return (EXIT_FAILURE);
	if (ft_atol(argv[1]) > 200)
	{
		printf("%s", ERR_ARG);
		return (EXIT_FAILURE);
	}
	if (init_all(&data, argc, argv) && printf("%s", ERR_INIT))
		return (EXIT_FAILURE);
	philo_start(&data);
	while (1)
		if (data.end == true)
			break ;
	clean_all(&data);
}
