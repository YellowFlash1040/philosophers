/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:02:37 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/08 18:13:47 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLOCK_H
# define CLOCK_H

# include "time_point.h"
# include <stdlib.h>
# include <unistd.h>

int	calculate_time_difference(t_time_point start, t_time_point end);
int	time_elapsed_since(t_time_point start, t_time_point *now_ref);
int	precise_usleep(int milliseconds);
int	get_current_time(void);

#endif