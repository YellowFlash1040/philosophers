/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_setup.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:06:17 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/01 17:04:42 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_SETUP_H
# define SIMULATION_SETUP_H

# include "environment_setup.h"
# include "philosophers_setup.h"
# include "simulation_data.h"
# include "table_setup.h"
# include "threads_setup.h"

int	setup_data(t_simulation_data *data, t_params *params);

#endif