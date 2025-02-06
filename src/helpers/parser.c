/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:46:42 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 18:16:30 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	convert_and_fill_numbers(int argsc, char **args, t_params *params);
static int	is_valid_params(t_params *params, int argsc);

int	parse_params(int argsc, char **args, t_params **params_ref)
{
	t_params	*params;
	int			validation_result;

	*params_ref = NULL;
	params = init_params();
	if (!params)
		return (PARAMS_INIT_ERR);
	convert_and_fill_numbers(argsc, args, params);
	validation_result = is_valid_params(params, argsc);
	if (validation_result == SUCCESS)
	{
		*params_ref = params;
		return (SUCCESS);
	}
	free(params);
	return (validation_result);
}

static bool	convert_and_fill_numbers(int argsc, char **args, t_params *params)
{
	int	number;

	if (check_and_atoi(args[1], &number))
		params->number_of_philosophers = number;
	if (check_and_atoi(args[2], &number))
		params->time_to_die = number;
	if (check_and_atoi(args[3], &number))
		params->time_to_eat = number;
	if (check_and_atoi(args[4], &number))
		params->time_to_sleep = number;
	if (argsc == 6 && check_and_atoi(args[5], &number))
		params->number_of_times_each_philosopher_must_eat = number;
	return (true);
}

static int	is_valid_params(t_params *params, int argsc)
{
	if (params->number_of_philosophers < 1)
		return (PHILOSOPHERS_COUNT_ERR);
	if (params->time_to_die < 1)
		return (TIME_TO_DIE_ERR);
	if (params->time_to_eat < 1)
		return (TIME_TO_EAT_ERR);
	if (params->time_to_sleep < 1)
		return (TIME_TO_SLEEP_ERR);
	if (argsc == 6 && params->number_of_times_each_philosopher_must_eat < 1)
		return (OPTIONAL_PARAM_ERR);
	return (SUCCESS);
}
