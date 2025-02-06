/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_setup.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:22:43 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 16:53:11 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_SETUP_H
# define MONITOR_SETUP_H

# include "global_status_codes.h"
# include "monitor.h"
# include "simulation_data.h"

# define EMPTY_MONITOR_ERR 80
# define EMPTY_DATA_ERR 81

int	setup_monitor(t_monitor **monitor, t_simulation_data *data);

#endif
