/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:02:37 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/31 18:35:31 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLOCK_H
# define CLOCK_H

# include <stdlib.h>
# include <sys/time.h>

typedef struct timeval	t_time_point;

double					calculate_time_difference(t_time_point start,
							t_time_point end);
int						get_current_time_stamp(t_time_point simulation_start);

#endif