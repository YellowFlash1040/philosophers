/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_data.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:21:54 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 15:37:39 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_DATA_H
# define SIMULATION_DATA_H

# include "destructors.h"
# include "monitor.h"
# include "table.h"
# include "timings.h"

# define SIMULATION_DATA_INIT_ERR 3

typedef struct simulation_data
{
	t_table			*table;
	t_circular_list	*philosophers;
	t_environment	*environment;
	t_circular_list	*threads;
	t_monitor		*monitor;
}					t_simulation_data;

t_simulation_data	*init_simulation_data(void);
void				destroy_simulation_data(t_simulation_data **data);

#endif