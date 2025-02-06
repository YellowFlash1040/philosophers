/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:22:54 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 16:52:51 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_H
# define MONITOR_H

# include "monitor_data.h"
# include "soul.h"
# include <stdlib.h>

# define MONITOR_INIT_ERR 90

typedef struct monitor
{
	t_monitor_data	*monitor_data;
	t_soul			*soul;
}					t_monitor;

t_monitor			*init_monitor(void);
void				destroy_monitor(t_monitor **monitor);

#endif
