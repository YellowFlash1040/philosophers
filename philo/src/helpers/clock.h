/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:02:37 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/18 17:11:57 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLOCK_H
# define CLOCK_H

# include <stdlib.h>
# include <unistd.h>
# include "time_point.h"

t_uint64	get_time_ms(void);
t_uint64	time_elapsed_since(t_uint64 start_time);
void		precise_sleep(t_uint64 duration_ms);

#endif