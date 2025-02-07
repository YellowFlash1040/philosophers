/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:31:32 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/07 11:54:45 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "clock.h"
# include "pthread.h"
# include "timings.h"
# include <stdbool.h>

# define ENV_INIT_ERR 60

typedef pthread_mutex_t	t_mutex;

typedef struct environment
{
	t_timings			*timings;
	t_time_point		simulation_start;
	bool				someone_died;
	t_mutex				*write_mutex;
	t_mutex				*death_mutex;
	int					meals_required;
}						t_environment;

t_environment			*init_environment(void);
void					destroy_environment(t_environment **environment);

#endif