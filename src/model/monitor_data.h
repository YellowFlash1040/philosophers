/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:22:48 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 15:28:01 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_DATA_H
# define MONITOR_DATA_H

# include "circular_list.h"
# include "environment.h"
# include <stdlib.h>

# define MONITOR_DATA_INIT_ERR 90

typedef struct monitor_data
{
	t_circular_list	*philosophers;
	t_environment	*environment;
}					t_monitor_data;

t_monitor_data		*init_monitor_data(void);
void				destroy_monitor_data(t_monitor_data **monitor_data);

#endif
