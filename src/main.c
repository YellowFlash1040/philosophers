/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:03:31 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/07 16:44:26 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_printer.h"
#include "parser.h"
#include "simulation.h"
#include "simulation_setup.h"

#define WRONG_PARAMS_AMOUNT_ERR 140

// static int	set_params(t_params **params_ref);
static int	philosophers(int argsc, char **args);

int	main(int argsc, char **args)
{
	int	status;

	if (argsc < 5 || argsc > 6)
	{
		print_error(WRONG_PARAMS_AMOUNT_ERR);
		return (WRONG_PARAMS_AMOUNT_ERR);
	}
	status = philosophers(argsc, args);
	if (status != SUCCESS)
		print_error(status);
	return (status);
}

static int	philosophers(int argsc, char **args)
{
	t_params			*params;
	t_simulation_data	*data;
	int					result;

	params = NULL;
	result = parse_params(argsc, args, &params);
	if (result != SUCCESS)
		return (result);
	data = init_simulation_data();
	if (!data)
		return (destroy_params(&params), SIMULATION_DATA_INIT_ERR);
	result = setup_data(data, params);
	destroy_params(&params);
	if (result != 0)
		return (destroy_simulation_data(&data), result);
	start_simulation(data);
	destroy_simulation_data(&data);
	return (SUCCESS);
}

// static int	set_params(t_params **params_ref)
// {
// 	t_params	*params;

// 	if (!params_ref)
// 		return (FAIL);
// 	*params_ref = NULL;
// 	params = init_params();
// 	if (!params)
// 		return (PARAMS_INIT_ERR);
// 	params->number_of_philosophers = 3;
// 	params->time_to_eat = 200;
// 	params->time_to_sleep = 200;
// 	params->time_to_die = 800;
// 	*params_ref = params;
// 	return (SUCCESS);
// }
