/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_setup.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:44:05 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/01 16:58:32 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_SETUP_H
# define THREADS_SETUP_H

# include "simulation_data.h"

# define THREADS_DATA_LIST_INIT_ERR 23

int	setup_threads(t_simulation_data *data);

#endif