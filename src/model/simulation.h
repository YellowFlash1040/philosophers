/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:44:48 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/28 18:42:25 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "actions.h"
# include "philosopher_pair.h"
# include "simulation_data.h"

# define PHILOSOPHERS_INIT_ERR 20

bool	create_philosophers(t_circular_list **list, int amount);
void	destroy_philosophers(t_circular_list **philosophers);
void	start_simulation(t_simulation_data *data);

#endif