/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_data.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:21:54 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/28 18:37:31 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_DATA_H
# define SIMULATION_DATA_H

# include "table.h"
# include "timings.h"

typedef struct simulation_data
{
	t_table			*table;
	t_circular_list	*philosophers;
	t_timings		*timings;
}					t_simulation_data;

t_simulation_data	*init_simulation_data(void);

#endif