/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_info.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:02:36 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 18:02:38 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEATH_INFO_H
# define DEATH_INFO_H

# include "time_point.h"
# include <stdlib.h>

# define DEATH_INFO_INIT_ERR 100

typedef struct death_info
{
	int				philo_id;
	t_time_point	timestamp;
}					t_death_info;

t_death_info		*init_death_info(void);
void				destroy_death_info(t_death_info **death_info);

#endif
