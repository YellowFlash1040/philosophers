/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:36:55 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/28 18:38:32 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMINGS_H
# define TIMINGS_H

# include <stdlib.h>

typedef struct timings
{
	int		time_to_eat;
	int		time_to_sleep;
	int		time_to_die;
}			t_timings;

t_timings	*init_timings(void);

#endif